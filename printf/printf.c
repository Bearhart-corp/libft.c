/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbelard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 14:05:40 by tbelard           #+#    #+#             */
/*   Updated: 2025/11/07 14:05:42 by tbelard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>

/* 
Flags (-, 0, #, , +)

- commence par la gauche
0 zero filled si un - existe alors annule le 0
# prefix dadress pour x et X ignore si utilise avec c,d,i,u,s
SPACE ajoute juste un espace au lieu dun signe (+ ou -) si + cest ignore car en contradiction
+ force le signe a etre affiche uniquement le negatif -

Largeur minimale

valeur unsigned int qui defini la largeur min
si le contenue est plus petit que la width alors non pad a droite ou a gauche avec des 0 
si specifie, JAMAIS de tronc, seul la precision le fait, 

Précision

si . alors valeur unsigned int , si val  = 0 alors pas d'output

Conversion (d, s, x, etc.)

FORMAT = struct 4 char
avec 256posibilite pour la width et la precision
et 2 char pour les flags
*/

static size_t print_fmt(const char **fmt, va_list lst, t_flags *flags_struct)
{
	size_t	count;

	count = 0;
	if ((*flags_struct).conversion == 1)
	{
		count += ft_putstr_fd(va_arg(lst, char *), *flags_struct);
	}
	else if ((*flags_struct).conversion == 2)
		count += ft_putchar_fd((char)va_arg(lst, int), *flags_struct);
	else if ((*flags_struct).conversion > 2 && (*flags_struct).conversion < 8)
		count += ft_putnbr((unsigned long)va_arg(lst, void *), *flags_struct);
	else
	{
		count += ft_putfloat(va_arg(lst, double), *flags_struct);
		(*fmt)++;
	}
	return (count);
}

static size_t	conv(const char **fmt, va_list lst, t_flags *flags_struct)
{
	size_t	count;

	count = 0;
	if ((**fmt) == 's')
		(*flags_struct).conversion = 1;
	else if ((**fmt) == 'c')
		(*flags_struct).conversion = 2;
	else if ((**fmt) == 'p')
		(*flags_struct).conversion = 3;
	else if ((**fmt) == 'd' || (**fmt) == 'i')
		(*flags_struct).conversion = 4;
	else if ((**fmt) == 'u')
		(*flags_struct).conversion = 5;
	else if ((**fmt) == 'x')
		(*flags_struct).conversion = 6;
	else if ((**fmt) == 'X')
		(*flags_struct).conversion = 7;
	else if ((**fmt) == 'f' && *fmt++)
		(*flags_struct).conversion = 8;
	else if ((**fmt) == '%')
		return count += ft_putchar_fd('%', *flags_struct);
	count += print_fmt(fmt, lst, flags_struct);
	return (count);
}

static size_t	accuracyF(const char **fmt, va_list lst, t_flags *flags_struct)
{
	size_t	count;

	count = 0;
	if ((**fmt) == '.')
		(*fmt)++;
	else
		return (count += conv(fmt, lst, flags_struct));
	while (**fmt >= 48 && **fmt <= 57)
	{
		(*flags_struct).prec = (*flags_struct).prec * 10 + (**fmt - 48);
		(*fmt)++;
	}
	if ((*flags_struct).prec == 0)
		(*flags_struct).prec = 6;
	count += conv(fmt, lst, flags_struct);
	return (count);
}

static size_t	flag_pars(const char **fmt, va_list lst, t_flags *flags_struct)
{
	size_t	count;

	count = 0;
	while (**fmt == '-' || **fmt == '+' || **fmt == ' ' || **fmt == '#' 
		|| **fmt == '0')
	{
		if ((**fmt) == '-')
			(*flags_struct).flags |= START_LEFT;
		else if ((**fmt) == '0' && ((*flags_struct).flags & START_LEFT )!= 1)
			(*flags_struct).flags |= ZEROS;
		else if ((**fmt) == '#')
			(*flags_struct).flags |= HASH;
		else if ((**fmt) == '+')
			(*flags_struct).flags |= PLUS;
		else if ((**fmt) == ' ')
			(*flags_struct).flags |= SPACE;
		(*fmt)++;
	}
	while (**fmt >= 48 && **fmt <= 57)
			{
				(*flags_struct).width = (*flags_struct).width * 10 + (**fmt - 48);
				(*fmt)++;
			}
	return count += accuracyF(fmt, lst, flags_struct);
}

// n,base, upper, adress flag
int	ft_printf(const char (*fmt), ...)
{
	va_list	lst;
	size_t	count;
	t_flags	flags_struct;

	count = 0;
	
	va_start(lst, fmt);
	while (*fmt)
	{
		flags_struct.flags = 0;
		flags_struct.width = 0;
		flags_struct.prec = 0;
		flags_struct.conversion = 0;
		if ((*fmt) == '%' && ++fmt)
			count += flag_pars(&fmt, lst, &flags_struct);
		else
			count += ft_putchar_fd((*fmt), flags_struct);
		fmt++;
	}
	va_end(lst);
	return (count);
}


int main()
{
//	char s[] = "hi";
//	int count = ft_printf("test%s,%u, %.3f, %d", "Tomtom", -1, -17.123, -42);
//	ft_printf("\n%d", count);
printf("%-5s\n", "hi");
ft_printf("%-5s\n", "hi");
}/* 
Flags (-, 0, #, , +)

- commence par la gauche
0 zero filled si un - existe alors annule le 0
# prefix dadress pour x et X ignore si utilise avec c,d,i,u,s
SPACE si signed et positif pad avec espace> si + cest ignore
+ si negatif signed alors affiche le -

Largeur minimale

valeur unsigned int qui defini la largeur min
si le contenue est plus petit que la width alors non pad a droite ou a gauche avec des 0 
si specifie, JAMAIS de tronc, seul la precision le fait, 

Précision

si . alors valeur unsigned int , si val  = 0 alors pas d'output

Conversion (d, s, x, etc.)

FORMAT = struct 4 char
avec 256posibilite pour la width et la precision
et 2 char pour les flags
*/