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


#include "printf.h"

size_t	ft_putfloat(double n, size_t accuracy)
{
	long	n_int;
	size_t	count;
	char	c;

	count = 0;
	if (n < 0)
	{
		n = -n;
		count += write(1, "-", 1);
	}
	n += 0.0000005;
	n_int = (long)n;
	count += ft_putnbr_fd(n_int, 1, 0);
	count += write(1, ".", 1);
	n = (n - n_int) * accuracy;
	count += ft_putnbr_fd(n, 1, 0);
	return (count);
}
// accuracy : if precision .2f alors 100 pour .6f  alors 1000000