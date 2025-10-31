/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbelard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 13:07:24 by tbelard           #+#    #+#             */
/*   Updated: 2025/10/27 13:07:26 by tbelard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*buf;

	if (!s || !f)
		return (NULL);
	i = 0;
	buf = malloc(ft_strlen(s) + 1);
	if (!buf)
		return (NULL);
	while (s[i])
	{
		buf[i] = f(i, s[i]);
		i++;
	}
	buf[i] = 0;
	return (buf);
}
