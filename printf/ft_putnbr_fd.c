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

size_t	ft_putnbr(long n, unsigned short int base, int upper, int flag)
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
		count += ft_putnbr(n / base, base, upper, flag);
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