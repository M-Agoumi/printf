/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magoumi <magoumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 12:49:14 by magoumi           #+#    #+#             */
/*   Updated: 2019/03/03 01:00:15 by magoumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	main(void)
{
	int x = 42;
	ft_printf("%*.3d\n",10, 12);
	printf("%*.3d\n",10, 12);

	//printf("[%*d]\n", 5, 12);
	return (0);
}