/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbelard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 12:53:00 by tbelard           #+#    #+#             */
/*   Updated: 2025/10/27 12:53:02 by tbelard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *destination, const void *src, size_t size)
{
	unsigned char		*dest;
	const unsigned char	*source;

	dest = (unsigned char *)destination;
	source = (const unsigned char *)src;
	if (dest == source)
		return (dest);
	if (dest < source)
		while (size--)
			*dest++ = *source++;
	else
		while (size--)
			dest[size] = source[size];
	return (dest);
}

/*
int main()
{
	   char data[] = "1234";
	   void *src = (void *)data;
	   void *dest = (void *)data;
	   ft_memmove(dest, src, 4);
	   int i = 0;
	   while (i < 4)
	   {
	   	 write(1, &dest[i], 1);
	   	i++;
	   }
}*/