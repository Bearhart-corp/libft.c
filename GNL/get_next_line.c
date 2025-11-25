/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbelard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 12:58:25 by tbelard           #+#    #+#             */
/*   Updated: 2025/11/25 12:58:27 by tbelard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buf[OPEN_MAX][BUFFER_SIZE + 1];
	char		left[BUFFER_SIZE + 1];
	char		*tmp;
	char		*line;
	size_t		len;
	size_t		cap;
	ssize_t		byte;

	cap = BUFFER_SIZE + 1;
	len = 0;
	line = malloc(cap);
	if (*buf[fd])
		len = ft_strlen(ft_memmove(line, buf[fd], ft_strchr(buf[fd], 0)));
	byte = read(fd, buf[fd], BUFFER_SIZE);
	while (byte > 0)
	{
		if (cap < len + BUFFER_SIZE)
		{
			while (cap < len + BUFFER_SIZE)
				cap = cap << 1;
			tmp = line;
			line = malloc(cap);
			ft_memmove(line, tmp, tmp + len + 1);
		}
		if (ft_strchr(buf[fd], 10))
		{
			ft_memmove(left, buf[fd], ft_strchr(buf[fd], 10));
			ft_memmove(buf[fd], ft_strchr(buf[fd], 10), &buf[fd][BUFFER_SIZE - 1]);
			ft_memmove(line + len, left, left + BUFFER_SIZE - 1);
			return (line);
		}
		ft_memmove(line + len, buf[fd], buf[fd] + BUFFER_SIZE - 1);
		len += byte;
	}
	return (line);
}
int main()
{
	int fd = open("test.txt", O_RDONLY);
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
}
