/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_width.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magoumi <magoumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 18:54:57 by magoumi           #+#    #+#             */
/*   Updated: 2019/11/01 00:37:26 by magoumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		ft_read_width(char *flag)
{
	char	*nbr;
	int		width;
	int		i;
	int		len;

	i = 0;
	while ((flag[i] > '9' || flag[i] < '0') && flag[i] != '.' && flag[i])
		i++;
	if (flag[i] == '.' && flag[i] == '\0' && !ft_isdigit(flag[i]))
		return (-1);
	len = 0;
	while (flag[i + len] <= '9' && flag[i + len] >= '0' && flag[i + len])
		len++;
	nbr = ft_strsub(flag, i , len);
	width = ft_atoi(nbr);
	return (width);
}

int		ft_is_negative(char *flag)
{
	int	i;

	i = -1;
	while (flag[++i] && flag[i] != '.' && !ft_isdigit(flag[i]))
		if (flag[i] == '-')
			return (1);
	return (0);
}

int		is_zero(char *flag)
{
	int i;

	i = 0;
	while (flag[i])
	{
		if (flag[i] == '0')
			return (1);
		if (flag[i] == '.' || (flag[i] <= '9' && flag[i] >= '0'))
			break ;
		i++;
	}
	return (0);
}

char	*ft_put_width(char *str, char *flag)
{
	char	*spaces;
	int		len;
	int		width;
	int		neg;

	len = ft_read_width(flag);
	if (len == -1)
		return (str);
	width = len - ft_strlen(str);
	if (width <= 0)
		return (str);
	spaces = ft_strnew(width);
	if (is_zero(flag) && (ft_read_precision(flag) == -1))
		ft_memset(spaces, '0', width);
	else
		ft_memset(spaces, ' ', width);
	neg = str[0] == '-' ? 1 : 0;
	if (neg && is_zero(flag))
		str++;
	str = ft_is_negative(flag) ? ft_strjoin(str, spaces) : ft_strjoin(spaces, str);
	str = neg && is_zero(flag) ? ft_strjoin("-", str) : str;
	return (str);
}