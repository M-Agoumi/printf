/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_address.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magoumi <magoumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 13:29:20 by magoumi           #+#    #+#             */
/*   Updated: 2019/10/29 14:31:55 by magoumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_convtodec(long int decimal)
{
	int			i;
	int			temp;
	char		hexa[15];

	i = 0;
	if (!decimal)
		return("0");
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

int		ft_print_address(char *flag, va_list list)
{
	char *address;

	address = ft_convtodec(va_arg(list, long int));
	address = ft_strjoin("0x", address);
	address = ft_put_width(address, flag);
	ft_putstr(address);
	return (ft_strlen(address));
}