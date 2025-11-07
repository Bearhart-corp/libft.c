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

size_t	ft_putnbr_fd(long n, int fd, int unsign)
{
	char	tmp;
	size_t	count;

	count = 0;
	if (!unsign && n < 0)
		count += write(fd, "-", 1);
	else if (unsign)
		n = (unsigned long)n;
	if (n >= 10)
		count += ft_putnbr_fd(n / 10, fd, unsign);
	tmp = (n % 10) + '0';
	count += write(fd, &tmp, 1);
	return (count);
}

/*
int main()
{
	size_t count = 0;
	size_t n = ft_putnbr_fd(123, 1, 1, &count);
	printf("%d\n",n );
}*/