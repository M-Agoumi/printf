
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magoumi <magoumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 12:49:14 by magoumi           #+#    #+#             */
/*   Updated: 2019/04/16 12:13:28 by magoumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	main(void)
{
	unsigned long		nb;
	nb = 12356549864789;
	ft_printf("[test o:%lo]\n", nb);printf("[test o:%lo]\n", nb);
	ft_printf("[hash:%#lo]\n", nb);printf("[hash:%#lo]\n", nb);
	ft_printf("[precision / grande:%.5lo]\n", nb);printf("[precision / grande:%.5lo]\n", nb);
	ft_printf("[precision / petite:%.0lo]\n", nb);printf("[precision / petite:%.0lo]\n", nb);
	ft_printf("[Prec + hash / grande:%#.5lo]\n", nb);printf("[Prec + hash / grande:%#.5lo]\n", nb);
	ft_printf("[Prec + hash / petite:%#.1lo]\n", nb);printf("[Prec + hash / petite:%#.1lo]\n", nb);
	ft_printf("[Prec + 0:%0.5lo]\n", nb);printf("[Prec + 0:%0.5lo]\n", nb);
	ft_printf("[Prec + minus:%-.5lo]\n", nb);printf("[Prec + minus:%-.5lo]\n", nb);
	ft_printf("[Size:%5lo]\n", nb);printf("[Size:%5lo]\n", nb);
	ft_printf("[size + prec:%7.3lo]\n", nb);printf("[size + prec:%7.3lo]\n", nb);
	ft_printf("[size + minus:%-5lo]\n", nb);printf("[size + minus:%-5lo]\n", nb);
	ft_printf("[size + zero:%05lo]\n", nb);printf("[size + zero:%05lo]\n", nb);
	ft_printf("[size + zero + hash:%#05lo]\n", nb);printf("[size + zero + hash:%#05lo]\n", nb);
	ft_printf("[size + zero + prec:%05.3lo]\n", nb);printf("[size + zero + prec:%05.3lo]\n", nb);
	ft_printf("[size + minus + prec:%-5.3lo]\n", nb);printf("[size + minus + prec:%-5.3lo]\n", nb);
	ft_printf("[size + hash + zero + prec:%#05.3lo]\n", nb);printf("[size + hash + zero + prec:%#05.3lo]\n", nb);
	ft_printf("[size + hash + zero + prec:%0#5.3lo]\n", nb);printf("[size + hash + zero + prec:%0#5.3lo]\n", nb);
	ft_printf("[size + hash + minus + prec:%-#7.3lo]\n", nb);printf("[size + hash + minus + prec:%-#7.3lo]\n", nb);


	/*-----------*/

	return (0);
}
