/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbelard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 14:05:55 by tbelard           #+#    #+#             */
/*   Updated: 2025/11/07 14:05:57 by tbelard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
#include <stdint.h>
# include <unistd.h>
# include <stdarg.h>
# include <limits.h>
///////////WARNING
# include <stdio.h>

# define UPPER 1
# define ADRR_F 1
# define HEX 16
# define DEC 10
# define BIN 2
# define OCT 8
# define START_LEFT 1
# define ZEROS 2
# define HASH 4
# define SPACE 8
# define PLUS 16

# define STRING 1
# define LETTER 2
# define INTEGER 3
# define UNSIGNED 4
# define PTR 5
# define HEX_LOW 6
# define HEX_MAJ 7
# define POINT 1

# define COUNT 0
# define LEN 1
# define PAD 2
# define NEG 0x8000000000000000
# define NEG4 0x80000000

////////////// struct format

typedef struct s_flags
{
	unsigned char	flags;
	int				width;
	int				prec;
	unsigned char	conv;
	unsigned char	point;
}	t_flags;

////////////// struct nombre

typedef struct nombre
{
	int		pad_prec;
	size_t	count;
	char	sign;
	int		sign_len;
	char	buf[0x1000];
	int		pad_width;
	int		base;
	int		is_hex;
	int		is_left;
	int		n_digit;
	char	sym_pad;
	char	*prefix;
	int		prefix_len;
	char	*base_sym;
}	t_nbr;

////////////// main

int		ft_printf(const char *fmt, ...);

////////////// printers.char

size_t	ft_putchar_fd(char c, t_flags flags_struct);
size_t	ft_putstr(char *s, t_flags f);

////////////// printers.nbr

size_t	ft_putfloat(double n, t_flags flag_struct);
size_t	ft_putnbr(long n, t_flags flags_struct);
size_t	ft_putnbr_u(unsigned long n, t_flags f);

////////////// petits helper

int	ft_strlen(char *s);

////////////// putnbr helper


////////////// init struct

void	init(long *n, t_flags f, int is_nbr, t_nbr *s);
void	init_f(t_flags *f);
void	init_u(unsigned long *n, t_flags f, int is_nbr, t_nbr *s);

#endif