/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magoumi <magoumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 14:38:20 by magoumi           #+#    #+#             */
/*   Updated: 2019/10/29 20:30:09 by magoumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		is_long_long(char *flag)
{
	int	i;
	int j;

	i = 0;
	j = 0;
	while (flag[i])
	{
		if (flag[i] == 'l')
		{
			if (j)
				return (1);
			else
				j = 1;
		}
		i++;
	}
	return (0);
}

int		is_long(char *flag)
{
	int	i;

	i = -1;
	while (flag[++i])
		if (flag[i] == 'l')
			return (1);
	return (0);
}

int		ft_print_int(char *flag, va_list list)
{
	long long int	nb;
	char			*nbr;

	if (is_long(flag))
		if (is_long_long(flag))
			nb = va_arg(list, long long int);
		else
			nb = (long int)va_arg(list, long int);
	else
		nb = (int)va_arg(list, int);
	nbr = ft_itoa_long(nb);
	nbr = ft_put_prec_int(nbr, flag);
	nbr = ft_put_width(nbr, flag);
	ft_printf("%s", nbr);
	return (ft_strlen(nbr));
}