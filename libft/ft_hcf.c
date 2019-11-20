/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hcf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magoumi <magoumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 15:36:16 by magoumi           #+#    #+#             */
/*   Updated: 2019/11/20 15:36:20 by magoumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_hcf(unsigned int a, unsigned int b)
{
	unsigned int hcf;
	unsigned int temp;

	hcf = 1;
	temp = 1;
	while (temp <= a && temp <= b)
	{
		if (a % temp == 0 && b % temp == 0)
			hcf = temp;
		temp++;
	}
	return (hcf);
}