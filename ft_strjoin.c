/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbelard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 13:05:30 by tbelard           #+#    #+#             */
/*   Updated: 2025/10/27 13:05:32 by tbelard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*buf;
	int		i;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	buf = malloc(s1_len + s2_len + 1);
	i = 0;
	while (*s1)
	{
		buf[i] = *s1;
		i++;
		s1++;
	}
	while (*s2)
	{
		buf[i] = *s2;
		i++;
		s2++;
	}
	buf[i] = 0;
	return (buf);
}

/*
int main()
{
	char *s = ft_strjoin("", "");
	printf("%s\n",s );
	free(s);
}*/