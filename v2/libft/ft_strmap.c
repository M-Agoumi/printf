/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magoumi <magoumi@1337.MA>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 00:40:41 by magoumi           #+#    #+#             */
/*   Updated: 2018/10/13 16:01:32 by magoumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char *str;
	char *result;

	str = NULL;
	result = NULL;
	if (s && f)
	{
		str = (char *)malloc(ft_strlen((char *)s) + 1);
		if (str == NULL)
			return (NULL);
		result = str;
		while (*s)
			*str++ = f(*s++);
		*str = '\0';
	}
	return (result);
}
