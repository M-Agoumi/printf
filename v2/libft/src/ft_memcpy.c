/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magoumi <magoumi@1337.MA>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 04:17:15 by magoumi           #+#    #+#             */
/*   Updated: 2018/10/19 23:34:05 by magoumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char *s;

	s = dst;
	while (n--)
	{
		*((unsigned char*)dst) = *((unsigned char*)src);
		src++;
		dst++;
	}
	return (s);
}
