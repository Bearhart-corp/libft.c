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

size_t	ft_abs(int a, int b)
{
	if ((a - b) > 0)
		return (a - b);
	else
		return (0);
}

void	init_f(t_flags *f)
{
	f->flags = 0;
	f->width = 0;
	f->prec = 0;
	f->conv = 0;
	f->point = 0;
}

static size_t	count_n_digit(uint64_t n, int base, t_flags f)
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

void	init(long *n, t_flags f, int is_nbr, t_nbr *s)
{
	s->count = 0;
	s->n_digit = 0;
	s->base = 0;
	s->pad_width = f.width;
	s->base_sym = "0123456789abcdef";
	if (f.conv == HEX_MAJ)
		s->base_sym = "0123456789ABCDEF";
	if (f.conv == INTEGER && !(*n))
		s->pad_width = 0;
	s->is_hex = (f.conv >= PTR && f.conv <= HEX_MAJ); 
	//seul ptr et ishex + hash ont 0x
	if (f.conv == INTEGER || f.conv == UNSIGNED)
		s->base = 10;
	else
		s->base = 16;
	s->is_left = (f.flags & START_LEFT);
	s->sign = 0;
	s->pad_prec = 0;
	if (is_nbr)//sign que si entier
	{
		if (f.conv == INTEGER && *n & NEG && f.conv != PTR)
		{
			*n = -(*n);
			s->sign = '-';
		}
		else
		{
			if (f.flags & SPACE)
				s->sign = ' ';
			if (f.flags & PLUS)
				s->sign = '+';
		}
		s->n_digit = count_n_digit((uint64_t)*n, s->base, f);
		s->pad_prec = ft_abs(f.prec, s->n_digit);
	}
	if (!is_nbr && *n)
		*(s->buf) = *(char *)*n;
	if (!(*n) && (f.prec >= 5 || !f.point) && f.conv == PTR)
		*((uint64_t *)s->buf) = 0x296C696E28; //(nil)
	if (s->sign)
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
			s->prefix = "X0";
		else
			s->prefix = "x0";
		s->prefix_len = 2;
	}
	else
		s->prefix = "";
	//peut etre neg donc verif > 0
	s->pad_width -= (s->sign_len + s->pad_prec + s->prefix_len + s->n_digit);
}


void	init_u(unsigned long *n, t_flags f, int is_nbr, t_nbr *s)
{
	s->count = 0;
	s->n_digit = 0;
	s->base = 0;
	s->pad_width = f.width;
	s->base_sym = "0123456789abcdef";
	if (f.conv == HEX_MAJ)
		s->base_sym = "0123456789ABCDEF";
	if (f.conv == INTEGER && !(*n))
		s->pad_width = 0;
	s->is_hex = (f.conv >= PTR && f.conv <= HEX_MAJ); 
	//seul ptr et ishex + hash ont 0x
	if (f.conv == INTEGER || f.conv == UNSIGNED)
		s->base = 10;
	else
		s->base = 16;
	s->is_left = (f.flags & START_LEFT);
	s->sign = 0;
	s->pad_prec = 0;
	if (is_nbr)//sign que si entier
	{
		if (f.conv == INTEGER && *n & NEG && f.conv != PTR)
		{
			*n = -(*n);
			s->sign = '-';
		}
		else
		{
			if (f.flags & SPACE)
				s->sign = ' ';
			if (f.flags & PLUS)
				s->sign = '+';
		}
		s->n_digit = count_n_digit((uint64_t)*n, s->base, f);
		s->pad_prec = ft_abs(f.prec, s->n_digit);
	}
	if (!is_nbr && *n)
		*(s->buf) = *(char *)*n;
	if (!(*n) && (f.prec >= 5 || !f.point) && f.conv == PTR)
		*((uint64_t *)s->buf) = 0x296C696E28; //(nil)
	if (s->sign)
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
			s->prefix = "X0";
		else
			s->prefix = "x0";
		s->prefix_len = 2;
	}
	else
		s->prefix = "";
	//peut etre neg donc verif > 0
	s->pad_width -= (s->sign_len + s->pad_prec + s->prefix_len + s->n_digit);
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
