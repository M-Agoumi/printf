/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_width.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magoumi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 10:18:03 by magoumi           #+#    #+#             */
/*   Updated: 2019/11/14 10:18:05 by magoumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_extend_s(t_flags *f, char *s, int k, char left)
{
	char *tmp;

	if (left == '+')
	{
		while (k-- > 0)
		{
			tmp = s;
			s = ft_strjoin(" ", tmp);
		}
		return (s);
	}
	if (!ft_strlen(s))
	{
		write(1, s, 1);
		if (f->conv == 'c' || f->conv == 'C')
			f->s_size--;
		f->total_size++;
	}
	while (k-- > 0)
	{
		tmp = s;
		s = ft_strjoin(tmp, " ");
	}
	return (s);
}

char	*ft_min_width(char *s, t_flags *f)
{
	intmax_t	i;
	char		*tmp;

	i = ft_strlen(s);
	if ((f->conv == 'd' || f->conv == 'i' || f->conv == 'e' ||
		f->conv == 'E' || f->conv == 'f' || f->conv == 'F' ||
		f->conv == 'g' || f->conv == 'G') &&
		i > 0 && s[0] != '-' && f->plus == 1)
	{
		tmp = s;
		s = ft_strjoin("+", tmp);
		f->min_width -= 1;
	}
	if (i > f->min_width)
		return (s);
	if (f->minus == 1)
		return (ft_extend_s(f, s, f->min_width - i, '-'));
	return (ft_extend_s(f, s, f->min_width - i, '+'));
}
