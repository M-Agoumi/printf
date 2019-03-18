/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magoumi <magoumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 12:49:14 by magoumi           #+#    #+#             */
/*   Updated: 2019/03/18 10:50:03 by magoumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	main(void)
{
	long long int x = 21474836491;

	ft_printf("[mine][% lld]\n", x); // not working case
	printf("[mine][% lld]\n", x); // not working case
	return (0);
}
