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
#include <stdio.h>
////////////// u, p, x, X
size_t	h(unsigned long n, int base, char *buf, t_flags f)
{
	size_t	count;
	size_t		i;
	char	tmp[64];

	i = -1;
	count = 0;
	if (n == 0)
	{
		buf[count++] = '0';
		if (f.point && f.prec == 0)
			buf[--count] = 0;
		return (count);
	}
	while (n > 0)
	{
		tmp[count++] = "0123456789abcdef"[n % base];
		n = n / base;
	}
	if (f.conversion == PTR || f.flags & HASH)
	{
		tmp[count++] = 'x';
		tmp[count++] = '0';
	}
	while (++i < count)
		buf[i] = tmp[(count - 1) - i];
	return (count);
}

size_t	ptr_zero(t_flags f)
{
	int 	pad;
	size_t	L;
	char	*nil;
	size_t	count;

	count = 0;
	{
		nil = "(nil)";
		L = 5;
		count = 0;
		if (f.width > L)
			pad = f.width - L;
		else
			pad = 0;
		if (!(f.flags & START_LEFT))
			while (pad--)
				count += write(1, " ", 1);
		count += write(1, nil, L);
		if (f.flags & START_LEFT)
			while (pad--)
				count += write(1, " ", 1);
		return (count);
	}
}

//////////////// i, d

size_t	ft_putnbr_help(long n, char *buf, t_flags f)
{
	size_t	count;
	size_t		i;
	char	tmp[64];

	i = 0;
	count = 0;
	if (n == 0)
	{
		buf[count++] = '0';
		if (f.point && f.prec == 0)
			buf[--count] = 0;
		return (count);
	}
	while (n > 0)
	{
		tmp[count++] = "0123456789"[n % 10];
		n = n /10;
	}
	while (i < count)
	{
		buf[i] = tmp[(count - 1) - i];
		i++;
	}
	return (count);
}
