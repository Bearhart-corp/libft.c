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

static int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

int	ft_strlen(char *s)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

static	void init_str(t_flags f, t_nbr *s, int len)
{
	s->is_left = (f.flags & START_LEFT);
	s->pad_width = f.width - ft_max(f.prec, len);
}

size_t	ft_putstr(char *str, t_flags f)
{
	t_nbr	s;
	size_t	count;
	int		len;

	count = 0;
	len = ft_strlen(str);
	init_str(f, &s, len);
	if ((f.point && f.prec > 0) && len > f.prec)
	{
		len = f.prec;
	}
	if (!(s.is_left))
		while (s.pad_width-- > len)
			count += write(1, " ", 1);
	count += write(1, str, len);
	if (s.is_left)
		while (s.pad_width-- > len)
			count += write(1, " ", 1);
	return (count);
}

/*1010 / 3 (*,/,-)

sum = 0;
	sum =+ n >> 2 
	n = sum + (n & 3)
void	init(uint64_t bin, t_flags f, int is_nbr, t_nbr *s)*/