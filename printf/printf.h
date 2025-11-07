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

int	ft_printf(const char *, ...);

void	*ft_calloc(size_t nmemb, size_t size);
int		ft_tolower(int c);
int		ft_toupper(int c);
size_t	ft_strlen(const char *s);
size_t	ft_putchar_fd(char c, int fd);
size_t	ft_putnbr_fd(long n, int fd, int unsign);
size_t	ft_putstr_fd(char *s, int fd, size_t size);
void	ft_bzero(void *s, size_t n);

#endif