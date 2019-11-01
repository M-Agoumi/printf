/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magoumi <magoumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 08:49:54 by magoumi           #+#    #+#             */
/*   Updated: 2019/03/27 08:58:46 by magoumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_strrev(const char *str)
{
	size_t	len;
	char	*rev;
	size_t	i;

	len = ft_strlen(str);
	rev = (char *)malloc(len + 1);
	i = 0;
	while (i < len)
	{
		rev[i] = str[len - i - 1];
		i++;
	}
	rev[i] = '\0';
	return (rev);
}
