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
	nbr		s;
	int		neg;

	neg = (n < 0);
	if (neg)
		n = -n;
	init_nbr_int(&s, f, neg, n);
	ft_putnbr_help(n, s.buf);
	s.z = f.width - (int)(s.sign_len + s.n_digit);
	if (s.z < 0)
		s.z = 0;
	if (!(s.is_left))
	{
		s.count += write(1, &s.sign, s.sign_len);
		while (s.z--)
			s.count += write(1, &s.sym_pad, 1);
	}
	s.count += write(1, s.buf, s.n_digit);
	if (s.is_left)
		while (s.z--)
			s.count += write(1, &s.sym_pad, 1);
	return (s.count);
}

/*
printf("c:%zu\n n_d:%zu\n pre:%zu\n s_len:%zu\n", s.count, s.n_digit, s.prefix_len, s.sign_len);
printf("sign:%c\n, prefix: %s\n, pad: %d\n, base; %d\n, upper: %d\n, hex: %d\n",s.sign, s.prefix,s.pad, s.base, s.upper, s.is_hex);
printf("left: %d\n, zeropaas : %d \n, z: %d\n, zero: %d\n",s.is_left, s.zero_pad_width, s.z , s.zero );
*/