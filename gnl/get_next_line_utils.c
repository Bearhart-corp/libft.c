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

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*buf;
	int		n;

	if (nmemb != 0 && size >= SIZE_MAX / nmemb)
		return (NULL);
	buf = malloc(nmemb * size);
	if (!buf)
		return (NULL);
	n = nmemb * size;
	while (n--)
		*(unsigned char *)(buf + n) = 0;
	return (buf);
}

char	*ft_strdup(char *s)
{
	int		i;
	char	*str;

	i = 0;
	str = malloc(ft_strlen(s) + 1);
	if (!str)
		return (NULL);
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = 0;
	return (str);
}

char	*ft_strchr( char *s, int c)
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

char	*ft_strjoin(char *s1, char *s2)
{
	char	*buf;
	char	*start;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	buf = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!buf)
		return (NULL);
	start = buf;
	while (*s1)
		*buf++ = *s1++;
	while (*s2)
		*buf++ = *s2++;
	*buf = 0;
	return (start);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*buf;
	size_t	j;
	size_t	true_size;

	if (!s)
		return (NULL);
	true_size = ft_strlen(s);
	j = 0;
	if (len == 0 || start >= true_size)
	{
		buf = ft_calloc(1, 1);
		return (buf);
	}
	if (start + len > true_size)
		len = true_size - start;
	buf = malloc(len + 1);
	if (!buf)
		return (NULL);
	while (j < len)
		buf[j++] = s[start++];
	buf[len] = 0;
	return (buf);
}