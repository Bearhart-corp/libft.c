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

static void	helper_init(t_nbr *s, t_flags f, unsigned long n)
{
	if (f.conv == PTR)
		(*s).prefix = "0x";
	else if ((*s).is_hex && (f.flags & HASH) && n != 0)
	{
		if ((*s).upper)
			(*s).prefix = "0X";
	}
	else
		(*s).prefix_len = 0;
	(*s).pad = f.width - (int)((*s).sign_len + (*s).n_digit);
	if ((*s).pad < 0)
		(*s).pad = 0;
	if (f.point)
	{
		if (f.prec > (int)s->n_digit)
			(*s).zero = (size_t)(f.prec - (int)(*s).n_digit);
		else
			(*s).zero = 0;
	}
}

void	init(t_flags *f)
{
	(*f).flags = 0;
	(*f).width = 0;
	(*f).prec = 0;
	(*f).conv = 0;
	(*f).point = 0;
}

void	init_nbr(t_nbr *s, t_flags f, unsigned long n)
{
	(*s).pad_prec = 0;
	(*s).zero = 0;
	(*s).count = 0;
	(*s).sign_len = 0;
	(*s).sign = 0;
	(*s).is_hex = (f.conv == HEX_LOW || f.conv == HEX_MAJ || f.conv == PTR);
	(*s).upper = (f.conv == (*s).is_hex);
	if (f.conv == UNSIGNED)
		(*s).base = 10;
	else
		(*s).base = 16;
	(*s).is_left = (f.flags & START_LEFT);
	(*s).zero_pad_width = (f.flags & ZEROS) && !((*s).is_left);
	if ((*s).zero_pad_width && !(f.point))
		(*s).sym_pad = '0';
	else
		(*s).sym_pad = ' ';
	s->upper = (f.conv == HEX_MAJ);
	(*s).prefix_len = 0;
	(*s).n_digit = h(n, (*s).base, (*s).buf, f);
	(*s).prefix_len = 2;
	helper_init(s, f, n);
}

void	helper_init_int(t_nbr *s, t_flags f, long *n)
{
	if ((*s).zero_pad_width && !(f.point))
		(*s).sym_pad = '0';
	else
		(*s).sym_pad = ' ';
	(*s).prefix_len = 0;
	if (*n < 0)
	{
		(*n) = -(*n);
		(*s).sign = '-';
	}
	else if (f.flags & PLUS)
		(*s).sign = '+';
	else if (f.flags & SPACE)
		(*s).sign = ' ';
	else
		(*s).sign_len = 0;
	(*s).n_digit = ft_putnbr_help(*n, (*s).buf, f);
	(*s).pad = f.width - (int)((*s).sign_len + (*s).n_digit);
	if ((*s).pad < 0)
		(*s).pad = 0;
}

void	init_nbr_int(t_nbr *s, t_flags f, long *n)
{
	(*s).pad_prec = 0;
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
	(*s).prefix = 0;
	helper_init_int(s, f, n);
}
