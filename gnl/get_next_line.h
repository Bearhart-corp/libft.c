/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbelard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 15:50:49 by tbelard           #+#    #+#             */
/*   Updated: 2025/11/18 15:50:51 by tbelard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

# define SIZE_MAX 0xfffffffffffffff

char	*ft_strdup(char *s);
char	*ft_strchr(char *s, int c);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
char	*ft_substr(char *s, unsigned int start, size_t len);
void	*ft_calloc(size_t nmemb, size_t size);
size_t	ft_strlen(char *s);

#endif
