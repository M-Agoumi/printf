/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magoumi <magoumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 12:50:38 by magoumi           #+#    #+#             */
/*   Updated: 2019/02/23 20:59:27 by magoumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int				ft_argornot(char c)
{
	if (c == 'd' || c == 'c' || c == 's' || c == 'p' || c == '%' || c == 'i' || c == 'o')
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

void			ft_putnbrlen(int nbr, int *len)
{
	*len += ft_nbrlen(nbr);
	ft_putnbr(nbr);
}

int				ft_putstrlen(char *str, int limit, int *len)
{
	int		i;

	i = 0;
	limit = ft_strlen(str) < limit ? ft_strlen(str) : limit;
	while (i < limit)
	{
		ft_putchar(str[i]);
		*len += 1;
		i++;
	}
	return (0);
}

int				ft_address(char *str, int index, long int decimal)
{
	int			i;
	int			j;
	int			temp;
	char		hexa[15];

	ft_putstr("0x");
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
		ft_putchar(hexa[j]);
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

int				ft_precision(char *str, int i, va_list vl, int *len)
{
	int	num;
	int	end;

	end = 0;
	while (str[i + end] <= '9' && str[i] + end >= '1')
	{
		end++;
	}
	num = ft_atoi(ft_strsub(str, i, end));
	if (str[i + end] == 's')
	{
		ft_putstrlen(va_arg(vl, char *), num, len);
	}
	else if (str[i + end] == 'd')
	{
		ft_putintlen(va_arg(vl, int), num);
	}
	return (end + 2);
}

int				ft_var(char *str, int i, va_list vl, int *len)
{
	int j;

	j = 1;
	if (str[i + 1] == '.')
		j = ft_precision(str, i + 2, vl, len);
	else if (str[i + 1] == 'd' || str[i + 1] == 'i' || str[i + 1] == 'o')
		ft_putnbrlen(va_arg(vl, int), len);
	else if (str[i + 1] == 's')
		ft_putstr(va_arg(vl, const char *));
	else if (str[i + 1] == 'c')
		ft_putchar(va_arg(vl, int));
	else if (str[i + 1] == 'p')
		ft_address(str, i, va_arg(vl, long int));
	else if (str[i + 1] == '%')
		ft_putchar('%');
	return (j);
}

int				ft_printf(char *str, ...)
{
	int		i;
	va_list	vl;
	int		len;

	va_start(vl, str);
	i = -1;
	len = 0;
	while (str[++i])
	{
		if (str[i] == '%')
			i += ft_var(str, i, vl, &len);
		else
		{
			ft_putchar(str[i]);
			len++;
		}
	}
	va_end(vl);
	return (len);
}
