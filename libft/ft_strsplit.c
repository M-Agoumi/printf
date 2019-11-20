/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magoumi <magoumi@1337.MA>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 10:30:01 by magoumi           #+#    #+#             */
/*   Updated: 2018/10/26 00:22:22 by magoumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_counter(const char *s, char c)
{
	int i;
	int j;
	int ch;

	i = 0;
	j = 0;
	ch = 0;
	while (s[j])
	{
		if (s[j] != c && !ch)
		{
			i++;
			ch = 1;
		}
		else if (s[j] == c)
			ch = 0;
		j++;
	}
	return (i);
}

static	int		ft_start(const char *s, char c, int cu)
{
	while (s[cu] == c && s[cu] != '\0')
		cu++;
	return (cu);
}

static int		ft_end(const char *s, char c, int cu)
{
	while (s[cu] != c && s[cu] != '\0')
		cu++;
	return (cu);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**str;
	int		len;
	int		i;
	int		cu;
	int		end;

	if (!s)
		return (NULL);
	i = 0;
	len = ft_counter(s, c);
	if (NULL == (str = (char**)malloc((len + 1) * sizeof(char*))))
		return (NULL);
	cu = 0;
	while (i < len)
	{
		cu = ft_start(s, c, cu);
		end = ft_end(s, c, cu + 1);
		str[i] = ft_strsub(s, cu, end - cu);
		cu = end;
		i++;
	}
	str[i] = 0;
	return (str);
}
