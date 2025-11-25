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

char	*ret_line(t_var s, char *buf)
{
	ft_memmove(s.left, buf, s.addr);
	ft_memmove(buf, s.addr + 1, s.tmp);
	ft_memmove(s.line + s.len, s.left, s.left + ft_strlen(s.left));
	return (s.line);
}

char	*get_next_line(int fd)
{
	static char	buf[OPEN_MAX][BUFFER_SIZE + 1];
	t_var		s;

	init(&s, buf[fd], fd);
	while (s.byte > 0)
	{
		if (s.cap < s.len + BUFFER_SIZE)
		{
			while (s.cap < s.len + BUFFER_SIZE)
				s.cap = s.cap << 1;
			s.tmp = s.line;
			s.line = malloc(s.cap);
			ft_memmove(s.line, s.tmp, s.tmp + s.len);
			free(s.tmp);
		}
		s.tmp = buf[fd] + BUFFER_SIZE - 1;
		s.addr = ft_strchr(buf[fd], 10, BUFFER_SIZE);
		if (s.addr)
			return (ret_line(s, buf[fd]));
		ft_memmove(s.line + s.len, buf[fd], s.tmp);
		s.byte = read(fd, buf[fd], BUFFER_SIZE);
		s.len += s.byte;
	}
	return (s.line);
}

int main()
{
	int fd = open("test.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));


}
//1234\n
//12345\n
//1234512345\n
