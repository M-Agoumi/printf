/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magoumi <magoumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 12:49:14 by magoumi           #+#    #+#             */
/*   Updated: 2019/04/07 01:52:20 by magoumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	main(void)
{
	long long int x = 4294967296;
	char y[] = "Hello worlllllllllllllllllllllllllllllllllllllllllld";

	ft_printf("[%llx] is a string\n", x);
	printf("[%llx] is a string\n", x);
	return (0);
}
