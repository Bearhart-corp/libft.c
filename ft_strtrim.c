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

static int	is_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static int	alloc(char const *s1, char const *set)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[i + j])
	{
		if (!is_set(s1[i + j], set))
			i++;
		else
			j++;
	}
	return (i + 1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t		i;
	char		*buf;
	int			j;

	buf = malloc(alloc(s1, set));
	i = 0;
	j = 0;
	while (s1[i])
	{
		if (!is_set(s1[i], set))
		{
			buf[j] = s1[i];
			j++;
		}
		i++;
	}
	buf[j] = 0;
	return (buf);
}

/*
int main()
{
	char *s =ft_strtrim("hello", "");
	printf("%s\n", s);
	free(s);
}*/