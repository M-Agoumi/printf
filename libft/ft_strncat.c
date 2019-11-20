/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strncat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magoumi <agoumihunter@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 02:51:03 by magoumi           #+#    #+#             */
/*   Updated: 2018/10/09 17:32:31 by magoumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	int len;
	int cn;

	cn = 0;
	len = ft_strlen(dest);
	while (src[cn] != '\0' && cn < (int)n)
	{
		dest[len] = src[cn];
		len++;
		cn++;
	}
	dest[len] = '\0';
	return (dest);
}
