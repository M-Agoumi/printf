/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_precision.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magoumi <magoumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 22:01:27 by magoumi           #+#    #+#             */
/*   Updated: 2019/10/27 22:23:19 by magoumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		ft_read_precision(char *flag)
{
	int		prec;
	char	*nbr;
	int		i;
	int		len;

	i = 0;
	while (flag[i] != '.' && flag[i])
		i++;
	if (flag[i] != '.')
		return (-1);
	len = 0;
	i++;
	while (flag[i + len] <= '9' && flag[i + len] >= '0')
		len++;
	nbr = ft_strsub(flag, i, len);
	//printf("\n\n[i=>%d][flag[i]=>%c][len=>%d][nbr=>%s]\n\n", i,flag[i], len, nbr);
	prec = ft_atoi(nbr);
	return (prec);
}
char	*ft_put_precision(char *str, char *flag)
{
	int		prec;
	char	*newstr;

	prec = ft_read_precision(flag);
	if (prec == -1)
		return (str);
	if (prec < (int)ft_strlen(str))
		newstr = ft_strsub(str, 0, prec);
	else
		newstr = ft_strdup(str);
	return (newstr);
}