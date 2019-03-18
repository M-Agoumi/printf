/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magoumi <magoumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 02:21:24 by magoumi           #+#    #+#             */
/*   Updated: 2019/03/18 04:24:15 by magoumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_precisionb(int num, int i, t_data *var)
{
	int		x;
	int		end;
	char	*n;

	end = 0;
	if (var->str[i] <= '9' && var->str[i] >= '0')
	{
		while (var->str[i + end] <= '9' && var->str[i] + end >= '0')
			end++;
		n = ft_strsub(var->str, i, end);
		x = ft_atoi(n);
		free(n);
	}
	else if (var->str[i] == '*')
	{
		x = va_arg(var->vl, int);
		end = 1;
	}
	if (var->str[i + end] == 's')
		ft_putstrlenb(va_arg(var->vl, char *), num, x, var);
	else if (var->str[i + end] == 'd')
		ft_putintlenb(va_arg(var->vl, int), x, num, var);
	return (end + 2);
}

int	ft_precisiona(t_data *var, int i, int nbr)
{
	int		num;
	int		end;
	char	*n;

	end = 0;
	if (var->str[i] <= '9' && var->str[i] >= '0')
	{
		while (var->str[i + end] <= '9' && var->str[i] + end >= '1')
			end++;
		n = ft_strsub(var->str, i, end);
		num = ft_atoi(n);
		free(n);
	}
	else if (var->str[i] == '*')
	{
		num = va_arg(var->vl, int);
		end = 1;
	}
	if (var->str[i + end] == 's')
		ft_putstrlen(va_arg(var->vl, char *), num, var);
	else if (var->str[i + end] == 'd')
		ft_putintlen(nbr, num, var);
	return (end + 2);
}

int	ft_precisiontpre(t_data *var, int i)
{
	int wild;
	int end;
	int nb;
	int num;

	wild = va_arg(var->vl, int);
	nb = va_arg(var->vl, int);
	end = 0;
	while (var->str[i + end] <= '9' && var->str[i] + end >= '1')
		end++;
	num = ft_atoi(ft_strsub(var->str, i, end));
	ft_put_spaces(wild - num, var);
	return (end + ft_precisiona(var, i, nb));
}

int	ft_precisiontwo(char *str, int i, t_data *var)
{
	int	num;
	int	end;

	end = 0;
	while (str[i + end] <= '9' && str[i] + end >= '1')
		end++;
	num = ft_atoi(ft_strsub(str, i, end));
	if (str[i + end] == 's')
		ft_putstrlen(va_arg(var->vl, char *), num, var);
	else if (str[i + end] == 'd')
		ft_putintlen(va_arg(var->vl, int), num, var);
	return (end + 2);
}

int	ft_precision(t_data *var, int i)
{
	int		num;
	int		end;
	char	*n;

	end = 0;
	if (var->str[i] <= '9' && var->str[i] >= '0')
	{
		while (var->str[i + end] <= '9' && var->str[i] + end >= '1')
			end++;
		n = ft_strsub(var->str, i, end);
		num = ft_atoi(n);
		free(n);
	}
	else if (var->str[i] == '*')
	{
		num = va_arg(var->vl, int);
		end = 1;
	}
	if (var->str[i + end] == 's')
		ft_putstrlen(va_arg(var->vl, char *), num, var);
	else if (var->str[i + end] == 'd')
		ft_putintlen(va_arg(var->vl, int), num, var);
	return (end + 2);
}
