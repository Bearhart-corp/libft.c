/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbelard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 12:48:26 by tbelard           #+#    #+#             */
/*   Updated: 2025/11/14 12:48:34 by tbelard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	helper_init(nbr *s, t_flags f, unsigned long n)
{
	if (f.conversion == PTR)
		(*s).prefix = "0x";
	else if ((*s).is_hex && (f.flags & HASH) && n != 0)
	{
		if ((*s).upper)
			(*s).prefix = "0X";
	}
	else
		(*s).prefix_len = 0;
	
	(*s).pad = f.width - (int)((*s).sign_len + (*s).n_digit);
	if ((*s).pad < 0)
		(*s).pad = 0;
	if (f.point)
	{
		if (f.prec > (int)s->n_digit)
			(*s).zero = (size_t)(f.prec - (int)(*s).n_digit);
		else
			(*s).zero = 0;
	}
}

void	init(t_flags *f)
{
	(*f).flags = 0;
	(*f).width = 0;
	(*f).prec = 0;
	(*f).conversion = 0;
	(*f).point = 0;
}

void	init_nbr(nbr *s, t_flags f, unsigned long n)
{
	(*s).zero = 0;
	(*s).count = 0;
	(*s).sign_len = 0;
	(*s).sign = 0;
	(*s).is_hex = (f.conversion == HEX_LOW 
		|| f.conversion == HEX_MAJ || f.conversion == PTR);
	(*s).upper = (f.conversion == (*s).is_hex);
	if (f.conversion == UNSIGNED)
		(*s).base = 10;
	else
		(*s).base = 16;
	(*s).is_left = (f.flags & START_LEFT);
	(*s).zero_pad_width = (f.flags & ZEROS) && !((*s).is_left);
	if ((*s).zero_pad_width)
		(*s).sym_pad = '0';
	else
		(*s).sym_pad = ' ';
	s->upper = (f.conversion == HEX_MAJ);
	(*s).prefix_len = 0;
	(*s).n_digit = h(n, (*s).base, (*s).buf, f);
	(*s).prefix_len = 2;
	helper_init(s, f, n);
}

void	init_nbr_int(nbr *s, t_flags f, int neg, long n)
{
	(*s).count = 0;
	(*s).z = 0;
	(*s).zero = 0;
	(*s).base = 10;
	(*s).sign_len = 1;
	(*s).sign = ' ';
	(*s).is_hex = 0;
	(*s).upper = 0;
	(*s).is_left = (f.flags & START_LEFT);
	(*s).zero_pad_width = (f.flags & ZEROS) && !((*s).is_left);
	(*s).n_digit = ft_putnbr_help(n, (*s).buf);
	(*s).prefix = 0;
	if ((*s).zero_pad_width)
		(*s).sym_pad = '0';
	else
		(*s).sym_pad = ' ';
	(*s).prefix_len = 0;
	if (neg)
		(*s).sign = '-';
	else if (f.flags & PLUS)
		(*s).sign = '+';
	else if (f.flags & SPACE)
		(*s).sign = ' ';
	else
		(*s).sign_len = 0;
	(*s).pad = f.width - (int)((*s).sign_len + (*s).n_digit);
	if ((*s).pad < 0)
		(*s).pad = 0;
}

/*
printf("c:%zu\n n_d:%zu\n pre:%zu\n s_len:%zu\n", s.count, s.n_digit, s.prefix_len, s.sign_len);
printf("sign:%c\n, prefix: %s\n, pad: %d\n, base; %d\n, upper: %d\n, hex: %d\n",s.sign, s.prefix,s.pad, s.base, s.upper, s.is_hex);
printf("left: %d\n, zeropaas : %d \n, z: %d\n, zero: %d\n",s.is_left, s.zero_pad_width, s.z , s.zero );
*/

/* 
famille de bug: 

1/le signe pas colle au nombre mais au pad...
2/le prefix_len pas compter dans lensemble  :
 Expected: [                0x7fff454b4b7f], return: 30
 Got:      [              0x7fff454b4b7f], return: 28
3/le cas ou la precision est inferieur a la taille totale de (null)
Expected: [], return: 0
Got:      [(null], return: 5
4/ajout de padding avec 0 pour les entier si la width > n_digit
Expected: [03], return: 2
Got:      [3], return: 1
CELA EXCLU LES SIGNE_LEN
 Expected: [-01234], return: 6
 Got:      [-1234], return: 5
5/LA PRECISION doit faire de meme
 Expected: [02147483647], return: 11
 Got:      [2147483647], return: 10
6/si .0 alors naffiche rien du tout meme pas 0 (cas particulier)
Expected: [], return: 0
Got:      [0], return: 1
PAREIL pour %.i, 0 
 Expected: [], return: 0
 Got:      [0], return: 1
7/fonctionne pareil avec les unsigned apparemment
Expected: [01], return: 2
Got:      [1], return: 1
ex:  ft_printf("%.2u", 1);
REMPLI par default de 0
8/
   Expected: [that's the way it 0x5b9cd4            is], return: 40
        Got:      [that's the way it 0x5b9cd4          is], return: 38
     You can rerun this test with sh test 449
     The function was called like this:
   ft_printf("that's the way it %-20pis", "");

inclu bien ton prefix_len sinon ca decal de 2 normal...

9/
459.KO (Wrong output) (Wrong return)
        Expected: [-10], return: 3
        Got:      [10], return: 2
     You can rerun this test with sh test 459
     The function was called like this:
   ft_printf("%-d", -10);

oublie le sign stp frero

10/
496.KO (Wrong output)
        Expected: [          ], return: 10
        Got:      [0         ], return: 10
     You can rerun this test with sh test 496
     The function was called like this:
   ft_printf("%-10.d", 0);

   SI WIDTH mais pas de PRECISION alors on affiche que le padding

11/
 498.KO (Wrong output)
        Expected: [00010     ], return: 10
        Got:      [10        ], return: 10
     You can rerun this test with sh test 498
     The function was called like this:
   ft_printf("%-10.5d", 10);
REGARDE !!

12/

      Expected: [ ], return: 1
        Got:      [0], return: 1
     You can rerun this test with sh test 780
     The function was called like this:
   ft_printf("%01.d", 0);

   celui la est violent

   0 | width = 1 | prec = 0 | entier | val = 0
   la width sur les entier est donc a ' ' si pas de precision (je crois)

	Si IL Y A DE LA PRECISION

	   Expected: [000], return: 3
        Got:      [0], return: 1
     You can rerun this test with sh test 786
     The function was called like this:
   ft_printf("%01.3d", 0);

	CA REMPLI DE 0, donc comme les prec agit sur les nombres et pas la width
	ca rempli de nombre sans valeurs que si prec le premet
	sinon cest la wifth mini qui lemporte avec le print de ' '
	la precision bat la width car elle est la largeur MINIMALE !!
13/



*/