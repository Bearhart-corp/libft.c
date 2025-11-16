/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbelard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 12:48:26 by tbelard           #+#    #+#             */
/*   Updated: 2025/11/14 12:48:34 by tbelard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	helper_init(nbr *s, t_flags f, unsigned long n)
{
	if (f.conversion == PTR)
		(*s).prefix = "0x";
	else if ((*s).is_hex && (f.flags & HASH) && n != 0)
	{
		if ((*s).upper)
			(*s).prefix = "0X";
		(*s).prefix_len = 2;
	}
	else
		(*s).prefix_len = 0;
	
	(*s).pad = f.width - (int)((*s).sign_len + (*s).prefix_len + (*s).n_digit);
	if ((*s).pad < 0)
		(*s).pad = 0;
}

void	init(t_flags *f)
{
	(*f).flags = 0;
	(*f).width = 0;
	(*f).prec = 0;
	(*f).conversion = 0;
	(*f).point = 0;
}

void	init_nbr(nbr *s, t_flags f, unsigned long n)
{
	(*s).zero = 0;
	(*s).count = 0;
	(*s).sign_len = 0;
	(*s).sign = 0;
	(*s).is_hex = (f.conversion == HEX_LOW 
		|| f.conversion == HEX_MAJ || f.conversion == PTR);
	(*s).upper = (f.conversion == (*s).is_hex);
	if (f.conversion == UNSIGNED)
		(*s).base = 10;
	else
		(*s).base = 16;
	(*s).is_left = (f.flags & START_LEFT);
	(*s).zero_pad_width = (f.flags & ZEROS) && !((*s).is_left);
	(*s).n_digit = h(n, (*s).base, (*s).buf, f);
	(*s).prefix_len = 2;
	helper_init(s, f, n);
}

void	init_nbr_int(nbr *s, t_flags f, int neg, long n)
{
	(*s).count = 0;
	(*s).z = 0;
	(*s).zero = 0;
	(*s).base = 10;
	(*s).sign_len = 1;
	(*s).sign = ' ';
	(*s).is_hex = 0;
	(*s).upper = 0;
	(*s).is_left = (f.flags & START_LEFT);
	(*s).zero_pad_width = (f.flags & ZEROS) && !((*s).is_left);
	(*s).n_digit = ft_putnbr_help(n, (*s).buf);
	(*s).prefix = 0;
	if ((*s).zero_pad_width)
		(*s).sym_pad = '0';
	else
		(*s).sym_pad = ' ';
	(*s).prefix_len = 0;
	if (neg)
		(*s).sign = '-';
	else if (f.flags & PLUS)
		(*s).sign = '+';
	else if (f.flags & SPACE)
		(*s).sign = ' ';
	else
		(*s).sign_len = 0;
	(*s).pad = f.width - (int)((*s).sign_len + (*s).n_digit);
	if ((*s).pad < 0)
		(*s).pad = 0;
}