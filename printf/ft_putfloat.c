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
	int	power;

	power = (int)pow;
	acc = 1;
	while (power--)
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
	return (count += ft_putnbr(n, f), n = (n - n_int) * power(f.prec));
}
