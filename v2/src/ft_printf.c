/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magoumi <magoumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 06:08:26 by magoumi           #+#    #+#             */
/*   Updated: 2019/11/01 03:19:57 by magoumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_flag(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'x' || c == 'X' || c == 'i')
		return (1);
	return (0);
}

char	*ft_get_flag(char *format, int i)
{
	int		j;
	char	*flag;

	j = 0;
	while (!is_flag(format [i + j]))
		j++;
	flag = ft_strsub(format, i , j + 1);
	return (flag);
}

int		is_conversion(char *format, int i)
{
	while (format[i])
	{
		if (is_flag(format[i]))
			return (1);
		i++;
	}
	return (0);
}

char	ft_get_char_flag(char *format, int i)
{
	int j;

	j = 0;
	while (!is_flag(format[i + j]))
		j++;
	return (format[i + j]);
}

int		ft_print_conversion(char *format, int i, va_list list)
{
	char	*flag;
	char	flg;

	flag = ft_get_flag(format, i);
	flg = ft_get_char_flag(format, i);
	if (flg == 'c')
		return (ft_print_char(flag, list));
	if (flg == 's')
		return (ft_print_str(flag, list));
	if (flg == 'p')
		return (ft_print_address(flag, list));
	if (flg == 'd' || flg == 'i')
		return (ft_print_int(flag, list));
	if (flg == 'x' || flg == 'X')
		return (ft_print_int_x(flag, list));
	return (0);
}

int		ft_skip_flag(char *format, int i)
{
	int j;

	j = 0;
	while (!is_flag(format [i + j]))
		j++;
	return (j);
}

int		ft_printall(char *format, va_list list)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (is_conversion(format, i))
			{
				len += ft_print_conversion(format, i, list);
				i += ft_skip_flag(format, i);
			}
		}
		else
		{
			ft_putchar(format[i]);
			len++;
		}
		i++;
	}
	return (len);
}

int		ft_printf(char *format, ...)
{
	va_list	list;
	int		len;

	if (!format)
		return (0);
	va_start(list, format);
	len = ft_printall(format, list);
	va_end(list);
	return (len);
}
