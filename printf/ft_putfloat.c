/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putfloat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbelard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 17:53:22 by tbelard           #+#    #+#             */
/*   Updated: 2025/11/07 17:53:24 by tbelard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	power(char pow)
{
	int	acc;
	int power;

	power = (int)pow;
	acc = 1;
	while (pow--)
		acc = acc * 10;
	return (acc);
}

size_t	ft_putfloat(double n, t_flags f)
{
	long	n_int;
	size_t	count;

	count = 0;
	if (n < 0)
	{
		n = -n;
		count += write(1, "-", 1);
	}
	n += (0.5 / power(f.prec));
	n_int = (long)n;
	count += ft_putnbr(n_int, f);
	count += write(1, ".", 1);
	n = (n - n_int) * power(f.prec);
	count += ft_putnbr(n, f);
	return (count);
}
/*
int main()
{
	ft_putfloat(42.123, 6);
}*/
// accuracy : if precision .2f alors 100 pour .6f  alors 1000000
//ft_putnbr(long n, int unsign, unsigned short int base, int upper)