/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strnstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magoumi <agoumihunter@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 18:22:04 by magoumi           #+#    #+#             */
/*   Updated: 2018/10/29 13:45:35 by magoumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t a;
	size_t b;
	size_t l;

	a = 0;
	if (to_find[a] == '\0')
		return ((char*)str);
	while (str[a] != '\0' && len--)
	{
		b = 0;
		l = len;
		if (str[a] == to_find[b])
		{
			while (to_find[b] != '\0' && to_find[b] == str[a + b] && l-- + 1)
				b++;
			if (to_find[b] == '\0')
				return ((char*)&str[a]);
		}
		a++;
	}
	return (0);
}
