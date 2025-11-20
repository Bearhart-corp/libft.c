/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbelard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 13:08:22 by tbelard           #+#    #+#             */
/*   Updated: 2025/10/27 13:08:23 by tbelard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_strlen(char *s)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

size_t	ft_putstr_fd(char *s, t_flags f)
{
	t_nbr	s;
	size_t	count;
	size_t	len;

	count = 0;
	len = ft_strlen(s);
	init(s, f, 0, &s);
	if ((f.point && f.prec) && len > f.prec)
		len = f.prec;
	if (!(s->isleft))
		while (s->pad_width-- > 0)
			count += write(1, " ", 1);
	count += write(1, s, len);
	if (s->isleft)
		while (s->pad_width-- > 0)
			count += write(1, " ", 1);
	return (count);
}


/*1010 / 3 (*,/,-)

sum = 0;
	sum =+ n >> 2 
	n = sum + (n & 3)
void	init(uint64_t bin, t_flags f, int is_nbr, t_nbr *s)*/
