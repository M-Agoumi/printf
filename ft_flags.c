/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magoumi <magoumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 03:04:18 by magoumi           #+#    #+#             */
/*   Updated: 2019/03/13 10:28:12 by magoumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int						ft_dash(int i, t_data *var)
{
	int	num;
	int	end;

	end = 0;
	while (var->str[i + end] <= '9' && var->str[i] + end >= '1')
		end++;
	num = ft_atoi(ft_strsub(var->str, i, end));
	if (var->str[i + end] == 'd')
		ft_putspacebackward(num, va_arg(var->vl, int), var, 0);
	else if (var->str[i + end - 1] == '%')
	{
		ft_putspacebackward(num, 0, var, 1);
		return (end + 1);
	}
	return (end + 2);
}
