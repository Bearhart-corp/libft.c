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

#include "ft_printf.h"
#include <stdio.h>

static size_t print_fmt(va_list lst, t_flags *flags_struct)
{
	size_t	count;
	long	tmp;

	count = 0;
	if ((*flags_struct).conversion == 1)
		count += ft_putstr_fd(va_arg(lst, char *), *flags_struct);
	else if ((*flags_struct).conversion == 2)
		count += ft_putchar_fd((char)va_arg(lst, int), *flags_struct);
	else if ((*flags_struct).conversion == 4)
		count += ft_putnbr(va_arg(lst, int), *flags_struct);
	else if ((*flags_struct).conversion > 2 && (*flags_struct).conversion < 8)
	{
		tmp = (unsigned long)va_arg(lst, void *);
		if ((*flags_struct).conversion == 3 || (*flags_struct).flags == HASH)
			if (tmp)
				count += write(1, "0x", 2);
		count += ft_putnbr(tmp, *flags_struct);
	}
	else
		count += ft_putfloat(va_arg(lst, double), *flags_struct);
	return (count);
}

static size_t	conv(const char **fmt, va_list lst, t_flags *flags_struct)
{
	size_t	count;

	count = 0;
	if ((**fmt) == 's')
		(*flags_struct).conversion = 1;
	else if ((**fmt) == 'c')
		(*flags_struct).conversion = 2;
	else if ((**fmt) == 'p')
		(*flags_struct).conversion = 3;
	else if ((**fmt) == 'd' || (**fmt) == 'i')
		(*flags_struct).conversion = 4;
	else if ((**fmt) == 'u')
		(*flags_struct).conversion = 5;
	else if ((**fmt) == 'x')
		(*flags_struct).conversion = 6;
	else if ((**fmt) == 'X')
		(*flags_struct).conversion = 7;
	else if ((**fmt) == 'f' && *fmt++)
		(*flags_struct).conversion = 8;
	else if ((**fmt) == '%')
		return count += ft_putchar_fd('%', *flags_struct);
	count += print_fmt(lst, flags_struct);
	return (count);
}

static size_t	accuracyF(const char **fmt, va_list lst, t_flags *flags_struct)
{
	size_t	count;

	count = 0;
	if ((**fmt) == '.')
		(*fmt)++;
	else
		return (count += conv(fmt, lst, flags_struct));
	while (**fmt >= 48 && **fmt <= 57)
	{
		(*flags_struct).prec = (*flags_struct).prec * 10 + (**fmt - 48);
		(*fmt)++;
	}
	if ((*flags_struct).prec == 0)
		(*flags_struct).prec = 6;
	count += conv(fmt, lst, flags_struct);
	return (count);
}

static size_t	flag_pars(const char **fmt, va_list lst, t_flags *flags_struct)
{
	size_t	count;

	count = 0;
	while (**fmt == '-' || **fmt == '+' || **fmt == ' ' || **fmt == '#' 
		|| **fmt == '0')
	{
		if ((**fmt) == '-')
			(*flags_struct).flags |= START_LEFT;
		else if ((**fmt) == '0' && ((*flags_struct).flags & START_LEFT )!= 1)
			(*flags_struct).flags |= ZEROS;
		else if ((**fmt) == '#')
			(*flags_struct).flags |= HASH;
		else if ((**fmt) == '+')
			(*flags_struct).flags |= PLUS;
		else if ((**fmt) == ' ')
			(*flags_struct).flags |= SPACE;
		(*fmt)++;
	}
	while (**fmt >= 48 && **fmt <= 57)
			{
				(*flags_struct).width = (*flags_struct).width * 10 + (**fmt - 48);
				(*fmt)++;
			}
	return count += accuracyF(fmt, lst, flags_struct);
}

// n,base, upper, adress flag
int	ft_printf(const char (*fmt), ...)
{
	va_list	lst;
	size_t	count;
	t_flags	flags_struct;

	count = 0;
	
	va_start(lst, fmt);
	while (*fmt)
	{
		flags_struct.flags = 0;
		flags_struct.width = 0;
		flags_struct.prec = 0;
		flags_struct.conversion = 0;
		if ((*fmt) == '%' && ++fmt)
			count += flag_pars(&fmt, lst, &flags_struct);
		else
			count += ft_putchar_fd((*fmt), flags_struct);
		fmt++;
	}
	va_end(lst);
	return (count);
}


int main()
{
	ft_printf(" %p %p ", (void *)LONG_MIN, (void *)LONG_MAX);
	   int n = printf(" %p %p ", (void *)LONG_MIN, (void *)LONG_MAX);
	   printf("%d\n",n );
}