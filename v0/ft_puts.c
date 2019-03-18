/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puts.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magoumi <magoumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 02:23:58 by magoumi           #+#    #+#             */
/*   Updated: 2019/03/18 04:32:56 by magoumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_putcharlen(char c, t_data *var)
{
	ft_putchar(c);
	var->len += 1;
}

void	ft_putnbrlen(int nbr, t_data *var)
{
	if (var->x)
		ft_putcharlen(' ', var);
	var->len += ft_nbrlen(nbr);
	ft_putnbr(nbr);
}

int		ft_putwildstr(int num, char *str, t_data *var)
{
	int len;

	len = num - ft_strlen(str);
	if (len > 0)
		while (len--)
			ft_putcharlen(' ', var);
	ft_putstrb(str, var);
	return (1);
}

int		ft_putstrlenb(char *str, int limit, int x, t_data *var)
{
	// int		i;

	// i = 0;
	// limit = ft_strlen(str) < limit ? ft_strlen(str) : limit;
	// ft_printf("[xd]");
	// while (i < limit)
	// {
	// 	ft_putchar(str[i]);
	// 	var->len += 1;
	// 	i++;
	// }
	// limit is the field width 
	// x is the precision
	int i;
	int y;
	int d;

	i = 0;
	y = ft_strlen(str);
	d = limit > x ? limit - x : 0;
	ft_put_spaces(d, var);
	ft_putstrlen(str, x, var);
	return (0);
}

int		ft_putstrlen(char *str, int limit, t_data *var)
{
	int		i;

	i = 0;
	limit = ft_strlen(str) < limit ? ft_strlen(str) : limit;
	while (i < limit)
	{
		ft_putchar(str[i]);
		var->len += 1;
		i++;
	}
	return (0);
}

int		ft_putintlen(int nbr, int limit, t_data *var)
{
	int	len;
	int x;

	len = ft_nbrlen(nbr);
	if (len > limit)
		ft_putnbrlen(nbr, var);
	else
	{
		x = limit - len;
		while (x--)
			ft_putcharlen('0', var);
		ft_putnbrlen(nbr, var);
	}
	return (0);
}

int		ft_putintlenb(int nbr, int y, int limit, t_data *var)
{
	int	len;
	int x;

	len = ft_nbrlen(nbr);
	if (len > limit)
		ft_putnbrlen(nbr, var);
	else
	{
		x = limit >= y ? limit - y : limit - len;
		//ft_printf("[%d][%d]", limit, y);
		if (limit > y)
			while (x--)
				ft_putcharlen(' ', var);
		x = y - len;
		while (x--)
			ft_putcharlen('0', var);
		ft_putnbrlen(nbr, var);
	}
	return (0);
}

void	ft_putspace(int lim, int nb, t_data *var, int x)
{
	int i;
	int ln;

	i = 0;
	ln = ft_nbrlen(nb);
	if (x)
		ln++;
	if (ln < lim)
		while (i++ < lim - ln)
			ft_putcharlen(' ', var);
	if (x == 1)
		ft_putcharlen('+', var);
	if (!x)
		ft_putnbrlen(nb, var);
	else if (x == 2)
		ft_putcharlen('%', var);
}

void	ft_put_spaces(int n, t_data *var)
{
	if (n > 0)
		while (n--)
			ft_putcharlen(' ', var);
}

void	ft_putstrb(char const *str, t_data *var)
{
	while (*str)
		ft_putcharlen(*str++, var);
}

int		ft_putzeros(char *str, int i, t_data *var)
{
	int	num;
	int	end;

	end = 0;
	while (str[i + end] <= '9' && str[i] + end >= '0')
		end++;
	num = ft_atoi(ft_strsub(str, i, end));
	if (str[i + end] == 'd')
		ft_putz(num, va_arg(var->vl, int), var);
	return (end + 1);
}

void	ft_putz(int lim, int nb, t_data *var)
{
	int i;
	int ln;

	i = 0;
	ln = ft_nbrlen(nb);
	if (ln < lim)
		while (i++ < lim - ln)
			ft_putcharlen('0', var);
	ft_putnbrlen(nb, var);
}

void	ft_putspacebackward(int lim, int nb, t_data *var, int x)
{
	int i;
	int ln;

	i = 0;
	ln = ft_nbrlen(nb) + x;
	if (!x)
		ft_putnbrlen(nb, var);
	else
		ft_putcharlen('%', var);
	if (ln < lim)
		while (i++ < lim - ln)
			ft_putcharlen(' ', var);
}
