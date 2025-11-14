/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbelard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 13:08:22 by tbelard           #+#    #+#             */
/*   Updated: 2025/10/27 13:08:23 by tbelard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

# define COUNT 0
# define LEN 1
# define PAD 2

size_t  ft_putstr_fd(char *s, t_flags f)
{
    size_t  t[3];

    t[COUNT] = 0;
    if (!s)
        s = "(null)";
    t[LEN] = ft_strlen(s);
    if (f.point)
    	if (f.prec < (int)t[LEN])
			t[LEN] = (size_t)f.prec;
    if (f.width > t[LEN])
    	t[PAD] = (size_t)(f.width - t[LEN]);
    else
    	t[PAD] = 0;
    if (!(f.flags & START_LEFT))// alignement droit
        while (t[PAD]--)
        	t[COUNT] += write(1, " ", 1);
    t[COUNT] += write(1, s, t[LEN]);
    if (f.flags & START_LEFT)// alignement gauche
        while (t[PAD]--)
        	t[COUNT] += write(1, " ", 1);
    return (t[COUNT]);
}

/*1010 / 3 (*,/,-)

sum = 0;
	sum =+ n >> 2 
	n = sum + (n & 3)
*/