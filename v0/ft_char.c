/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magoumi <magoumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 22:55:45 by magoumi           #+#    #+#             */
/*   Updated: 2019/04/06 23:11:30 by magoumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void    ft_char(char *flag, t_data *var)
{
	int     width;
	char    c;
	t_flags x;

	ft_initflags(&x);
	ft_checkflags(&x, flag);
	width = ft_width(flag) - 1;
	c = va_arg(var->vl, int);
	if (x.width)
	{
		if (x.moin)
		{
			ft_putcharlen(c, var);
			while (--width >= 0)
				ft_putcharlen(' ', var);
		}
		else
		{
			while (--width >= 0)
				ft_putcharlen(' ', var);
			ft_putcharlen(c, var);
		}
		
	}
	else
		ft_putcharlen(c, var);
}