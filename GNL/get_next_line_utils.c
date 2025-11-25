/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbelard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 15:51:02 by tbelard           #+#    #+#             */
/*   Updated: 2025/11/18 15:51:03 by tbelard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	init(t_var *s, char *buf_fd)
{
	s->cap = BUFFER_SIZE + 1;
	s->line = malloc(s->cap);
	if (!s->line)
	{
		s->cap = 0;
		s->len = 0;
		s->byte = -1;
		return ;
	}
	s->len = 0;
	s->i = 0;
	s->byte = (ssize_t)ft_strlen(buf_fd);
}

int	ensure_cap(t_var *s)
{
	char	*new_line;

	if (s->cap >= s->len + BUFFER_SIZE + 1)
		return (1);
	while (s->cap < s->len + BUFFER_SIZE + 1)
		s->cap <<= 1;
	new_line = s->line;
	s->line = malloc(s->cap);
	if (!s->line)
		return (0);
	ft_memmove(s->line, new_line, s->len);
	free(new_line);
	return (1);
}


size_t	ft_strlen(const char *s)
{
	size_t	len;

	if (!s)
		return (0);
	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_strchr(const char *s, int c, size_t n)
{
	int	i;

	i = -1;
	while (s[++i] && n--)
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
	}
	if (s[i] == (char)c && !s[i])
		return ((char *)s + i);
	return (NULL);
}

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	if (!n || dst == src)
		return (dst);
	d = (unsigned char *)dst;
	s = (const unsigned char *)src;
	if (d < s)
		while (n--)
			*d++ = *s++;
	else
		while (n--)
			d[n] = s[n];
	return (dst);
}

void	*fast_memmove(void *dst, void *src, size_t n)
{
    if (!n || dst == src)
		return (dst);
    if (dst < src)
    {
        while (n-- && ((uintptr_t)dst & 0b111))
			*(uint8_t *)dst++ = *(uint8_t *)src++;
        while (n >= 8)
        {
            n -= 8;
            *(uint64_t *)dst++ = *(uint64_t *)src++;
        }
        while (n--)
            *(uint8_t *)dst++ = *(uint8_t *)src++;
    }
    else
    {
        while (n-- && ((uintptr_t)dst & 0b111))
			*(uint8_t *)(dst + n) = *(uint8_t *)(src + n);
        while (n >= 8)
        {
            n -= 8;
            *(uint64_t *)(dst + n) = *(uint64_t *)(src + n);
        }
        while (n--)
            *(uint8_t *)(dst + n) = *(uint8_t *)(src + n);
    }
    return (dst);
}
 /*#include <immintrin.h>

void *ft_memcpy_avx2(void *dst, const void *src, size_t n)
{
    unsigned char *d = dst;
    const unsigned char *s = src;

    while (n >= 32)
    {
        __m256i chunk = _mm256_loadu_si256((__m256i*)s);
        _mm256_storeu_si256((__m256i*)d, chunk);
        s += 32;
        d += 32;
        n -= 32;
    }
    while (n--)
        *d++ = *s++;
    return dst;
}
*/
