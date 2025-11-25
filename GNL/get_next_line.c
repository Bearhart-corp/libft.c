/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_s.line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbelard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 12:58:25 by tbelard           #+#    #+#             */
/*   Updated: 2025/11/25 12:58:27 by tbelard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	refill(int fd, t_var *s, char *buf)
{
	if (s->byte != 0)
		return (1);
	s->byte = read(fd, buf, BUFFER_SIZE);
	if (s->byte <= 0)
		return (0);
	buf[s->byte] = '\0';
	return (1);
}

static int	consume_buf(t_var *s, char *buf)
{
	s->i = 0;
	while (s->i < s->byte && buf[s->i] != '\n')
		s->i++;
	if (!ensure_cap(s))
		return (-1);
	if (s->i == s->byte)
	{
		ft_memmove(s->line + s->len, buf, s->byte);
		s->len += s->byte;
		s->line[s->len] = '\0';
		s->byte = 0;
		buf[0] = '\0';
		return (0);
	}
	//a trouvé un \n
	ft_memmove(s->line + s->len, buf, s->i + 1);//left
	s->len += s->i + 1;
	s->line[s->len] = '\0';
	s->byte -= s->i + 1; // equ de buffer size - index de \n + 1
	ft_memmove(buf, buf + s->i + 1, s->byte);
	buf[s->byte] = '\0';
	return (1);
}

char	*get_next_line(int fd)
{
	static char	buf[OPEN_MAX][BUFFER_SIZE + 1];
	t_var		s;
	int			r;

	if (fd < 0 || fd >= OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	init(&s, buf[fd]);
	if (!s.line || s.byte < 0)
		return (NULL);
	while (1)
	{
		if (!refill(fd, &s, buf[fd]))
			break ;
		r = consume_buf(&s, buf[fd]);
		if (r == 1)
			return (s.line);
		if (r < 0)
			return (free(s.line), NULL);
	}
	if (s.len == 0)
		return (free(s.line), NULL);
	s.line[s.len] = '\0';
	return (s.line);
}



int main()
{
	char *line;
	int fd = open("test.txt", O_RDONLY);
	while ((line = get_next_line(fd)) != 0)
		printf("%s", line);
}

