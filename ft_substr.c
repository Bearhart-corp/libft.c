/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbelard <tbelard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 13:05:15 by tbelard           #+#    #+#             */
/*   Updated: 2025/11/04 10:09:58 by tbelard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
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

/*
int main()
{
	char *s = ft_substr("Hello", 10, 5);
	printf("%s\n",s );
}*/