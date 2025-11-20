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

static size_t	pre_init(va_list lst, t_flags *f)
{
	if (f->conv == STRING)
		return (ft_putstr_fd((va_arg(lst, char *), *f));
	if (f->conv == LETTER)
		return (ft_putchar_fd((char)va_arg(lst, int), *f));
	if (f->conv >= INTEGER && f->conv <= HEX_MAJ)
		return (ft_putnbr((uint64_t)va_arg(lst, long), *f)));
	if (f->conv == 8)
		return (ft_putfloat(va_arg(lst, double), *f));
	else
		return (1);
}

static size_t	conv(const char **fmt, va_list lst, t_flags *f)
{
	if ((**fmt) == 's')
		f->conv = STRING;
	else if ((**fmt) == 'c')
		f->conv = LETTER;
	else if ((**fmt) == 'd' || (**fmt) == 'i')
		f->conv = INTEGER;
	else if ((**fmt) == 'u')
		f->conv = UNSIGNED;
	else if ((**fmt) == 'p')
		f->conv = PTR;
	else if ((**fmt) == 'x')
		f->conv = HEX_LOW;
	else if ((**fmt) == 'X')
		f->conv = HEX_MAJ;
	else if ((**fmt) == 'f')
		f->conv = 8;
	else if ((**fmt) == '%')
		return (ft_putchar_fd('%', *f));
	return (pre_init(lst, f));
}

static size_t	accuracy_f(const char **fmt, va_list lst, t_flags *f)
{
	if ((**fmt) != '.')
		return (conv(fmt, lst, f));
	f->point = 1;
	(*fmt)++;
	while (**fmt >= '0' && **fmt <= '9')
	{
		f->prec = f->prec * 10 + (**fmt - 48);
		(*fmt)++;
	}
	if (f->prec == 0 && **fmt == 'f')
		f->prec = 6;
	return (conv(fmt, lst, f));
}

static size_t	flag_pars(const char **fmt, va_list lst, t_flags *f)
{
	init(f);
	while (**fmt == '-' || **fmt == '+' || **fmt == ' ' || **fmt == '#'
		|| **fmt == '0')
	{
		if ((**fmt) == '-')
			f->flags |= START_LEFT;
		else if ((**fmt) == '0' && (!(f->flags & START_LEFT)))
			f->flags |= ZEROS;
		else if ((**fmt) == '#')
			f->flags |= HASH;
		else if ((**fmt) == '+')
			f->flags |= PLUS;
		else if ((**fmt) == ' ')
			f->flags |= SPACE;
		(*fmt)++;
	}
	while (**fmt >= 48 && **fmt <= 57)
	{
		f->width = f->width * 10 + (**fmt - 48);
		(*fmt)++;
	}
	return (accuracy_f(fmt, lst, f));
}

int	ft_printf(const char *fmt, ...)
{
	va_list	lst;
	size_t	count;
	t_flags	f;

	count = 0;
	if (!fmt || write(1, "", 0) == -1)
		return (-1);
	va_start(lst, fmt);
	while (*fmt)
	{
		if ((*fmt) == '%' && fmt[1])
		{
			fmt++;
			count += flag_pars(&fmt, lst, &f);
		}
		else
			count += write(1, fmt, 1);
		fmt++;
	}
	va_end(lst);
	return ((int)count);
}
