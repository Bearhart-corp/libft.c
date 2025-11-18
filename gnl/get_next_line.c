/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbelard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 15:50:39 by tbelard           #+#    #+#             */
/*   Updated: 2025/11/18 15:50:41 by tbelard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}
 /*
char	*ft_strdup(char *s);
char	*ft_strchr(char *s, int c);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
char	*ft_substr(char *s, unsigned int start, size_t len);
void	*ft_calloc(size_t nmemb, size_t size);
size_t	ft_strlen(char *s);
*/

# define BUF_SIZE 5

char *get_next_line(int fd)
{
	static char buf[BUF_SIZE];
	char		*line;
	char		*left;
	ssize_t 	count;

	count = BUF_SIZE;
	line = malloc(10000);
	while (count > 0)
	{
		count = read(fd, buf, BUF_SIZE);
		if (ft_strchr(buf, 10) != 0)
		{
			ft_strlcat(line, buf ,ft_strchr(buf, 10) - buf);
			//on ajoute a line le buf jusquau \n !! attention au \0 du coup..
			break ;
		}
		ft_strlcat(line, buf,BUF_SIZE);
	}

	return (line);
}

int main()
{
	int fd;
	fd = open("test.txt", O_RDONLY);
	char *s = get_next_line(fd);
	printf("%s\n", s);
}
