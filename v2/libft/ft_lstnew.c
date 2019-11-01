/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magoumi <magoumi@1337.MA>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 23:02:32 by magoumi           #+#    #+#             */
/*   Updated: 2018/10/22 00:39:57 by magoumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *s;

	if (NULL == (s = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (content == NULL)
	{
		s->content = NULL;
		s->content_size = 0;
	}
	else
	{
		if (NULL == (s->content = (void*)malloc(content_size)))
			return (NULL);
		ft_memcpy(s->content, content, content_size);
		s->content_size = content_size;
	}
	s->next = NULL;
	return (s);
}
