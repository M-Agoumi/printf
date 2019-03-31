/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_octal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magoumi <magoumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 00:16:38 by magoumi           #+#    #+#             */
/*   Updated: 2019/03/30 18:32:20 by magoumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

long long int     to_octal(long long int n)
{
    long long int i;
	long long int octal;

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

long long int	ft_octal(/*char *flag, t_data *var*/ long long int n)
{
	// t_flags x;
	// char	*nstr;

	// ft_initflags(&x);
	// ft_checkflags(&x, flag);
	// //printf("[flag  %s]", flag);
	// flag[ft_strlen(flag) - 1] = 'd';
	// nstr = ft_strjoin("%", flag);
	// ft_printf(nstr, to_octal(va_arg(var->vl, int)));
	return (to_octal(n));
}