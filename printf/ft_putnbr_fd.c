/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbelard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 13:08:56 by tbelard           #+#    #+#             */
/*   Updated: 2025/10/27 13:08:58 by tbelard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_putnbr(long n, t_flags f)
{
	t_nbr		s;

	init_nbr_int(&s, f, &n);
	ft_putnbr_help(n, f, &s);
	if (f.point && f.prec == 0 && n == 0)
		s.n_digit = 0;
	s.pad_prec = ft_max(f.prec, s.n_digit);
	s.z = f.width - (int)(s.sign_len + s.pad_prec);
	if (s.z < 0)
		s.z = 0;
	if (f.flags & ZEROS && !(f.point))
		s.count += write(1, &s.sign, s.sign_len);
	if (!(s.is_left))
		while (s.z--)
			s.count += write(1, &s.sym_pad, 1);
	if (!(f.flags & ZEROS) || f.point)
		s.count += write(1, &s.sign, s.sign_len);
	while (f.point && s.pad_prec-- > (int)s.n_digit)
		s.count += write(1, "0", 1);
	s.count += write(1, s.buf, s.n_digit);
	if (s.is_left)
		while (s.z--)
			s.count += write(1, " ", 1);
	return (s.count);
}
