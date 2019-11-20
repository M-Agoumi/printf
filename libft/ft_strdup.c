/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strdup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magoumi <agoumihunter@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 18:14:12 by magoumi           #+#    #+#             */
/*   Updated: 2018/10/10 17:27:03 by magoumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s;
	int		i;

	i = -1;
	s = (char*)malloc(ft_strlen((char*)s1) + 1);
	if (s == NULL)
		return (0);
	while (s1[++i])
		s[i] = (char)(s1[i]);
	s[i] = '\0';
	return (s);
}
