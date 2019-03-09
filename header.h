/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magoumi <magoumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 11:46:29 by magoumi           #+#    #+#             */
/*   Updated: 2019/03/09 10:54:05 by magoumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include "libft/libft.h"
# include <stdarg.h>
# include <stdio.h>

typedef struct data
{
    char *str;
    int i;
    int len;
    int tmp;
    int x;
    va_list vl;
    
}               data;


int	ft_printf(char *str, ...);

#endif
