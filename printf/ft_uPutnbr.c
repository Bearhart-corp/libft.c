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

static size_t	helper(t_nbr s, t_flags f)
{
	if (!(s.is_left))
	{
		while (s.z-- > 0)
			s.count += write(1, &s.sym_pad, 1);
	}
	while (f.point && s.pad_prec-- > 0)
			s.count += write(1, "0", 1);
		s.count += write(1, &s.sign, s.sign_len);
		s.count += write(1, s.buf, s.n_digit);
	if (s.is_left)
	{
		while (s.z-- > 0)
			s.count += write(1, &s.sym_pad, 1);
	}
	return (s.count);
}

size_t	u_putnbr(unsigned long n, t_flags f)
{
	t_nbr		s;

	init_nbr(&s, f, n);
	if (f.conv == PTR && n == 0)
		return (s.count += ptr_zero(f));
	if (s.upper && f.conv != PTR)
		ft_toupper_str(s.buf);
	s.z = f.width - (int)(s.sign_len + ft_max(s.n_digit, f.prec));
	if (s.z < 0)
		s.z = 0;
	if (f.point)
		s.pad_prec = f.prec - s.n_digit;
	else
		s.pad_prec = 0;
	return (helper(s, f));
}
