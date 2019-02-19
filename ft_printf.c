/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magoumi <magoumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 12:50:38 by magoumi           #+#    #+#             */
/*   Updated: 2019/02/19 12:43:52 by magoumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int				ft_argornot(char c)
{
	if (c == 'd' || c == 'c' || c == 's')
		return (1);
	return (0);
}

int				ft_printf(char *str, ...)
{
	int i;
	va_list vl;

	va_start(vl, str);
	i = -1;
	while(str[++i]){
		if (str[i] == '%' && ft_argornot(str[i + 1]))
		{
			if(str[i + 1] == 'd')
				ft_putnbr(va_arg(vl, int));
			if(str[i + 1] == 's')
				ft_putstr(va_arg(vl, const char *));
			if(str[i + 1] == 'c')
				ft_putchar(va_arg(vl, int));
			i++;
		}
		else {
			ft_putchar(str[i]);
		}
	}
	return (0);
}