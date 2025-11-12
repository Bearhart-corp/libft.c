/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbelard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 13:08:00 by tbelard           #+#    #+#             */
/*   Updated: 2025/10/27 13:08:02 by tbelard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_putchar_fd(char c, t_flags flags_struct)
{
	int 	i;
	int		largeur;

	largeur = flags_struct.width;
	i = 0;
	if (flags_struct.width)
	{
		if (flags_struct.flags & START_LEFT)
			write(1, &c, 1);
		while (++i < largeur)
			write(1, " ", 1);
		if (!(flags_struct.flags & START_LEFT))
			write(1, &c, 1);
	}
	else
		i = write(1, &c, 1);
	return (i);
}
