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

#ifndef PRINTF_H
# define PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

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

typedef struct s_flags
{
	char	flags;
	char	width;
	char	prec;
	char	conversion;
}	t_flags;

int		ft_printf(const char *fmt, ...);
size_t	ft_putfloat(double n, t_flags flag_struct);
int		ft_tolower(int c);
int		ft_toupper(int c);
size_t	ft_strlen(const char *s);
size_t	ft_putchar_fd(char c, t_flags flags_struct);
size_t	ft_putnbr(long n, t_flags flags_struct);
size_t	ft_putstr_fd(char *s, t_flags flags_struct);

#endif