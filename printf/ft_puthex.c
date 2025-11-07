/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbelard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 17:52:59 by tbelard           #+#    #+#             */
/*   Updated: 2025/11/07 17:53:01 by tbelard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "printf.h"

size_t	ft_putnbr(long n)
{
	char	tmp;
	size_t	count;
	long	nb;
	char	buf[100];

	nb = n;
	count = 0;
	if (n < 0)
		count += write(fd, "-", 1);
	while (n >= 10)
	{
		tmp = (n % 10) + '0';
		n /= 10;
	}		
	count += write(fd, &tmp, 1);
	return (count);
}
