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

	count = 0;
	if ((*flags_struct).conversion == STRING)
		count += ft_putstr_fd(va_arg(lst, char *), *flags_struct);
	else if ((*flags_struct).conversion == LETTER)
		count += ft_putchar_fd((char)va_arg(lst, int), *flags_struct);
	else if ((*flags_struct).conversion == INTEGER)
		count += ft_putnbr((long)va_arg(lst, int), *flags_struct);
	else if ((*flags_struct).conversion >= PTR 
		&& (*flags_struct).conversion <= HEX_MAJ)
	{
		if ((*flags_struct).flags == HASH)
		{
			if((*flags_struct).conversion == HEX_MAJ)
				count += write(1, "0X", 2);
			else
				count += write(1, "0x", 2);
		}
		if ((*flags_struct).conversion == PTR)
			count += ft_putnbr((long)va_arg(lst, void *), *flags_struct);
		else
			count += ft_putnbr(va_arg(lst, long), *flags_struct);
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
		(*flags_struct).conversion = STRING;
	else if ((**fmt) == 'c')
		(*flags_struct).conversion = LETTER;
	else if ((**fmt) == 'd' || (**fmt) == 'i')
		(*flags_struct).conversion = INTEGER;
	else if ((**fmt) == 'p')
		(*flags_struct).conversion = PTR;
	else if ((**fmt) == 'u')
		(*flags_struct).conversion = UNSIGNED;
	else if ((**fmt) == 'x')
		(*flags_struct).conversion = HEX_LOW;
	else if ((**fmt) == 'X')
		(*flags_struct).conversion = HEX_MAJ;
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
int	ft_printf(const char *fmt, ...)
{
	va_list	lst;
	size_t	count;
	t_flags	flags_struct;

	count = 0;
	if (!fmt)
		return (-1);
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
/*
int main()
{
	int n1 = ft_printf("%0014.2X%020X%0002.X%000.5X\n", -1, 3, 30, -1);
	int n2 =    printf("%0014.2X%020X%0002.X%000.5X\n", -1, 3, 30, -1);
	   printf("n:%d\n",n1 );
	    printf("n2:%d\n",n2 );
}*/