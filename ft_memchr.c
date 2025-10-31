/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbelard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 12:56:07 by tbelard           #+#    #+#             */
/*   Updated: 2025/10/27 12:56:09 by tbelard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *memoryBlock, int searchedChar, size_t size)
{
	unsigned int	i;

	i = 0;
	while (i < size)
	{
		if (*(unsigned char *)(memoryBlock + i) == (unsigned char)searchedChar)
			return ((void *)memoryBlock + i);
		i++;
	}
	return (NULL);
}
