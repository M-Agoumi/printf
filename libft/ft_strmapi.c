/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magoumi <magoumi@1337.MA>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 00:40:59 by magoumi           #+#    #+#             */
/*   Updated: 2018/10/13 15:59:45 by magoumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	int		i;

	str = NULL;
	if (s && f)
	{
		i = -1;
		str = (char *)malloc(ft_strlen((char *)s) + 1);
		if (str == NULL)
			return (NULL);
		while (s[++i])
			str[i] = f(i, s[i]);
		str[i] = '\0';
	}
	return (str);
}
