/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_var.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magoumi <magoumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 05:04:30 by magoumi           #+#    #+#             */
/*   Updated: 2019/03/18 05:59:58 by magoumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		is_flag(char c)
{
	if (c == 'd')
		return (1);
	return (0);
}

int		ft_var(t_data *var)
{
	int		x;
	int		end;
	char	*flag;

	x = 0;
	end = 0;
	while (!is_flag(var->str[var->i + end]))
		end++;
	flag = ft_strsub(var->str, var->i + 1, end);
	if (flag[end - 1] == 'd')
		ft_int(flag, var);
	free(flag);
	return (ft_strlen(flag) + 1);
}