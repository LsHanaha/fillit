/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pututf_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 15:30:34 by jrobin-h          #+#    #+#             */
/*   Updated: 2018/12/04 15:30:34 by jrobin-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_pututf_fd(int c, int fd)
{
	unsigned char	buf[4];
	unsigned char	len;
	unsigned char	i;

	if (c < 0x80)
		len = 1;
	else if (c < 0x800)
		len = 2;
	else if (c < 0x10000)
		len = 3;
	else
		len = 4;
	buf[0] = 0b11110000 << (4 - len);
	i = len;
	while (i > 1)
	{
		buf[i - 1] = 0b10000000 ^ (0b00111111 & c);
		c = c >> 6;
		i--;
	}
	buf[0] = buf[0] ^ ((0b11111111 >> (len + 1)) & c);
	write(fd, buf, len);
}
