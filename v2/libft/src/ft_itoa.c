/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magoumi <magoumi@1337.MA>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/21 06:23:31 by magoumi           #+#    #+#             */
/*   Updated: 2018/10/26 14:04:08 by magoumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_todig(int n)
{
	int count;

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

static char	*ft_doall(int div, int dn, char *str)
{
	int started;

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

char		*ft_itoa(int n)
{
	char	*str;
	char	*ret;
	int		div;
	long	dn;

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
