/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magoumi <magoumi@1337.MA>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 19:51:46 by magoumi           #+#    #+#             */
/*   Updated: 2018/10/14 19:58:14 by magoumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_whitespace(const char c)
{
	if (c == '\t' || c == '\n' || c == ' ')
		return (1);
	return (0);
}

char		*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	start;
	size_t	end;
	char	*str;

	if (s == NULL)
		return (NULL);
	i = 0;
	while (is_whitespace(s[i]))
		i++;
	if (s[i] == '\0')
		return ("\0");
	start = i;
	i = ft_strlen((char*)s) - 1;
	while (is_whitespace(s[i]))
		i--;
	end = i - start;
	str = ft_strsub(s, (unsigned int)start, end + 1);
	if (str == NULL)
		return (NULL);
	return (str);
}
