/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magoumi <magoumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 12:50:38 by magoumi           #+#    #+#             */
/*   Updated: 2019/02/20 14:46:37 by magoumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int				ft_argornot(char c)
{
	if (c == 'd' || c == 'c' || c == 's' || c == 'p')
		return (1);
	return (0);
}

void			ft_writedownaddress(char *hexadecimalNumber, int i)
{
	int j;

	j = i - 1;
	while (j> 0)
	{
		if (hexadecimalNumber[j] >= 'A' && hexadecimalNumber[j] <= 'Z')
			ft_putchar(ft_tolower(hexadecimalNumber[j]));
		else
			ft_putchar(hexadecimalNumber[j]);
		j--;
	}
}

int				ft_address(char *str, int index, long int decimalNumber)
{
	ft_putstr("0x");
	long int remainder,quotient;
	int i=1,temp;
	char hexadecimalNumber[100];
	quotient = decimalNumber;
	while(quotient!=0) {
		temp = quotient % 16;
		if( temp < 10)
		    temp =temp + 48; else
		    temp = temp + 55;
		hexadecimalNumber[i++]= temp;
		quotient = quotient / 16;
	}
	ft_writedownaddress(hexadecimalNumber, i);
	return 0;
}

int				ft_var(char *str, int i, va_list vl)
{
	int j;

	j = 1;
	if(str[i + 1] == 'd')
		ft_putnbr(va_arg(vl, int));
	if(str[i + 1] == 's')
		ft_putstr(va_arg(vl, const char *));
	if(str[i + 1] == 'c')
		ft_putchar(va_arg(vl, int));
	if (str[i + 1] == 'p')
		i += ft_address(str, i, va_arg(vl, long int));
	return (1);
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
			i += ft_var(str, i, vl);
		}
		else {
			ft_putchar(str[i]);
		}
	}
	va_end(vl);
	return (0);
}
