/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magoumi <magoumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 09:50:08 by magoumi           #+#    #+#             */
/*   Updated: 2019/10/27 19:53:46 by magoumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_char_to_str(char c)
{
	char *str;

	str = ft_strnew(1);
	str[0] = c;
	return (str);
}
int		ft_print_char(char *flag, va_list list)
{
	char *c;

	c = ft_char_to_str(va_arg(list, int));
	c = ft_put_width(c, flag);
	ft_putstr(c);
	return (ft_strlen(c));
}