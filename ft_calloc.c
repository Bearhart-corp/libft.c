/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbelard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 12:58:36 by tbelard           #+#    #+#             */
/*   Updated: 2025/10/27 12:58:38 by tbelard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t elementCount, size_t elementSize)
{
	void	*buf;

	buf = malloc(elementCount * elementSize);
	if (!buf)
		return (NULL);
	ft_bzero(buf, elementCount);
	return (buf);
}
