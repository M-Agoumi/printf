/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magoumi <magoumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 06:04:15 by magoumi           #+#    #+#             */
/*   Updated: 2019/04/29 02:20:41 by magoumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

// static int	ft_todig(int n)
// {
// 	int count;

// 	count = 0;
// 	if (n < 0)
// 		count++;
// 	while (n != 0)
// 	{
// 		count++;
// 		n /= 10;
// 	}
// 	return (count);
// }

// static char	*ft_doall(int div, int dn, char *str)
// {
// 	int started;

// 	started = 0;
// 	while (div > 0)
// 	{
// 		if (dn / div > 0)
// 		{
// 			*str++ = dn / div + '0';
// 			dn = dn % div;
// 			started = 1;
// 		}
// 		else if (dn / div == 0)
// 		{
// 			if (started)
// 			{
// 				*str++ = dn / div + '0';
// 				dn = dn % div;
// 			}
// 		}
// 		div = div / 10;
// 	}
// 	*str = '\0';
// 	return (str);
// }

// char		*ft_itoa(long long int n)
// {
// 	char	*str;
// 	char	*ret;
// 	int		div;
// 	long	dn;

// 	if (n == -2147483648)
// 		return (ft_strdup("-2147483648"));
// 	if (n == 0)
// 		return (ft_strdup("0"));
// 	dn = (long)n;
// 	div = 1000000000;
// 	if (NULL == (str = (char*)malloc(ft_todig(dn) + 1)))
// 		return (NULL);
// 	ret = str;
// 	if (dn == 0)
// 		return ("0");
// 	if (dn < 0)
// 	{
// 		*str++ = '-';
// 		dn = -dn;
// 	}
// 	str = ft_doall(div, dn, str);
// 	return (ret);
// }

int 			ft_intlen(long long int n)
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

long long int	ft_power(long long int n)
{
	long long int nb;

	nb = 10;
	n = n > 0 ? n : -n;
	while(n)
	{
		nb *= 10;
		n /= 10;
	}
	return (nb);
}
char			*ft_itoab(long long int n)
{
	int				ln;
	long long int	div;
	char			*str;
	int				i;
	int				x;

	ln = ft_intlen(n);
	x = n < 0 ? 1 : 0;
	str = (char*)malloc(ln + 1 + x);
	if (x)
	{
		str[0] = '-';
		n *= -1;
	}
	div = ft_power(ln);
	i = 0;
	while (div)
	{
		str[i + x] = n / div + '0';
		n = n % div;
		div /= 10;
		i++;
	}
	str[i + x] = '\0';
	return (str);
}

// int main(void)
// {
// 	long long int x;
// 	x = 90000000000;
// 	printf("[%s]\n", ft_itoab(x));
// }