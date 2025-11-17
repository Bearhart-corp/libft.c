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
# include <unistd.h>
# include <stdarg.h>
# include <limits.h>

# define SIZE_MAX -1
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
# define PTR 4
# define UNSIGNED 5
# define HEX_LOW 6
# define HEX_MAJ 7
# define POINT 1

# define COUNT 0
# define LEN 1
# define PAD 2

////////////// struct format

typedef struct s_flags
{
	unsigned char	flags;
	size_t			width;
	int				prec;
	unsigned char	conversion;
	unsigned char	point;
}	t_flags;

////////////// struct nombre

typedef struct nombre
{
	size_t	count;
	char	sign;
	size_t	sign_len;
	char	buf[64];
	int		pad;
	int		base;
	int		upper;
	int		is_hex;
	int		is_left;
	int		zero_pad_width;
	size_t	n_digit;
	char	*prefix;
	size_t	prefix_len;
	int		z;
	int		zero;
	char	sym_pad;
}	nbr;

////////////// main

int		ft_printf(const char *fmt, ...);

////////////// printers.char

size_t	ft_putchar_fd(char c, t_flags flags_struct);
size_t  ft_putstr_fd(char *s, t_flags f);
size_t	ft_putchar(char c);

////////////// printers.nbr

size_t	ft_putfloat(double n, t_flags flag_struct);
size_t	ft_putnbr(long n, t_flags flags_struct);
size_t	Uputnbr(unsigned long n, t_flags f);

////////////// petits helper

int		ft_toupper(int c);
size_t	ft_strlen(const char *s);
void	ft_toupper_str(char *s);
int		ft_max(int a, int b);

////////////// putnbr helper

size_t	h(unsigned long n, int base, char *buf, t_flags f);
size_t	ft_putnbr_help(long n, char *buf, t_flags f);
size_t	ptr_zero(t_flags f);

////////////// init struct

void	init_nbr_int(nbr *s, t_flags f, int neg, long n);
void	init(t_flags *f);
void	init_nbr(nbr *s, t_flags f, unsigned long n);

#endif