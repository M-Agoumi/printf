/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_address.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magoumi <magoumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 02:46:29 by magoumi           #+#    #+#             */
/*   Updated: 2019/03/13 10:28:08 by magoumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_address(char *str, int index, long int decimal, t_data *var)
{
	int			i;
	int			j;
	int			temp;
	char		hexa[15];

	ft_putstrb("0x", var);
	i = 1;
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
	j = i;
	while (--j > 0)
		ft_putcharlen(hexa[j], var);
	return (0);
}
