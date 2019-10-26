/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strschr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magoumi <magoumi@1337.MA>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 18:59:55 by magoumi           #+#    #+#             */
/*   Updated: 2018/10/18 19:08:24 by magoumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*tmp;
	int		find;

	find = 0;
	while (*s)
	{
		if (*s == (const char)c)
		{
			find = 1;
			tmp = (char *)s;
		}
		s++;
	}
	if (find)
		return (tmp);
	if (c == '\0')
		return ((char*)s);
	return (NULL);
}
