/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rbtinsertbyid.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 12:38:00 by jrobin-h          #+#    #+#             */
/*   Updated: 2018/12/19 12:38:02 by jrobin-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		simple_btree_insert_by_id(t_rbt *root, t_rbt *new)
{
	if (!root || !new)
		return ;
	if (new->id < root->id)
		if (root->left)
			simple_btree_insert_by_id(root->left, new);
		else
		{
			root->left = new;
			new->parent = root;
		}
	else if (new->id > root->id)
		if (root->right)
			simple_btree_insert_by_id(root->right, new);
		else
		{
			root->right = new;
			new->parent = root;
		}
	else
		ft_rbtupdatenode(root, new);
}

static int		get_uncle_colour(t_rbt *root, t_rbt **uncle)
{
	t_rbt *parent;

	parent = root->parent;
	if (parent->parent->left == parent)
		*uncle = parent->parent->right;
	else
		*uncle = parent->parent->left;
	return ((*uncle) ? (*uncle)->colour : BLACK);
}

static void		black_uncle(t_rbt *x, t_rbt *p, t_rbt *g)
{
	if (p == g->left && x == p->left)
	{
		ft_rbtrotate(g, 'r');
		ft_rbtswapcolours(g, p);
	}
	else if (p == g->left && x == p->right)
	{
		ft_rbtrotate(p, 'l');
		ft_rbtrotate(g, 'r');
		ft_rbtswapcolours(x, g);
	}
	else if (p == g->right && x == p->right)
	{
		ft_rbtrotate(g, 'l');
		ft_rbtswapcolours(g, p);
	}
	else
	{
		ft_rbtrotate(p, 'r');
		ft_rbtrotate(g, 'l');
		ft_rbtswapcolours(x, g);
	}
}

static void		red_uncle(t_rbt **current, t_rbt *uncle)
{
	(*current)->parent->colour = BLACK;
	uncle->colour = BLACK;
	(*current)->parent->parent->colour = RED;
	*current = (*current)->parent->parent;
}

void			ft_rbtinsertbyid(t_rbt **root_node, t_rbt *new)
{
	t_rbt	*uncle;

	if (!root_node || !new)
		return ;
	if (!(*root_node))
	{
		*root_node = new;
		return ;
	}
	new->colour = RED;
	simple_btree_insert_by_id(*root_node, new);
	if (ft_rbtisvalid(*root_node))
		return ;
	while (new->parent && new->parent->colour == RED)
	{
		if (get_uncle_colour(new, &uncle) == RED)
			red_uncle(&new, uncle);
		else
		{
			black_uncle(new, new->parent, new->parent->parent);
			break ;
		}
	}
	*root_node = ft_rbtgetroot(new);
	(*root_node)->colour = BLACK;
}
