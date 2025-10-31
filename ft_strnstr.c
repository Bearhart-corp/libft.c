/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbelard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 12:56:23 by tbelard           #+#    #+#             */
/*   Updated: 2025/10/27 12:56:25 by tbelard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	long unsigned int	i;
	long unsigned int	j;
	size_t				size_l;

	size_l = ft_strlen(little);
	if (!(*little))
		return ((char *)big);
	j = 0;
	while (*big && j < len)
	{
		i = 0;
		while (big[i] == little[i] && (j + i) < len && big[i])
			i++;
		if (i == size_l)
			return ((char *)big);
		big++;
		j++;
	}
	return (NULL);
}

/*
int main()
{
	const char s[] = "12a3a123";
	const char *p = ft_strnstr(s, "3a", 4);
	printf("%p\n", s);
	printf("%p\n", p);
}
*/