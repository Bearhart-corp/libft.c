/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbelard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 13:05:15 by tbelard           #+#    #+#             */
/*   Updated: 2025/10/27 13:05:17 by tbelard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*buf;
	size_t	j;
	size_t	verif;

	verif = ft_strlen(s);
	j = 0;
	if (len == 0 || start >= verif)
	{
		buf = malloc(1);
		*buf = 0;
		return (buf);
	}
	if (start + len > verif)
		len = verif - start;
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