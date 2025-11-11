/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbelard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 12:55:27 by tbelard           #+#    #+#             */
/*   Updated: 2025/10/27 12:55:28 by tbelard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*der;

	i = 0;
	der = NULL;
	while (1)
	{
		if (s[i] == (char)c)
			der = ((char *)s + i);
		if (!s[i])
		{
			if (s[i] == (char)c)
				der = ((char *)s + i);
			break ;
		}
		i++;
	}
	return (der);
}

/*
int main()
{
	char s[] = "hello";
	char *p = ft_strrchr(s, 'h');
	printf("%p\n", s);
	printf("%p\n", p);
	//on cherche dans la string jusqua 0 puis a 0 puis on break 
}*/