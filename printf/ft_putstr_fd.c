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

#include "printf.h"

size_t	ft_putstr_fd(char *s, int fd, size_t size)
{
	size_t	count;

	if (!s)
		return (0);
	if (!size)
		count = ft_strlen(s);
	else
		count = size;
	write(fd, s, count);
	return (count);
}
