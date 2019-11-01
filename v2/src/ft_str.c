/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magoumi <magoumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 21:58:50 by magoumi           #+#    #+#             */
/*   Updated: 2019/10/27 22:18:24 by magoumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_str(char *flag, va_list list)
{
	char *str;

	str = va_arg(list, char*);
	str = ft_put_precision(str, flag);
	str = ft_put_width(str, flag);
	ft_putstr(str);
	return (ft_strlen(str));
}