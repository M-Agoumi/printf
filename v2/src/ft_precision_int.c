/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision_int.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magoumi <magoumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 20:08:06 by magoumi           #+#    #+#             */
/*   Updated: 2019/10/29 20:43:07 by magoumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_put_prec_int(char *nbr, char *flag)
{
	int		prec;
	int		len;
	int		neg;
	char	*newstr;

	prec = ft_read_precision(flag);
	if (prec == -1)
		return (nbr);
	neg = nbr[0] == '-' ? 1 : 0;
	if (neg)
		nbr = ft_strsub(nbr, 1, ft_strlen(nbr) - 1);
	len = ft_strlen(nbr);
	if (prec < len)
		return(nbr);
	len = prec - len;
	newstr = ft_strnew(len + neg);
	ft_memset(newstr, '0', len + neg);
	newstr[0] = neg ? '-' : '0';
	newstr = ft_strjoin(newstr, nbr);
	return (newstr);
}