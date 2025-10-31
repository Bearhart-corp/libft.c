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
#include <stdio.h>

char	*ft_strchr(const char *string, int searchedChar)
{
	int	i;

	i = -1;
	while (string[++i])
	{
		if (string[i] == (char)searchedChar)
			return ((char *)string + i);
	}
	if (string[i] == (char)searchedChar && !string[i])
		return ((char *)string + i);
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