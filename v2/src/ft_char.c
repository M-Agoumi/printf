/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magoumi <magoumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 09:50:08 by magoumi           #+#    #+#             */
/*   Updated: 2019/10/26 09:53:59 by magoumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(char *flag, va_list list)
{
	char c;

	c = va_arg(list, int);
	ft_putchar(c);
	return (ft_strlen(flag));
}