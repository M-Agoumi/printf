/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magoumi <magoumi@1337.MA>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 02:03:19 by magoumi           #+#    #+#             */
/*   Updated: 2018/10/12 18:49:35 by magoumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*mem;
	size_t	i;

	mem = malloc(size);
	if (!mem)
		return (NULL);
	i = 0;
	while (i < size)
		*((unsigned char*)mem + i++) = 0;
	return (mem);
}
