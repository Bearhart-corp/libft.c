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

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	while (n--)
		*(unsigned char *)(dest + n) = *(unsigned char *)(src + n);
	return ((void *)dest);
}

/*
int main()
{
	int dest[10];
	int src[3] = {11, 22, 42};
	ft_memcpy(dest, src, sizeof(int) * 3);
	for(int i = 0; i < 3; i++)
	{
		printf("%d \n", dest[i]);
	}
}*/