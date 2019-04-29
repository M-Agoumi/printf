/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magoumi <magoumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 15:16:36 by magoumi           #+#    #+#             */
/*   Updated: 2019/04/23 23:19:38 by magoumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*ft_nullornot(char *str)
{
	if (str)
		return(ft_strdup(str));
	return (ft_strdup("(null)"));
}

void	ft_normalstr(char *flag, t_data *var, t_flags *x)
{
	char *str;

	str = ft_nullornot(va_arg(var->vl, char *));
	ft_putstrlen(str, var);
	free(str);
}

void	ft_onlywidthstr(t_data *var, char *flag, t_flags *x)
{
	int		width;
	int		len;
	int		i;
	char	*str;

	width = ft_width(flag);
	str = ft_nullornot(va_arg(var->vl, char *));
	len = ft_strlen(str);
	//ft_printf("[%d][%d]", width, len);
	i = -1;
	if (x->moin) {
		ft_putstrlen(str, var);
		while (++i < width - len)
			ft_putcharlen(' ', var);
	}
	else
	{
		while (++i < width - len)
			ft_putcharlen(' ', var);
		ft_putstrlen(str, var);
	}
	free(str);
}

void	ft_onlyprecstr(t_data *var, char *flag, t_flags *x)
{
	int		prec;
	char	*str;
	int		i;

	prec = ft_precision(flag, var);
	str = ft_nullornot(va_arg(var->vl, char *));
	i = 0;
	while (i < prec && str[i])
		ft_putcharlen(str[i++], var);
	free(str);
}

void	ft_putchartilln(t_data *var, char *str, int n)
{
	int i;

	i = 0;
	while(i < n && str[i])
		ft_putcharlen(str[i++], var);
	
}

void	ft_preandwidstr(t_data *var, char *flag, t_flags *x)
{
	int		width;
	int		prec;
	int		i;
	int		len;
	char	*str;

	width = ft_width(flag);
	prec = ft_precision(flag, var);
	str = ft_nullornot(va_arg(var->vl, char *));
	len = ft_strlen(str);
	i = len >= prec ? prec : len;
	if (x->moin) {
		ft_putchartilln(var, str, i);
		while (++i <= width)
			ft_putcharlen(' ', var);
	}
	else
	{
		while (++i <= width)
			ft_putcharlen(' ', var);
		ft_putchartilln(var, str, prec);
	}
	free(str);
}

void	ft_str(char *flag, t_data *var)
{
	t_flags x;

	ft_initflags(&x);
	ft_checkflags(&x, flag);
	//printf("[flag  %s]", flag);
	if (x.prec && x.width)
		ft_preandwidstr(var, flag, &x);
	else if(x.width && !x.prec)
		ft_onlywidthstr(var, flag, &x);
	else if(!x.width && x.prec)
		ft_onlyprecstr(var, flag, &x);
	else
		ft_normalstr(flag, var, &x);
}