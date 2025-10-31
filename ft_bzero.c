/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbelard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 12:52:21 by tbelard           #+#    #+#             */
/*   Updated: 2025/10/27 12:52:26 by tbelard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_bzero(void *pointer, size_t size)
{
	unsigned char	*p;

	p = (unsigned char *)pointer;
	while (size--)
		p[size] = 0;
	return (p);
}
