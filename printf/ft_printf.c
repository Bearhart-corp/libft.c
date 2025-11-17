/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbelard <tbelard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 14:05:40 by tbelard           #+#    #+#             */
/*   Updated: 2025/11/14 14:44:42 by tbelard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static size_t	print_fmt(va_list lst, t_flags *f_struct)
{
	size_t	count;

	count = 0;
	if ((*f_struct).conv == STRING)
		count += ft_putstr_fd(va_arg(lst, char *), *f_struct);
	else if ((*f_struct).conv == LETTER)
		count += ft_putchar_fd((char)va_arg(lst, int), *f_struct);
	else if ((*f_struct).conv == INTEGER)
		count += ft_putnbr((long)va_arg(lst, int), *f_struct);
	else if ((*f_struct).conv >= PTR
		&& (*f_struct).conv <= HEX_MAJ)
		count += u_putnbr((unsigned long)va_arg(lst, void *), *f_struct);
	else
		count += ft_putfloat(va_arg(lst, double), *f_struct);
	return (count);
}

static size_t	conv(const char **fmt, va_list lst, t_flags *f_struct)
{
	size_t	count;

	count = 0;
	if ((**fmt) == 's')
		(*f_struct).conv = STRING;
	else if ((**fmt) == 'c')
		(*f_struct).conv = LETTER;
	else if ((**fmt) == 'd' || (**fmt) == 'i')
		(*f_struct).conv = INTEGER;
	else if ((**fmt) == 'p')
		(*f_struct).conv = PTR;
	else if ((**fmt) == 'u')
		(*f_struct).conv = UNSIGNED;
	else if ((**fmt) == 'x')
		(*f_struct).conv = HEX_LOW;
	else if ((**fmt) == 'X')
		(*f_struct).conv = HEX_MAJ;
	else if ((**fmt) == 'f')
		(*f_struct).conv = 8;
	else if ((**fmt) == '%')
		return (count += ft_putchar_fd('%', *f_struct));
	count += print_fmt(lst, f_struct);
	return (count);
}

static size_t	accuracy_f(const char **fmt, va_list lst, t_flags *f_struct)
{
	size_t	count;

	count = 0;
	if ((**fmt) == '.')
	{
		(*f_struct).point = 1;
		(*fmt)++;
	}
	else
		return (count += conv(fmt, lst, f_struct));
	while (**fmt >= 48 && **fmt <= 57)
	{
		(*f_struct).prec = (*f_struct).prec * 10 + (**fmt - 48);
		(*fmt)++;
	}
	if ((*f_struct).prec == 0)
		if (**fmt == 'f')
			(*f_struct).prec = 6;
	count += conv(fmt, lst, f_struct);
	return (count);
}

static size_t	flag_pars(const char **fmt, va_list lst, t_flags *f_struct)
{
	size_t	count;

	count = 0;
	init(f_struct);
	while (**fmt == '-' || **fmt == '+' || **fmt == ' ' || **fmt == '#'
		|| **fmt == '0')
	{
		if ((**fmt) == '-')
			(*f_struct).flags |= START_LEFT;
		else if ((**fmt) == '0' && (!((*f_struct).flags & START_LEFT)))
			(*f_struct).flags |= ZEROS;
		else if ((**fmt) == '#')
			(*f_struct).flags |= HASH;
		else if ((**fmt) == '+')
			(*f_struct).flags |= PLUS;
		else if ((**fmt) == ' ')
			(*f_struct).flags |= SPACE;
		(*fmt)++;
	}
	while (**fmt >= 48 && **fmt <= 57)
	{
		(*f_struct).width = (*f_struct).width * 10 + (**fmt - 48);
		(*fmt)++;
	}
	return (count += accuracy_f(fmt, lst, f_struct));
}

int	ft_printf(const char *fmt, ...)
{
	va_list	lst;
	size_t	count;
	t_flags	f_struct;

	count = 0;
	if (!fmt || write(1, "", 0) == -1)
		return (-1);
	va_start(lst, fmt);
	while (*fmt)
	{
		if ((*fmt) == '%' && ++fmt)
			count += flag_pars(&fmt, lst, &f_struct);
		else
			count += write(1, fmt, 1);
		fmt++;
	}
	va_end(lst);
	return (count);
}
/*
int main()
{
	//char c;
	int n1 = ft_printf("%.0d\n", 420000);
	int n2 =    printf("%.0d\n", 420000);
	printf("n:%d\n",n1 );
	printf("n2:%d\n",n2 );
}*/
