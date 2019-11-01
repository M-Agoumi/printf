/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magoumi <magoumi@1337.MA>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 04:17:15 by magoumi           #+#    #+#             */
/*   Updated: 2018/10/20 05:53:36 by magoumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*a;
	unsigned char	*b;

	i = 0;
	a = (unsigned char*)src;
	b = (unsigned char*)dst;
	while (i < n)
	{
		b[i] = a[i];
		if (a[i] == (unsigned char)c)
			return ((unsigned char*)&(dst[i + 1]));
		i++;
	}
	return (NULL);
}
