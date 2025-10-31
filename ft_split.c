/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbelard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 13:06:12 by tbelard           #+#    #+#             */
/*   Updated: 2025/10/27 13:06:14 by tbelard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_w(char const *s, char c)
{
	int	i;
	int	flag;
	int	count;

	i = 0;
	flag = 1;
	count = 0;
	while (s[i])
	{
		if (s[i] == c)
			flag = 1;
		else if (flag)
		{
			count++;
			flag = 0;
		}
		i++;
	}
	return (count);
}

static void	free_split(char **buf, size_t *k)
{
	while (*k > 0)
		free(buf[--(*k)]);
	free(buf);
}

static int	helper(char const *s, char c, size_t *k, char **buf)
{
	int		j;
	int		l;

	while (*s)
	{
		l = -1;
		j = 0;
		while (*s && *s == c)
			s++;
		while (s[j] && s[j] != c)
			j++;
		buf[*k] = malloc(j + 1);
		if (!buf[*k])
		{
			free_split(buf, k);
			return (1);
		}
		while (++l < j)
			buf[*k][l] = s[l];
		s = s + j;
		buf[(*k)++][l] = 0;
	}
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char		**buf;
	size_t		k;

	k = 0;
	buf = malloc((count_w(s, c) + 1) * sizeof(char *));
	if (!buf)
		return (NULL);
	if (helper(s, c, &k, buf))
		return (NULL);
	else
		buf[k] = NULL;
	return (buf);
}

/*
int main()
{
	char const s[] = "  ta maman la chauve   ";
	char **chauve = ft_split(s, ' ');
	int i = 0;
	if (!chauve)
	{
		printf("ca a bien clean");
		return 0;
	}
	while(chauve[i])
	{
		printf("%s\n", chauve[i]);
		free(chauve[i]);
		i++;
	}
	free(chauve);
	return 0;
}*/