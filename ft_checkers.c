/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magoumi <magoumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 02:31:38 by magoumi           #+#    #+#             */
/*   Updated: 2019/03/13 10:28:10 by magoumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_argornot(char c)
{
	if (c == 'd' || c == 'c' || c == 's' || c == 'p' || c == '%' || c == 'i' ||
	c == 'o' || c == '*' || c == 'f' || c == '.' || c == '-' || c == '+' ||
	c == ' ')
		return (1);
	else if (c <= '9' && c >= '0')
		return (1);
	return (0);
}

int	ft_varb(t_data *var)
{
	int j;

	if (var->str[var->i + 1] == '+')
		j = ft_widthwild(var->str, var->i + 2, var, 1);
	else if (var->str[var->i + 1] == '0')
		j = ft_putzeros(var->str, var->i + 1, var);
	else if (var->str[var->i + 1] == '*')
		j = ft_wildcard(var->str, ++(var->tmp), var);
	else if (var->str[var->i + 1] == 'f')
		j = ft_putfloat(var);
	else if (var->str[var->i + 1] == '-')
		j = ft_dash(var->i + 2, var);
	return (j + var->x);
}

int	ft_var(t_data *var)
{
	int j;

	j = 1;
	if (var->str[var->i + 1] == ' ')
		ft_skipspaces(var, var->i + 1);
	if (var->str[var->i + 1] == '.')
		j = ft_precision(var, var->i + 2);
	else if (var->str[var->i + 1 + var->x] == 'd' ||
	var->str[var->i + 1 + var->x] == 'i')
		ft_putnbrlen(va_arg(var->vl, int), var);
	else if (var->str[var->i + 1] == 's')
		ft_putstrb(va_arg(var->vl, const char *), var);
	else if (var->str[var->i + 1] == 'c')
		ft_putcharlen(va_arg(var->vl, int), var);
	else if (var->str[var->i + 1] == 'p')
		ft_address(var->str, var->i, va_arg(var->vl, long int), var);
	else if (var->str[var->i + 1] == '%')
		ft_putcharlen('%', var);
	else if (var->str[var->i + 1] == 'o')
		ft_putnbrlen(ft_octal(va_arg(var->vl, int)), var);
	else if (var->str[var->i + 1] >= '1' && var->str[var->i + 1] <= '9')
		j = ft_widthwild(var->str, var->i + 1, var, 0);
	else
		return (ft_varb(var));
	return (j + var->x);
}
