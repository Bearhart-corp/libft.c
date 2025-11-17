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

size_t  ft_putstr_fd(char *s, t_flags f)
{
    int  t[3];

    t[COUNT] = 0;
    t[LEN] = 0;
    t[PAD] = 0;
    if (!s)
    {
        s = "(null)";
         if (!(f.point && f.prec < 6))
			t[LEN] = 6;
    }
    else
    	t[LEN] = ft_strlen(s);
    if (f.point && (f.prec < (int)t[LEN]))
		t[LEN] = (size_t)f.prec;
    if (f.width > (size_t)t[LEN])
    	t[PAD] = ft_max(f.width, t[LEN]);
    if (!(f.flags & START_LEFT))// alignement droit
        while (t[PAD]-- > t[LEN])
        	t[COUNT] += write(1, " ", 1);
    t[COUNT] += write(1, s, t[LEN]);
    if (f.flags & START_LEFT)// alignement gauche
        while (t[PAD]-- > t[LEN])
        	t[COUNT] += write(1, " ", 1);
    return ((size_t)t[COUNT]);
}

/*1010 / 3 (*,/,-)

sum = 0;
	sum =+ n >> 2 
	n = sum + (n & 3)
*/