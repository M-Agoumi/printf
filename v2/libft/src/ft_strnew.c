/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magoumi <magoumi@1337.MA>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 19:22:23 by magoumi           #+#    #+#             */
/*   Updated: 2018/10/12 19:51:43 by magoumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*str;
	size_t	i;

	str = malloc(size * sizeof(char) + 1);
	if (str == NULL)
		return (NULL);
	i = -1;
	while (++i <= size)
		str[i] = '\0';
	return (str);
}
