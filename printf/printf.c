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

static void appel_du25_juin(size_t *count, va_list lst)
{
	*count += write(1, "0x", 2);
	*count += ft_putnbr((unsigned long)va_arg(lst, void *), 16, 0, 1);
}

static void appel_du26_juin(size_t *count, va_list lst, const char **fmt, int *accuracy)
{
	if ((*fmt)[1] == '.')
		*accuracy = (*fmt)[2] - '0';
	*count += ft_putfloat(va_arg(lst, double), *accuracy);
	((*fmt) += 2);
}

static void	helper(const char **fmt, size_t *count, va_list lst, int accuracy)
{
	if ((*fmt)[1] == 's')
		*count += ft_putstr_fd(va_arg(lst, char *), 1, 0);
	else if ((*fmt)[1] == 'c')
		*count += ft_putchar_fd((char)va_arg(lst, int), 1);
	else if ((*fmt)[1] == 'p')
		appel_du25_juin(count, lst);
	else if ((*fmt)[1] == 'd' || (*fmt)[1] == 'i')
		*count += ft_putnbr((int)va_arg(lst, int), 10, 0, 0);
	else if ((*fmt)[1] == 'u')
		*count += ft_putnbr((unsigned int)va_arg(lst, unsigned int), 10, 0, 0);
	else if ((*fmt)[1] == 'x')
		*count += ft_putnbr(va_arg(lst, int), 16, 0, 0);
	else if ((*fmt)[1] == 'X')
		*count += ft_putnbr(va_arg(lst, int), 16, 1, 0);
	else if ((*fmt)[1] == '.' || (*fmt)[1] == 'f')
		appel_du26_juin(count, lst, fmt, &accuracy);
	else if ((*fmt)[1] == '%')
		*count += ft_putchar_fd('%', 1);
	(*fmt) += 1;
}

// n,base, upper, adress flag
int	ft_printf(const char (*fmt), ...)
{
	va_list	lst;
	size_t	count;
	int		accuracy;

	count = 0;
	accuracy = 6;
	va_start(lst, fmt);
	while (*fmt)
	{
		if ((*fmt) == '%' && fmt[1])
			helper(&fmt, &count, lst, accuracy);
		else
			count += ft_putchar_fd((*fmt), 1);
		fmt++;
	}
	va_end(lst);
	return (count);
}


int main()
{
	char s[] = "hi";
	int count = ft_printf("%s,%u, %.3f, %d", "Tomtom", -1, -17.123, -42);
	ft_printf("\n%d", count);
}