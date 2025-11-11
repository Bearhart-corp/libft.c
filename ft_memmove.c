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

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*des;
	const unsigned char	*source;

	des = (unsigned char *)dest;
	source = (const unsigned char *)src;
	if (des == source || n == 0)
		return (dest);
	if (des < source)
		while (n--)
			*des++ = *source++;
	else
		while (n--)
			des[n] = source[n];
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