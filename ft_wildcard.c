/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wildcard.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magoumi <magoumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 02:21:52 by magoumi           #+#    #+#             */
/*   Updated: 2019/03/13 14:30:37 by magoumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_widthwildtwo(int num, t_data *var)
{
	int	end;

	end = 0;
	ft_putspace(num, va_arg(var->vl, int), var, 0);
	return (end + 1);
}

int	ft_wildcard(char *str, int i, t_data *var)
{
	if (str[i + 1] == 'd')
		return (ft_widthwildtwo(va_arg(var->vl, int), var) + 1);
	else if (str[i + 1] == '.')
		return (ft_precisiontpre(var, var->i + 3));
	return (4);
}

int	ft_widthwild(char *str, int i, t_data *var, int x)
{
	int	num;
	int	end;

	end = 0;
	while (str[i + end] <= '9' && str[i + end] >= '0')
		end++;
	num = ft_atoi(ft_strsub(str, i, end));
	if (str[i + end] == 'd')
		ft_putspace(num, va_arg(var->vl, int), var, x);
	else if (str[i + end] == '.')
		return (ft_precisionb(num, i + end + 1, var) + end);
	else if (str[i + end == 's'])
		ft_putwildstr(num, va_arg(var->vl, char *), var);
	else if (str[i + end - 1] == '%')
	{
		ft_putspace(num, 0, var, 2);
		return (end + 1);
	}
	else
	{
		ft_putspace(num, 0, var, x);
		return (end - 1);
	}
	return (end + 1 + x);
}
