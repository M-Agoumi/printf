/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_var.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magoumi <magoumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 05:04:30 by magoumi           #+#    #+#             */
/*   Updated: 2019/04/22 04:01:17 by magoumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		is_flag(char c)
{
	if (c == 'd' || c == 's' || c == 'p' || c == 'o' || c == 'c' || c == 'C'
	|| c == 'x' || c == 'X' || c == 'i')
		return (1);
	return (0);
}

int		is_prec(char *flag, int i)
{
	while (flag[i])
	{
		if (is_flag(flag[i]))
			return (0);
		if (flag[i] == '%')
			return (1);
		i++;
	}
	return (0);
}
int		ft_var(t_data *var)
{
	//int		x;
	int		end;
	char	*flag;

	//x = 0;// maybe useless
	end = 0;
	while (!is_flag(var->str[var->i + end]) && var->str[var->i + end])
		end++;
	flag = ft_strsub(var->str, var->i + 1, end);
	if (is_prec(var->str, var->i+1))
		return(ft_precentage(var, var->i + 1));
	else if (flag[end - 1] == 'd' || flag[end - 1] == 'i')
		ft_int(flag, var);
	else if (flag[end - 1] == 's')
		ft_str(flag, var);
	else if (flag[end - 1] == 'p')
		ft_address(var, flag);
	else if (flag[end - 1] == 'o')
	 	ft_octal(flag, var);
	else if (flag[end - 1] == 'c' || flag[end - 1] == 'C')
	 	ft_char(flag, var);
	else if (flag[end - 1] == 'x' || flag[end - 1] == 'X')
	 	ft_intx(flag, var);
	free(flag);
	return (end + 1);
}