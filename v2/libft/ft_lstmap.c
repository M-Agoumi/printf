/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magoumi <magoumi@1337.MA>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 22:18:26 by magoumi           #+#    #+#             */
/*   Updated: 2018/10/25 11:00:09 by magoumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*s;
	t_list	*ds;
	int		i;

	ds = 0;
	i = 0;
	if (!(s = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	while (lst)
	{
		if (!(s->next = f(lst)))
			return (NULL);
		if (i == 0)
			ds = s->next;
		s = s->next;
		lst = lst->next;
		i++;
	}
	return (ds);
}
