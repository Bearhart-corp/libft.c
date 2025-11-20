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

static size_t	count_n_digit(long long n, int base)
{
	size_t	i;

	i = 0;
	if (n == 0)
	{
		if (f.point && f.prec == 0)
			return (0);
		return (1);
	}
	if (n == 0 || base == 0)
		return (1);
	while (n != 0)
	{
		i++;
		n /= base;
	}
	return (i);
}
//1. Avec %x ou %X (hexadécimal)
//Le # ajoute le préfixe 0x ou 0X devant le nombre.
//❌ 4. Avec d’autres formats (%d, %s, etc.)
//Le # n’a aucun effet.
//le ' ' nexiste que si la place nest pas prise par le signe
//printf("%#08x", 42); // 0x00002a

void	init(uint64_t bin, t_flags f, int is_nbr, t_nbr *s)
{
	t_nbr s;

	s->count = 0;
	s->n_digit = 0;
	s->buf[0x1000];
	s->base = 0;
	s->is_hex = (f.conv >= PTR && f.conv <= HEX_MAJ); 
	//seul ptr et ishex + hash ont 0x
	if (f.conv == INTEGER || f.conv == UNSIGNED)
		s->base = 10;
	else
		s->base = 16;
	s->is_left = (f.flags & START_LEFT);
	s->sign = 0;
	if (is_nbr)//sign que si entier
	{
		if (f.conv == INTEGER)
			if (bin & NEG)
			{
				bin = -bin;
				s->sign = '-';
			}
		else
		{
			if (f.flags & SPACE)
				s->sign = ' ';
			if (f.flags & PLUS)
				s->sign = '+';
		}
		s->n_digit = count_n_digit((long long)bin);
	}
	if (sign[0])
		s->sign_len = 1;
	else
		s->sign_len = 0;
	if (!(f.point) && is_nbr && f.flags & ZEROS && !(s->is_left))
		s->sym_pad = '0';
	else
		s->sym_pad = ' ';
	s->prefix_len = 0;
	if (f.conv == PTR || (s->is_hex && f.flags & HASH))
	{
		if (f.conv == HEX_MAJ)
			s->prefix = "0X";
		else
			s->prefix = "0x";
		s->prefix_len = 2;
	}
	else
		s->prefix = "";
	s->pad_prec = f.prec - s->n_digit;//peut etre neg donc verif > 0
	s->pad_width -= (sign_len + s->pad_prec + s->prefix_len + s->n_digit);
}

/*
	int		pad_prec;
	size_t	count;
	char	sign;
	char	buf[64];
	int		pad_width;
	int		base;
	int		is_hex;
	int		is_left;
	size_t	n_digit;
	char	sym_pad;
	char	*prefix;
	int		sign_len;
	int		prefix_len;
	*/