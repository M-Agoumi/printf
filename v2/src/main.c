/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magoumi <magoumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 05:44:10 by magoumi           #+#    #+#             */
/*   Updated: 2019/10/26 11:01:43 by magoumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	ft_printf("it's actually%2corkin\n", 'w');
	printf("it's actually%2corkin\n", 'w');
	return (0);
}