/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magoumi <magoumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 20:13:58 by magoumi           #+#    #+#             */
/*   Updated: 2019/04/11 01:59:29 by magoumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ft_precentage(t_data *var, int i)
{
	int end;
	int width;
	char *flag;

	end = 0;
	//ft_printf("[%c]", var->str[i + end]);
	while (var->str[i + end] != '%' && var->str[i + end])
		end++;
	//ft_printf("[%d]", end);
	flag = ft_strsub(var->str, i, end);
	//ft_printf("{%s}", flag);
	width = ft_width(flag);
	if (width <= 0)
		ft_putcharlen('%', var);
	else
	{
		if (!ft_strchr(flag, '-'))
		{
			while (--width)
				ft_putcharlen(' ', var);
			ft_putcharlen('%', var);
		}else
		{
			ft_putcharlen('%', var);
			while (--width)
				ft_putcharlen(' ', var);
		}
		
	}
	return (end + 2);
}