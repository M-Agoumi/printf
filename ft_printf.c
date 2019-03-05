/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magoumi <magoumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 12:50:38 by magoumi           #+#    #+#             */
/*   Updated: 2019/03/03 00:59:16 by magoumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int				ft_argornot(char c)
{
	if (c == 'd' || c == 'c' || c == 's' || c == 'p' || c == '%' || c == 'i' || c == 'o' || c == '*' || c == 'f')
		return (1);
	else if (c <= '9' && c >= '0')
		return (1);
	return (0);
}

int				ft_nbrlen(int nb)
{
	int i;

	i = 0;
	while(nb > 0)
	{
		i++;
		nb /= 10;
	}
	return (i);
}

void				ft_putcharlen(char c, data *var)
{
	ft_putchar(c);
	var->len += 1;
}

void			ft_putnbrlen(int nbr, data *var)
{
	var->len += ft_nbrlen(nbr);
	ft_putnbr(nbr);
}

void			ft_putstrb(char const *str, data *var)
{
	while(*str)
		ft_putcharlen(*str++, var);
}

int				ft_putstrlen(char *str, int limit, data *var)
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

int				ft_address(char *str, int index, long int decimal, data *var)
{
	int			i;
	int			j;
	int			temp;
	char		hexa[15];

	ft_putstrb("0x", var);
	i = 1;
	while (decimal != 0)
	{
		temp = decimal % 16;
		if (temp < 10)
			temp = temp + 48;
		else
			temp = temp + 87;
		hexa[i++] = temp;
		decimal = decimal / 16;
	}
	j = i;
	while (--j > 0)
		ft_putcharlen(hexa[j], var);
	return (0);
}

int				ft_putintlen(int nbr, int limit)
{
	int	len;
	int x;

	len = ft_nbrlen(nbr);
	if (len > limit)
		ft_putnbr(nbr);
	else
	{
		x = limit - len;
		while (x--)
			ft_putchar('0');
		ft_putnbr(nbr);
	}
	return (0);
}

int				ft_precision(data *var, int i)
{
	int		num;
	int		end;
	char	*n;

	end = 0;
	while (var->str[i + end] <= '9' && var->str[i] + end >= '1')
		end++;
	n = ft_strsub(var->str, i, end);
	num = ft_atoi(n);
	if (var->str[i + end] == 's')
		ft_putstrlen(va_arg(var->vl, char *), num, var);
	else if (var->str[i + end] == 'd')
		ft_putintlen(va_arg(var->vl, int), num);
	free(n);
	return (end + 2);
}

int				ft_octal(int n)
{
	int i;
	int octal;

	octal = 0;
	i = 1;
	while (n > 0)
	{
		octal = octal + (n % 8) * i;
		i = i * 10;
		n = n / 8;
	}
	return (octal);
}

void			ft_putspace(int lim, int nb, data *var){
	int i;
	int ln;

	i = 0;
	ln = ft_nbrlen(nb);
	if (ln < lim)
		while (i++ < lim - ln)
			ft_putcharlen(' ', var);
	ft_putnbrlen(nb, var);
}

int				ft_widthwild(char *str, int i, data *var)
{
	int	num;
	int	end;

	end = 0;
	while (str[i + end] <= '9' && str[i] + end >= '1')
		end++;
	num = ft_atoi(ft_strsub(str, i, end));
	if (str[i + end] == 'd')
		ft_putspace(num, va_arg(var->vl, int), var);
	return (end + 1);
}

int				ft_precisiontwo(char *str, int i, data *var)
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
		ft_putintlen(va_arg(var->vl, int), num);
	return (end + 2);
}

void			ft_put_spaces(int n, data *var)
{
	if (n > 0)
		while (n--)
			ft_putcharlen(' ', var);
}

int				ft_precisiontpre(data *var, int i)
{
	int wild;
	int prec;
	int end;
	int nb;
	int num;

	wild = va_arg(var->vl, int);
	nb = va_arg(var->vl, int);
	end = 0;
	while (var->str[i + end] <= '9' && var->str[i] + end >= '1')
		end++;
	//ft_printf("[%c][%c]", var->str[i], var->str[end]);
	num = ft_atoi(ft_strsub(var->str, i, end));
	//ft_printf("[%d][%d][%d]", wild, num, wild - num - ft_nbrlen(nb));
	ft_put_spaces(wild - num - ft_nbrlen(nb), var);
	return (end + ft_precision(var, i));
}

int				ft_widthwildtwo(int num, data *var)
{
	int	end;

	end = 0;
	ft_putspace(num, va_arg(var->vl, int), var);
	return (end + 1);
}

int				ft_wildcard(char *str, int i, data *var)
{
	if (str[i + 1] == 'd')
		return (ft_widthwildtwo(va_arg(var->vl, int), var) + 1);
	else if (str[i + 1] == '.')
		return (ft_precisiontpre(var, var->i + 3));
	return (1);
}

int			ft_putfloat(data *var)
{
	var->len += printf("%f", va_arg(var->vl, double));
	return (1);	
}

int				ft_var(data* var)
{
	int j;

	j = 1;
	if (var->str[var->i + 1] == '.')
		j = ft_precision(var, var->i + 2);
	else if (var->str[var->i + 1] == 'd' || var->str[var->i + 1] == 'i')
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
	else if (var->str[var->i + 1] >= '0' && var->str[var->i + 1] <= '9')
		j = ft_widthwild(var->str,var->i + 1, var);
	else if (var->str[var->i + 1] == '*')
		j = ft_wildcard(var->str, ++(var->tmp), var);
	else if (var->str[var->i + 1] == 'f')
		j = ft_putfloat(var);
	return (j);
}

void			ft_init(data *var, char *str)
{
	var->len = 0;
	var->str = str;
	var->i = -1;
	var->tmp = 0;
}

int				ft_printf(char *str, ...)
{
	data var;

	ft_init(&var, str);
	va_start(var.vl, str);
	while (str[++var.i])
	{
		if (str[var.i] == '%' && ft_argornot(str[var.i + 1]))
			var.i += ft_var(&var);
		else
			ft_putcharlen(var.str[var.i], &var);
	}
	va_end(var.vl);
	return (var.len);
}
