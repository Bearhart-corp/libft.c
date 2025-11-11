/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbelard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 13:06:00 by tbelard           #+#    #+#             */
/*   Updated: 2025/10/27 13:06:02 by tbelard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	char	*buf;
	int		end;
	int		k;

	if (!set)
		return ((char *)s1);
	if (!s1 || !set)
		return (NULL);
	start = 0;
	k = 0;
	end = ft_strlen(s1) - 1;
	while (ft_strchr(set, s1[start]) != 0 && s1[start])
		start++;
	while (ft_strchr(set, s1[end]) != 0 && (end > start))
		end--;
	buf = malloc((end - start) + 2);
	if (!buf)
		return (NULL);
	while (start <= end)
		buf[k++] = s1[start++];
	buf[k] = 0;
	return (buf);
}

/*
int main()
{
	char *s =ft_strtrim(NULL, "ABC");
	printf("%s\n", s);
	//free(s);
}*/