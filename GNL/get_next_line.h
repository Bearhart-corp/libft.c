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
#include <stdint.h>

# define BUFFER_SIZE 5
# define OPEN_MAX 1024

typedef struct s_var
{
	char	*line;
	size_t	len;
	size_t	cap;
	ssize_t	byte;
	ssize_t	i;
}	t_var;

size_t	ft_strlen(const char *s);
void	*ft_memmove(void *dst, const void *src, size_t n);

void	init(t_var *s, char *buf_fd);
int		ensure_cap(t_var *s);

char	*get_next_line(int fd);

#endif
