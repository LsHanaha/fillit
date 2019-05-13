/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 15:51:11 by jrobin-h          #+#    #+#             */
/*   Updated: 2018/12/19 16:23:32 by jrobin-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

enum			e_rbtclr
{
	RED,
	BLACK
};

typedef struct	s_rbtree
{
	int					id;
	void				*content;
	size_t				content_size;
	enum e_rbtclr		colour;
	struct s_rbtree		*parent;
	struct s_rbtree		*left;
	struct s_rbtree		*right;
}				t_rbt;

/*
**	LINKED LISTS
*/

void			ft_lstadd(t_list **alst, t_list *new);
t_list			*ft_lstappend(t_list *alst, t_list *new);
void			ft_lstdel(t_list **alst, void (*del)(void **, size_t *));
void			ft_lstdelone(t_list **alst, void (*del)(void **, size_t *));
t_list			*ft_lstfromchr(char const *content, size_t len);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
size_t			ft_lstlen(t_list *lst);
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list			*ft_lstnew(void const *content, size_t size);
char			*ft_lsttostr(t_list *lst, char sep);
char			**ft_lsttotab(t_list *lst);

/*
**	MEMORY OPERATIONS
*/

void			ft_bzero(void *s, size_t n);
void			ft_delcontent(void **content, size_t *size);
void			*ft_memalloc(size_t size);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
void			ft_memdel(void **ap);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memset(void *b, int c, size_t len);

/*
**	OUTPUT FUNCTIONS
*/

void			ft_putchar(char c);
void			ft_putchar_fd(char c, int fd);
void			ft_putendl(char const *s);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putlst(t_list *lst);
void			ft_putnbr(int n);
void			ft_putnbr_fd(int n, int fd);
void			ft_putstr(char const *s);
void			ft_putstr_fd(char const *s, int fd);
void			ft_puttab(const char **tab);
void			ft_pututf_fd(int c, int fd);

/*
**	RED BLACK TREES
*/

enum e_rbtclr	ft_rbtcolour(t_rbt *node);
void			ft_rbtdel(t_rbt **root, void (*del)(void **, size_t *));
void			ft_rbtdelone(t_rbt *node, void (*del)(void **, size_t *));
t_rbt			*ft_rbtfindbyid(t_rbt *root, int id);
t_rbt			*ft_rbtfromchr(int id, char const *content, size_t len);
unsigned int	ft_rbtgetbheight(t_rbt *root);
t_rbt			*ft_rbtgetroot(t_rbt *node);
t_rbt			*ft_rbtgetsibling(t_rbt *node);
void			ft_rbtinsertbyid(t_rbt **root_node, t_rbt *new);
int				ft_rbtisleft(t_rbt *node);
int				ft_rbtisvalid(t_rbt *root);
t_rbt			*ft_rbtmin(t_rbt *root);
t_rbt			*ft_rbtnew(int id, void const *content, size_t size);
void			ft_rbtrm(t_rbt **root, t_rbt *to_delete,
		void (*del)(void **, size_t *));
void			ft_rbtrmbyid(t_rbt **root, int id,
		void (*del)(void **, size_t *));
t_rbt			*ft_rbtrotate(t_rbt *root, char dir);
void			ft_rbtswapcolours(t_rbt *a, t_rbt *b);
void			ft_rbtupdatecontent(t_rbt *node, void *content, size_t size);
void			ft_rbtupdatenode(t_rbt *old, t_rbt *new);
void			ft_rbtupdatestr(t_rbt *node, char *s, size_t len);

/*
**	STRING OPERATIONS
*/

char			*ft_itoa(int n);
char			*ft_stpcpy(char *dst, const char *src);
char			*ft_strcat(char *dest, const char *src);
char			*ft_strchr(const char *s, int c);
void			ft_strclr(char *s);
int				ft_strcmp(const char *s1, const char *s2);
char			*ft_strcpy(char *dest, const char *src);
void			ft_strdel(char **s);
char			*ft_strdup(const char *s);
int				ft_strequ(char const *s1, char const *s2);
long			ft_strfind(const char *s, int c);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strjoin(char const *s1, char const *s2);
size_t			ft_strlcat(char *dest, const char *src, size_t size);
size_t			ft_strlen(const char *s);
t_list			*ft_strlsplit(char const *s, char c);
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			*ft_strncat(char *dest, const char *src, size_t n);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strncpy(char *dest, const char *src, size_t n);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strnew(size_t size);
char			*ft_strnstr(const char *hs, const char *needle, size_t len);
char			*ft_strrchr(const char *s, int c);
char			**ft_strsplit(char const *s, char c);
char			*ft_strstr(const char *haystack, const char *needle);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strtrim(char const *s);

/*
**	MISCELLANEOUS
*/

int				ft_atoi(const char *str);
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_islower(int c);
int				ft_isprint(int c);
int				ft_isspace(int c);
int				ft_isupper(int c);
int				ft_gnl(const int fd, char **line);
void			ft_tabdel(char **tab);
int				ft_tolower(int c);
int				ft_toupper(int c);

#endif
