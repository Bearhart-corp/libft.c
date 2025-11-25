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

void	init(t_var *s, char *buf, int fd)
{
	s->tmp = NULL;
	s->cap = BUFFER_SIZE + 1;
	s->line = malloc(s->cap);
	s->len = 0;
	if (*buf)
	{
		ft_memmove(s->line, buf, ft_strchr(buf, 0, BUFFER_SIZE));
		s->len = ft_strlen(s->line);
	}
	s->byte = read(fd, buf, BUFFER_SIZE);
	if (s->byte >= 0)
   		buf[s->byte] = 0;
	s->addr = NULL;
}

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

char	*ft_strchr(const char *s, int c, size_t n)
{
	int	i;

	i = -1;
	while (s[++i] && n--)
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
