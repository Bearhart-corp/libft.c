/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbelard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 12:54:36 by tbelard           #+#    #+#             */
/*   Updated: 2025/10/27 12:54:38 by tbelard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

/*
int main()
{
	char s[] = "hello";
	char *p = ft_strchr(s, 0);
	printf("%p\n", s);
	printf("%p\n", p);
}*/