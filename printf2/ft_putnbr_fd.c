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



static size_t	h(long long n, t_flags f, t_nbr *s)
{
	size_t	count;
	size_t	i;
	char	tmp[64];

	i = -1;
	count = 0;
	if (!(s->isleft))
		while (s->pad_width-- > 0)
			tmp[count++] = s->sym_pad;
	while (n > 0)
	{
		tmp[count++] = "0123456789abcdef"[n & s->base];
		n = n / s->base;
	}
	while (s->prefix[++i])
		tmp[count++] = s->prefix[i];
	i = - 1;
	while (s->pad_prec-- > s->n_digit)
		tmp[count++] = '0';
	if (s->sign_len)
		tmp[count++] = s->sign;
	count = 0;
	if (s->isleft)
		while (s->pad_width-- > 0)
			tmp[count++] = s->sym_pad;
	while (++i < count)
		s->buf[i] = tmp[(count - 1) - i];
	return (count);
}
//pad - sign - prec - prefix - digit - pad
size_t	ft_putnbr(long n, t_flags f)
{
	t_nbr	s;
	
	init(n, f, 1, &s);
	h(n, f, s);
	return (h())
}
