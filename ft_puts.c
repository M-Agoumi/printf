/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puts.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magoumi <magoumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 05:00:38 by magoumi           #+#    #+#             */
/*   Updated: 2019/04/16 16:33:54 by magoumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void    ft_putcharlen(char c, t_data *var)
{
    ft_putchar(c);
    var->len++;
}

void    ft_putstrlen(char *str, t_data *var)
{
    ft_putstr(str);
    var->len += ft_strlen(str);
}