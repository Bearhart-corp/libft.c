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

#include "ft_printf.h"

static int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

size_t	ft_putnbr(long n, t_flags f)
{
	nbr		s;
	int		neg;
	int		pad_prec;

	neg = (n < 0);
	if (neg)
		n = -n;
	init_nbr_int(&s, f, neg, n);
	ft_putnbr_help(n, s.buf, f);
	if (f.point && f.prec == 0 && n == 0)
		s.n_digit = 0;
	pad_prec = ft_max(f.prec , s.n_digit);
	s.z = f.width - (int)(s.sign_len + pad_prec);
	if (s.z < 0)
		s.z = 0;
	if (f.flags & ZEROS && !(f.point))
		s.count += write(1, &s.sign, s.sign_len);
	if (!(s.is_left))
		while (s.z--)
			s.count += write(1, &s.sym_pad, 1);
	if (!(f.flags & ZEROS) || f.point)
		s.count += write(1, &s.sign, s.sign_len);
	while (f.point && pad_prec-- > (int)s.n_digit)
		s.count += write(1, "0", 1);
	s.count += write(1, s.buf, s.n_digit);
	if (s.is_left && s.z > 0)
		while (s.z--)
			s.count += write(1, " ", 1);
	return (s.count);
}
/*
printf("c:%zu\n n_d:%zu\n pre:%zu\n s_len:%zu\n", s.count, s.n_digit, s.prefix_len, s.sign_len);
printf("sign:%c\n, prefix: %s\n, pad: %d\n, base; %d\n, upper: %d\n, hex: %d\n",s.sign, s.prefix,s.pad, s.base, s.upper, s.is_hex);
printf("left: %d\n, zeropaas : %d \n, z: %d\n, zero: %d\n",s.is_left, s.zero_pad_width, s.z , s.zero );
*/

/*

	ACTUELLEMENT: si . pad_preci = prec - n_digits genre (0042) prec = 4 - 2 donc 00 a add
	sinon pas de pad prec.

	WIDTH = width - (sign_len + n_digit + son pad prec si existe)
	si width = neg alors width = 0.

	si ne commence pas a gauche consomme la width min et on ecrit le sym pad
	puis le sign
	puis on consomme le pad de la preci en mettant des 0
	puis on ecrit n_digits

765.KO (Wrong output)
        Expected: [-0000000000000042000], return: 20
        Got:      [00000000000000-42000], return: 20
     You can rerun this test with sh test 765
     The function was called like this:
   ft_printf("%020d", -42000);
 156.KO (Wrong output)
        Expected: [              -42000], return: 20
        Got:      [-              42000], return: 20
     You can rerun this test with sh test 156
     The function was called like this:
   ft_printf("%20d", -42000);


*/


/* 

 1/si n = 0 && f.point && f.prec == 0 pour entier
 
 X2/donc n != 0 precision ignore

 X3/si f.point && f.width && f.prec = 0 alors space et pas 0 en padding (cas particulier)

 4/le - doit donc diparaitre aussi si 1/ est vrai

 5/si flag 0 et n < 0 alors le sign doit apparaitre avant le paddind (sign, pad, nbr)
 le sign fait partie de la width, pas de la precision !

 6/si . alors 0 desactive

 7/"%020.19d", 8000 : 20width et 19 de prec avec donc un pad toujours en 0 mais comme
 prec il y a, alors le pad de la width est en space pas en 0.

 8/"%042.20u", 42000 (largeur 42, précision 20) devrait donner 22 espaces + 20 chiffres 
 = 42 caractères, donc largeur -= precision et comme f.prec alors width en space
 et pas width -= n_digit seulement ENFAITE CEST MEME WIDTH -= N_DIGIT FORMATER AVEC LES 0
 SI IL Y A !

*/