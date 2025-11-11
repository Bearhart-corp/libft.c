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

#include "printf.h"

size_t	ft_putchar_fd(char c, t_flags flags_struct)
{
	int 	i;

	i = flags_struct.flags;
	i++;
	if (!c)
		return (0);
	write(1, &c, 1);
	return (1);
}
