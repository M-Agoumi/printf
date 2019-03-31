/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_adress.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magoumi <magoumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 08:28:18 by magoumi           #+#    #+#             */
/*   Updated: 2019/03/27 21:38:04 by magoumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*ft_convtodec(long int decimal)
{
	int			i;
	int			j;
	int			temp;
	char		hexa[15];

	i = 0;
	while (decimal != 0)
	{
		temp = decimal % 16;
		if (temp < 10)
			temp = temp + 48;
		else
			temp = temp + 87;
		hexa[i++] = temp;
		decimal = decimal / 16;
	}
	hexa[i] = '\0';
	return (ft_strrev(hexa));
}

void	ft_address(t_data *var, char *flag)
{
	t_flags	x;
	char	*hexa;
	long int		add;

	ft_initflags(&x);
	ft_checkflags(&x, flag);
	add = va_arg(var->vl, long int);
	hexa = ft_convtodec(add);
	//ft_printf("[%s]", hexa);
	ft_putstrlen("0x", var);
	ft_putstrlen(hexa, var);
}