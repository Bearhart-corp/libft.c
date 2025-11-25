/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbelard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 15:51:02 by tbelard           #+#    #+#             */
/*   Updated: 2025/11/18 15:51:03 by tbelard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	if (!s)
		return (0);
	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = -1;
	while (s[++i])
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
	}
	if (s[i] == (char)c && !s[i])
		return ((char *)s + i);
	return (NULL);
}

void	*ft_memmove(void *dest, const void *src, char *add_end)
{
	unsigned char		*d;
	const unsigned char	*s;
	unsigned char		*ad;

	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	ad = (unsigned char *)add_end;
	if (dest == src)
		return (dest);
	while (s <= ad)
			*d++ = *s++;
		*d = 0;
	return(dest);
}
