/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbelard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 11:40:43 by tbelard           #+#    #+#             */
/*   Updated: 2025/10/30 11:40:58 by tbelard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*buf;

	buf = malloc(sizeof(t_list));
	if (!buf)
		return (NULL);
	buf->content = content;
	buf->next = NULL;
	return (buf);
}

/*
int main()
{
	t_list *nom = ft_lstnew(&"yolooo");
	printf("%s\n", (char *)nom->content);
	free(nom);
}*/