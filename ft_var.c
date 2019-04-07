/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_var.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magoumi <magoumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 05:04:30 by magoumi           #+#    #+#             */
/*   Updated: 2019/04/07 01:25:51 by magoumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		is_flag(char c)
{
	if (c == 'd' || c == 's' || c == 'p' || c == 'o' || c == 'c' || c == 'C' || c == 'x')
		return (1);
	return (0);
}

int		ft_precentage(t_data *var)
{
	ft_putcharlen('%', var);
	return (2);
}

int		ft_var(t_data *var)
{
	int		x;
	int		end;
	char	*flag;

	x = 0;
	end = 0;
	while (!is_flag(var->str[var->i + end]) && var->str[var->i + end])
		end++;
	flag = ft_strsub(var->str, var->i + 1, end);
	if (var->str[var->i + 1] == '%')
		return (ft_precentage(var));
	else if (flag[end - 1] == 'd')
		ft_int(flag, var);
	else if (flag[end - 1] == 's')
		ft_str(flag, var);
	else if (flag[end - 1] == 'p')
		ft_address(var, flag);
	else if (flag[end - 1] == 'o')
	 	ft_octal(flag, var);
	else if (flag[end - 1] == 'c' || flag[end - 1] == 'C')
	 	ft_char(flag, var);
	else if (flag[end - 1] == 'x')
	 	ft_intx(flag, var);
	free(flag);
	return (end + 1);
}