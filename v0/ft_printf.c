/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magoumi <magoumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 12:50:38 by magoumi           #+#    #+#             */
/*   Updated: 2019/03/13 10:33:21 by magoumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void					ft_init(t_data *var, char *str)
{
	var->len = 0;
	var->str = str;
	var->i = -1;
	var->tmp = 0;
	var->x = 0;
}

int						ft_printf(char *str, ...)
{
	t_data var;

	ft_init(&var, str);
	va_start(var.vl, str);
	while (str[++var.i])
	{
		if (str[var.i] == '%' && ft_argornot(str[var.i + 1]))
			var.i += ft_var(&var);
		else
			ft_putcharlen(var.str[var.i], &var);
		var.x = 0;
	}
	va_end(var.vl);
	return (var.len);
}
