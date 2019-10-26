/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magoumi <magoumi@1337.MA>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 17:14:07 by magoumi           #+#    #+#             */
/*   Updated: 2018/10/13 17:31:09 by magoumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *str;
	char *res;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	str = (char*)malloc(ft_strlen((char*)s1) + ft_strlen((char*)s2) + 1);
	if (str == NULL)
		return (NULL);
	res = str;
	while (*s1)
		*str++ = *s1++;
	while (*s2)
		*str++ = *s2++;
	*str = '\0';
	return (res);
}
