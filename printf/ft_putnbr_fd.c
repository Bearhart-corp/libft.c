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

static size_t	long_len(long n, int base)
{
	size_t	len;

	len = 0;
	while (n > 0)
	{
		n /= base;
		len++;
	}
	return (len);
}

static int helper(t_flags flags_struct, int *upper, long *n, size_t *count)
{
	int	base;

	if (flags_struct.conversion == HEX_LOW ||
		flags_struct.conversion == HEX_MAJ ||
		flags_struct.conversion == PTR)
			base = 16;
	else
		base = 10;
	if (*n < 0)
		{
			*count += write(1, "-", 1);
			*n = -(*n);
		}
	if (flags_struct.conversion == HEX_MAJ)
		*upper = 1;
	else
		*upper = 0;
	return (base);
}

static size_t	ft_putnbr_help(long n, t_flags flags_struct, int base, int up)
{
	char	tmp;
	size_t	count;

	count = 0;
	if (n >= base)
		count += ft_putnbr_help(n / base, flags_struct, base, up);
	tmp = "0123456789abcdef"[n % base];
	if (up)
		tmp = ft_toupper(tmp);
	count += write(1, &tmp, 1);
	return (count);
}

size_t	ft_putnbr(long n, t_flags flags_struct)
{
	unsigned long	tmp;
	size_t			count;
	int				base;
	int				upper;
	char			temp;

	upper = 0;
	count = 0;
	tmp = (unsigned long)n;
	if (flags_struct.flags == SPACE)
		temp = ' ';
	else if (flags_struct.flags == ZEROS)
		temp = '0';
	if (flags_struct.conversion == PTR && !n)
		return count += write(1, "(nil)", 5);
	if ((flags_struct.flags & PLUS) && n >= 0)
		count += write(1, "+", 1);
	if (flags_struct.flags == SPACE && !(flags_struct.flags & PLUS) && n >= 0)
		count += write(1, " ", 1);
	base = helper(flags_struct, &upper, &n, &count);
	if (flags_struct.width)
		flags_struct.width -= long_len(n, base) - count;
	if (n < 0 && (!(tmp & (tmp - 1))))
	{
		if (!(flags_struct.flags & START_LEFT))
			while (flags_struct.width--)
				count += write(1, &temp, 1);
		if (base == 16)
			count += write(1, "8000000000000000", 16);
		else
			count += write(1, "9223372036854776000", 19);
		if ((flags_struct.flags & START_LEFT))
			while (flags_struct.width--)
				count += write(1, " ", 1);
	}
	else
	{
		if (!(flags_struct.flags & START_LEFT) && flags_struct.width)
			while (flags_struct.width--)
				count += write(1, &temp, 1);
		count += ft_putnbr_help(n, flags_struct, base, upper);
		if ((flags_struct.flags & START_LEFT) && flags_struct.width)
			while (flags_struct.width--)
				count += write(1, &temp, 1);
	}
	return (count);
}
/*
int main()
{
	size_t n = ft_putnbr(42, 1, 16, 1);
	printf("\ntaille :%zu\n",n );
}*/