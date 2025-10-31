/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbelard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 13:06:27 by tbelard           #+#    #+#             */
/*   Updated: 2025/10/27 13:06:28 by tbelard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	long	nb;
	int		i;
	char	*res;
	int		sign;
	long	temp;

	i = (n == 0);
	sign = (n < 0);
	nb = n;
	if (nb < 0)
		nb = -(long)n;
	temp = nb;
	while (temp > 0 && ++i)
		temp = temp / 10;
	res = malloc ((i + 1 + sign) * sizeof(char));
	res[i + sign] = 0;
	while (i-- > 0)
	{
		res[i + sign] = "0123456789"[nb % 10];
		nb = nb / 10;
	}
	if (sign)
		res[0] = '-';
	return (res);
}

/*
int main()
{
	char *s = ft_itoa(2147483647);
	printf("%s\n", s);
	free(s);
}*/