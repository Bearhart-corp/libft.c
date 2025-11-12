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

size_t	ft_putstr_fd(char *s, t_flags flags_struct)
{
	size_t	count;
	int		largeur;
	int		i;
	char	sz;

	if ((flags_struct.flags & ZEROS) && !(flags_struct.flags & START_LEFT))
		sz = '0';
	else
		sz = 32;
	i = 0;
	largeur = 0;
	count = 0;
	largeur = flags_struct.width;
	if (!s)
		return (count += write(1, "(null)", 6));
	if (flags_struct.width)
		i = largeur - ft_strlen(s) - 1;
	if (flags_struct.flags & START_LEFT)
	{
		while (*s)
		{
			count += write(1, s, 1);
			s++;
		}
		while (i <= largeur)
		{
			count += write(1, &sz, 1);
			i++;
		}
	}
	else
	{
		while (++i <= largeur && largeur)
			count += write(1, &sz, 1);
		while (*s)
		{
			count += write(1, s, 1);
			s++;
		}
	}
	return (count);
}

/*1010 / 3 (*,/,-)

sum = 0;
	sum =+ n >> 2 
	n = sum + (n & 3)
*/
