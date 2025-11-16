/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uPutnbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbelard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 14:52:54 by tbelard           #+#    #+#             */
/*   Updated: 2025/11/14 14:52:56 by tbelard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	Uputnbr_suite( t_flags f, nbr s)
{
	if (!s.is_left)
	{
		while (!(s.pad-- & 0x8000000000000000))
			s.count += write(1, " ", 1);
		s.count += write(1, &s.sign, s.sign_len);
		s.count += write(1, &s.prefix, s.prefix_len);
		s.count += write(1, s.buf, s.n_digit);
	}
	if (!s.is_left)
		while (!(s.pad-- & 0x8000000000000000))
			s.count += write(1, " ", 1);
	if (f.point)
	{
		if (f.prec > (int)s.n_digit)
			s.zero = (size_t)(f.prec - (int)s.n_digit);
		else
			s.zero = 0;
	}
}

size_t	Uputnbr(unsigned long n, t_flags f)
{
	nbr		s;
	char	sym_pad;

	if (s.zero_pad_width)
		sym_pad = '0';
	else
		sym_pad = ' ';
	init_nbr(&s, f, n);
	if (f.conversion == PTR && n == 0)
		return (s.count+= ptr_zero(f));

	if (s.upper)
		ft_toupper_str(s.buf);
	s.z = f.width - (int)(s.sign_len + s.prefix_len + s.n_digit);
	if (s.z < 0)
		s.z = 0;
	if (!(s.is_left))
	{
		s.count += write(1, &s.sign, s.sign_len);
		s.count += write(1, &s.prefix, s.prefix_len);
		while (s.z-- & 0x8000000000000000)
			s.count += write(1, &sym_pad, 1);
		s.count += write(1, s.buf, s.n_digit);
	}
	Uputnbr_suite(f, s);
	return (s.count);
}
