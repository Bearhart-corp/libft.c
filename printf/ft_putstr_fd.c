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
#include <stdio.h>

size_t	ft_putstr_fd(char *s, t_flags flags_struct)
{
	size_t	count;
	size_t	largeur;
	int		accuracy;
	char	sz;

	if ((flags_struct.flags & ZEROS) && !(flags_struct.flags & START_LEFT))
		sz = '0';
	else
		sz = 32;
	largeur = 0;
	accuracy = 0;
	count = 0;
	if (flags_struct.flags == SPACE)
		count += write(1, " ", 1);
	if (!s)
	{
		if (flags_struct.prec && flags_struct.prec < 6)
			return (0);
		else
			return (count += write(1, "(null)", 6));
	}
	if (flags_struct.prec)
		accuracy = flags_struct.prec;
	if (flags_struct.width)
	{
		if (flags_struct.prec)
			largeur = (flags_struct.width - accuracy) - count;
		else
			largeur = (flags_struct.width - ft_strlen(s) - count);
	}
	if (flags_struct.width)
	{
		if (flags_struct.flags & START_LEFT)
		{
			while ((*s && accuracy-- ))
				count += write(1, s++, 1);
			while (largeur--)
				count += write(1, &sz, 1);
		}
		else
		{
			while (largeur--)
				count += write(1, &sz, 1);
			largeur = flags_struct.width - ft_strlen(s);
			if (accuracy)
				while ((*s && accuracy-- ) && largeur++ <= flags_struct.width)
					count += write(1, s++, 1);
			else
				while ((*s) && largeur++ <= flags_struct.width)
					count += write(1, s++, 1);
		}
	}
	else
		while (*s)
			count += write(1, s++, 1);
	return (count);
}

/*1010 / 3 (*,/,-)

sum = 0;
	sum =+ n >> 2 
	n = sum + (n & 3)
*/