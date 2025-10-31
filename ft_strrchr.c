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
#include <stdio.h>

char	*ft_strrchr(const char *string, int searchedChar)
{
	int	i;

	i = ft_strlen(string);
	if (string[i] == (char)searchedChar && !string[i])
		return ((char *)string + i);
	while (string[--i])
	{
		if (string[i] == (char)searchedChar)
			return ((char *)string + i);
	}
	return (NULL);
}

/*
int main()
{
	char s[] = "12a3a123";
	char *p = ft_strrchr(s, 0);
	printf("%p\n", s);
	printf("%p\n", p);
}*/