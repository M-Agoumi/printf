// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   ft_itoab.c                                         :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: magoumi <magoumi@student.42.fr>            +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2019/03/18 06:04:15 by magoumi           #+#    #+#             */
// /*   Updated: 2019/04/29 10:36:47 by magoumi          ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

#include "header.h"

static int	ft_todig(long long int n)
{
	long long int count;

	count = 0;
	if (n < 0)
		count++;
	while (n != 0)
	{
		count++;
		n /= 10;
	}
	return (count);
}

static char	*ft_doall(long long int div, long long int dn, char *str)
{
	long long int started;

	started = 0;
	while (div > 0)
	{
		if (dn / div > 0)
		{
			*str++ = dn / div + '0';
			dn = dn % div;
			started = 1;
		}
		else if (dn / div == 0)
		{
			if (started)
			{
				*str++ = dn / div + '0';
				dn = dn % div;
			}
		}
		div = div / 10;
	}
	*str = '\0';
	return (str);
}

char		*ft_itoab(long long int n)
{
	char	*str;
	char	*ret;
	long long int		div;
	long long int	dn;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	dn = (long)n;
	div = 1000000000;
	if (NULL == (str = (char*)malloc(ft_todig(dn) + 1)))
		return (NULL);
	ret = str;
	if (dn == 0)
		return ("0");
	if (dn < 0)
	{
		*str++ = '-';
		dn = -dn;
	}
	str = ft_doall(div, dn, str);
	return (ret);
}