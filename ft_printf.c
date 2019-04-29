/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magoumi <magoumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 04:53:47 by magoumi           #+#    #+#             */
/*   Updated: 2019/04/11 01:58:06 by magoumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void    ft_init(t_data *var, char *str)
{
	var->str = str;
	var->i = 0;
    var->len = 0;
}

int	    ft_printf(char *str, ...)
{
    t_data var;

	ft_init(&var, str);
	va_start(var.vl, str);
    if (!str)
        return (-1);
    while (str[var.i])
    {
        if (str[var.i] == '%')
            var.i += ft_var(&var);
        else
        {
            ft_putcharlen(str[var.i], &var);
            var.i++;
        }
    }
    va_end(var.vl);
    return (var.len);
}