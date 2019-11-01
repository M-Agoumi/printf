/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strcat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magoumi <agoumihunter@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 02:23:24 by magoumi           #+#    #+#             */
/*   Updated: 2018/10/09 17:33:47 by magoumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	int cn;
	int len;

	len = ft_strlen(dest);
	cn = 0;
	while (src[cn] != '\0')
	{
		dest[len] = src[cn];
		cn++;
		len++;
	}
	dest[len] = '\0';
	return (dest);
}
