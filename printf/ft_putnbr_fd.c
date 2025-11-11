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

#include "printf.h"

static int helper(size_t *count, t_flags flags_struct, int *upper)
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
	if (flags_struct.flags != 4 && flags_struct.flags != 5)
		*count += write(1, "0x", 2);
	return (base);
}

size_t	ft_putnbr(long n, t_flags flags_struct)
{
	char	tmp;
	size_t	count;
	int		base;
	int		upper;

	count = 0;
	base = helper(&count, flags_struct, &upper);
	if (n < 0)
	{
		count += write(1, "-", 1);
		n = -n;
	}
	if (n >= base)
		count += ft_putnbr(n / base, flags_struct);
	tmp = "0123456789abcdef"[n % base];
	if (upper)
		tmp = ft_toupper(tmp);
	count += write(1, &tmp, 1);
	return (count);
}

/*
int main()
{
	size_t n = ft_putnbr(42, 1, 16, 1);
	printf("\ntaille :%zu\n",n );
}*/