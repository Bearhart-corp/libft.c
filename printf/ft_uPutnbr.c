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

static int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

size_t	Uputnbr(unsigned long n, t_flags f)
{
	nbr		s;
	int		pad_prec;

	init_nbr(&s, f, n);
	if (f.conversion == PTR && n == 0)
		return (s.count+= ptr_zero(f));
	if (s.upper && f.conversion != PTR)
		ft_toupper_str(s.buf);
	s.z = f.width - (int)(s.sign_len + ft_max(s.n_digit, f.prec));
	if (s.z < 0)
		s.z = 0;
	if (f.point)
		pad_prec = f.prec - s.n_digit;
	else
		pad_prec = 0;
	if (!(s.is_left))
	{
		while (s.z-- > 0)
			s.count += write(1, &s.sym_pad, 1);
		while (f.point && pad_prec-- > 0)
			s.count += write(1, "0", 1);
		s.count += write(1, &s.sign, s.sign_len);
		if (!f.point || f.prec)
			s.count += write(1, s.buf, s.n_digit);
		else if (f.point && !(f.prec) && n > 0)
			s.count += write(1, s.buf, s.n_digit);
	}
	if (s.is_left)
	{
		while (f.point && pad_prec-- > 0)
			s.count += write(1, "0", 1);
		s.count += write(1, &s.sign, s.sign_len);
		if (!f.point || f.prec)
			s.count += write(1, s.buf, s.n_digit);
		else if (f.point && !(f.prec) && n > 0)
			s.count += write(1, s.buf, s.n_digit);
		while (s.z-- > 0)
			s.count += write(1, &s.sym_pad, 1);
	}
	return (s.count);
}
