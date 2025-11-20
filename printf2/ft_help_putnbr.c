/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_help_putnbr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbelard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 10:48:34 by tbelard           #+#    #+#             */
/*   Updated: 2025/11/16 10:48:38 by tbelard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
////////////// u, p, x, X

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

static size_t	hh(unsigned long n, t_flags f, t_nbr *s)
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

size_t	h(unsigned long n, t_flags f, t_nbr *s)
{
	size_t	count;

	count = 0;
	if (n == 0)
	{
		s->buf[count++] = '0';
		if (f.point && f.prec == 0)
			s->buf[--count] = 0;
		return (count);
	}
	return (hh(n, f, s));
}

size_t	ptr_zero(t_flags f)
{
	int		pad;
	char	*nil;
	size_t	count;

	count = 0;
	{
		nil = "(nil)";
		count = 0;
		if (f.width > 5)
			pad = f.width - 5;
		else
			pad = 0;
		if (!(f.flags & START_LEFT))
			while (pad--)
				count += write(1, " ", 1);
		count += write(1, nil, 5);
		if (f.flags & START_LEFT)
			while (pad--)
				count += write(1, " ", 1);
		return (count);
	}
}

//////////////// i, d

size_t	ft_putnbr_help(long n, t_flags f, t_nbr *s)
{
	size_t	count;
	size_t	i;
	char	tmp[64];

	i = -1;
	count = 0;
	if (n == 0)
	{
		s->buf[count++] = '0';
		if (f.point && f.prec == 0)
			s->buf[--count] = 0;
		return (count);
	}
	while (n > 0)
	{
		tmp[count++] = "0123456789"[n % 10];
		n = n / 10;
	}
	while (++i < count)
		s->buf[i] = tmp[(count - 1) - i];
	return (count);
}
