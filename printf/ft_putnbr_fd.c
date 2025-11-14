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
#include <stdio.h>

static size_t	ft_putnbr_help(long n, char *buf)
{
	size_t	count;
	size_t		i;
	char	tmp[64];

	i = 0;
	count = 0;
	if (n == 0)
	{
		buf[count++] = '0';
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

size_t	ft_putnbr(long n, t_flags f)
{
	size_t	count;
	char	sign;
	size_t	sign_len;
	char	buf[64];
	char	symb_pad;
	size_t	pad;

	count = 0;
	sign = 0;
	sign_len = 1;
	symb_pad = ' ';
	if (n < 0)
	{
		sign = '-';
		n = -n;
		sign_len = 1;
	}
	count += ft_putnbr_help(n, buf);
	
	if (!(f.flags & START_LEFT) && (f.flags & ZEROS) && (f.width - count) && sign != '-')
		symb_pad = '0';
	else if (f.flags & PLUS && sign != '-')
		sign = '+';
	else if (f.flags & SPACE && sign != '-')
		sign = ' ';
	else if (sign != '-')
		sign_len = 0;
	pad = f.width - (count + sign_len);
	if (pad & 0x8000000000000000)
		pad = 0;
	f.width = pad;
	if (f.flags & START_LEFT)
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
//"%10d", (int)-2147483648