/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbelard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 13:08:56 by tbelard           #+#    #+#             */
/*   Updated: 2025/10/27 13:08:58 by tbelard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"



static size_t	h(long long n, t_flags f, t_nbr *s)
{
	size_t	count;
	size_t	i;
	char	tmp[64];

	i = -1;
	count = 0;
	while (n > 0)
	{
		tmp[count++] = "0123456789abcdef"[n % s->base];
		n = n / s->base;
	}
	if (f.conv == PTR || f.flags & HASH)
	{
		tmp[count++] = 'x';
		tmp[count++] = '0';
	}
	while (++i < count)
		s->buf[i] = tmp[(count - 1) - i];
	return (count);
}

size_t	ft_putnbr(long n, t_flags f)
{
	t_nbr	s;
	
	init(n, f, 1, &s);
	return (h())
}