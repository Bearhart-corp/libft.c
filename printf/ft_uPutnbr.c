/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uPutnbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbelard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 14:52:54 by tbelard           #+#    #+#             */
/*   Updated: 2025/11/14 14:52:56 by tbelard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
static size_t	h(unsigned long n, unsigned int base, char *buf, t_flags f)
{
	size_t	count;
	size_t		i;
	char	tmp[64];

	i = -1;
	count = 0;
	if (n == 0)
	{
		buf[count++] = '0';
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

static size_t ptr_zero(t_flags f)
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

size_t	Uputnbr(unsigned long n, t_flags f)
{
	size_t	count;
	int		base;
	int		upper;
	char	sign;
	size_t	sign_len;
	char	buf[64];
	char	symb_pad;
	size_t	pad;

	sign = 0;
	symb_pad = ' ';
	upper = (f.conversion == HEX_MAJ);
	count = 0;
	sign_len = 1;

	if (f.conversion == UNSIGNED)
		base = 10;
	else
		base = 16;
	if (f.conversion == PTR && n == 0)
		return (count+= ptr_zero(f));	

	count += h(n, base, buf, f);

	if (!(f.flags & START_LEFT) && (f.flags & ZEROS) && (f.width - count))
		symb_pad = '0';
	else if (f.flags & PLUS)
		sign = '+';
	else if (f.flags & SPACE)
		sign = ' ';
	else
		sign_len = 0;

	pad = f.width - (count + sign_len);
	if (pad & 0x8000000000000000)
		pad = 0;
	f.width = pad;

	if (upper)
		ft_toupper_str(buf);
	if ((f.flags & START_LEFT))
	{
		if (sign_len)
			write(1, &sign, 1);
		write(1, buf, count);
	}
	while (f.width-- && !(f.width & 0x8000000000000000))
		count += write(1, &symb_pad, 1);
	if (!(f.flags & START_LEFT))
	{
		if (sign_len)
			write(1, &sign, 1);
		write(1, buf, count - pad);
	}
	return (count + sign_len);
}
//"%05X", -1