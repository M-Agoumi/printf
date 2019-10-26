/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magoumi <agoumihunter@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 02:51:03 by magoumi           #+#    #+#             */
/*   Updated: 2018/10/22 11:42:31 by magoumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t	len;
	size_t	j;

	j = 0;
	len = ft_strlen(dst);
	if (n <= len)
		return (n + ft_strlen(src));
	while (src[j] && j < n - len - 1)
	{
		dst[len + j] = src[j];
		j++;
	}
	dst[len + j] = 0;
	return (len + ft_strlen(src));
}
