/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbelard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 14:05:40 by tbelard           #+#    #+#             */
/*   Updated: 2025/11/07 14:05:42 by tbelard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>

//static int helper(const char *fmt, )

int	ft_printf(const char *fmt, ...)
{
	va_list lst;
	size_t	count;
	size_t	j;

	count = 0;
	va_start(lst, fmt);
	while (*fmt)
	{
		j = 0;
		while (fmt[j] != '%' && fmt[j])
			j++;
		if (j)
			count += ft_putstr_fd((char *)fmt, 1, j);
		fmt += j;
		if (*fmt == '%')
		{
			if (fmt[1] == 's')
			count += ft_putstr_fd(va_arg(lst, char *), 1, 0);
		else if (fmt[1] == 'c')
			count += ft_putchar_fd((char)va_arg(lst, int), 1);
		else if (fmt[1] == 'p')
			count += ft_putnbr_fd((unsigned long)va_arg(lst, void *), 1, 1);
		else if (fmt[1] == 'd')
			count += ft_putnbr_fd(va_arg(lst, int), 1, 0);
		else if (fmt[1]  == 'i')
			count += ft_putnbr_fd(va_arg(lst, int), 1, 0);
		else if (fmt[1]  == 'u')
			count += ft_putnbr_fd(va_arg(lst, unsigned int), 1, 1);
		else if (fmt[1]  == 'x')
			count += ft_putnbr_fd(va_arg(lst, int), 1, 1);
		else if (fmt[1] == 'X')
			count += ft_putnbr_fd(va_arg(lst, int), 1, 1);
		else if (fmt[1] == '%')
			count += ft_putchar_fd('%', 1);
		fmt += 2;
		}
	}
	va_end(lst);
	return (count);
}

int main()
{
	int count = ft_printf("%u ans\n et %c", -1, 'f');
	printf("%.17f", -42.12);
}