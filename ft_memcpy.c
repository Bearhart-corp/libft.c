/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbelard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 12:52:41 by tbelard           #+#    #+#             */
/*   Updated: 2025/10/27 12:52:43 by tbelard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *destination, const void *src, size_t size)
{
	while (size--)
		*(unsigned char *)(destination + size) = *(unsigned char *)(src + size);
	return ((void *)destination);
}
