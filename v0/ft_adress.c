/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_adress.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magoumi <magoumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 08:28:18 by magoumi           #+#    #+#             */
/*   Updated: 2019/04/07 00:46:39 by magoumi          ###   ########.fr       */
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

void	ft_put_space(int n, t_data *var)
{
	while (--n >= 0)
		ft_putcharlen(' ', var);
}

void	ft_address(t_data *var, char *flag)
{
	t_flags		x;
	char		*hexa;
	long int	add;
	int			width;

	ft_initflags(&x);
	ft_checkflags(&x, flag);
	add = va_arg(var->vl, long int);
	hexa = ft_convtodec(add);
	hexa = ft_strjoin("0x", hexa);
	if (x.width)
	{
		width = ft_width(flag) - ft_strlen(hexa);
		if (!x.moin)
		{
			ft_put_space(width, var);
			ft_putstrlen(hexa, var);
		}
		else
		{
			ft_putstrlen(hexa, var);
			ft_put_space(width, var);
		}
	}
	else
		ft_putstrlen(hexa, var);
	free(hexa);
}