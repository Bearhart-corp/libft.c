/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbelard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 13:08:22 by tbelard           #+#    #+#             */
/*   Updated: 2025/10/27 13:08:23 by tbelard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_strlen(char *s)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

size_t	ft_putstr_fd(char *s, t_flags f)
{
	t_nbr	s;

	init(s, f, 0, &s);
	return (write(1, s, ft_strlen(s)));
}

/*1010 / 3 (*,/,-)

sum = 0;
	sum =+ n >> 2 
	n = sum + (n & 3)
void	init(uint64_t bin, t_flags f, int is_nbr, t_nbr *s)*/