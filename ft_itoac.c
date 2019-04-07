/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoac.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magoumi <magoumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 19:00:01 by magoumi           #+#    #+#             */
/*   Updated: 2019/04/03 19:04:41 by magoumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int 			ft_intlen(unsigned long long int n)
{
	int x;

	x = 0;
	n = n > 0 ? n : -n; 
	if (n > -9 && n < 9)
		return (1);
	while (n > 0)
	{
		x++;
		n /= 10;
	}
	return (x);
}

static long long int	ft_power(unsigned long long int n)
{
	int i;
	long long int nb;

	i = 1;
	nb = 1;
	n = n > 0 ? n : -n;
	while(i < n)
	{
		nb *= 10;
		i++;
	}
	return (nb);
}
char			*ft_itoac(unsigned long long int n)
{
	int				ln;
	long long int	div;
	char			*str;
	int				i;

	ln = ft_intlen(n);
	str = (char*)malloc(ln + 1);
	div = ft_power(ln);
	i = 0;
	while (div)
	{
		str[i] = (n / div) + '0';
		n = n % div;
		div /= 10;
		i++;
	}
	str[i] = '\0';
	return (str);
}