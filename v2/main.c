/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magoumi <magoumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 05:44:10 by magoumi           #+#    #+#             */
/*   Updated: 2019/11/01 03:31:36 by magoumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"
#include <stdio.h>

int	main(void)
{
	unsigned int i;

	i = 12;
	//ft_printf("hello %010s\n", "-99");
	ft_printf("hello %010s\n", "99");

	printf("hello %010s\n", "99");
	return (0);
}