/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbelard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 13:08:56 by tbelard           #+#    #+#             */
/*   Updated: 2025/10/27 13:08:58 by tbelard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	nb;
	char	tmp;

	nb = n;
	if (nb < 0)
	{
		nb = -(long)n;
		write(fd, "-", 1);
	}
	if (nb < 10)
	{
		tmp = nb + '0';
		write(fd, &tmp, 1);
		return ;
	}
	ft_putnbr_fd(nb / 10, fd);
	tmp = (nb % 10) + '0';
	write(fd, &tmp, 1);
}

/*
int main()
{
	ft_putnbr_fd(0, 1);
}*/