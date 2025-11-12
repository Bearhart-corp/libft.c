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
static int helper(t_flags flags_struct, int *upper)
{
	int	base;

	if (flags_struct.conversion == 6 ||
		flags_struct.conversion == 7 ||
		flags_struct.conversion == 3)
			base = 16;
	else
		base = 10;
	if (flags_struct.conversion == 5)
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
	if (n < 0)
	{
		count += write(1, "-", 1);
		n = -n;
	}
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

	upper = 0;
	count = 0;
	tmp = (unsigned long)n;
	base = helper(flags_struct, &upper);
	if (n < 0 && (!(tmp & (tmp - 1))))
	{
		if (base == 16)
			count += write(1, "8000000000000000", 16);
		else
			count += write(1, "9223372036854776000", 19);
	}
	else
		ft_putnbr_help(n, flags_struct, base, upper);
	return (count);
}
/*
int main()
{
	size_t n = ft_putnbr(42, 1, 16, 1);
	printf("\ntaille :%zu\n",n );
}*/