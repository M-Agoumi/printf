/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magoumi <magoumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 05:40:44 by magoumi           #+#    #+#             */
/*   Updated: 2019/03/18 10:49:48 by magoumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_initflags(t_flags *flag)
{
	flag->h = 0;
	flag->zero = 0;
	flag->plus = 0;
	flag->moin = 0;
	flag->ln = 0;
	flag->lnln = 0;
    flag->prec = 0;
	flag->space = 0;
}

void	ft_checkflags(t_flags *flag, char *flags)
{
	int i;

	i = -1;
	while(flags[++i])
	{
		if (flags[i] == 'h')
			flag->h = 1;
		if (flags[i] == '0')
			flag->zero = 1;
		if (flags[i] == '+')
			flag->plus = 1;
		if (flags[i] == '-')
			flag->moin = 1;
		if (flags[i] == 'l')
			flag->ln = 1;
		if (flags[i] == 'l' && flag->ln == 1)
			flag->lnln = 1;
        if (flags[i] == '.')
			flag->prec = 1;
		if (flags[i] == ' ')
			flag->space = 1;
	}
}

int		ft_width(char *flag)
{
	int		width;
	char	*str;
	int		i;
	int		start;
	int		len;

	i = 0;
	while (!(flag[i] <= '9' && flag[i] >= '0') && flag[i] != '\0')
		i++;
	if (i == ft_strlen(flag))
		return(-1);
	start = i;
	len = 0;
	if (flag[i - 1] != '.')
	{
		while (flag[i + len] <= '9' && flag[i + len] >= '0')
			len++;
		str = ft_strsub(flag, i, len);
		width = ft_atoi(str);
		free(str);
		return (width);
	}
	else
		return (-1);
}

int		ft_precision(char *flag, t_data *var)
{
	int		prec;
	char	*str;
	int		i;
	int		start;
	int		len;

	i = 0;
	while (flag[i] != '.')
		i++;
	start = i;
	len = 0;
	if (flag[i + 1] == '*')
		prec = va_arg(var->vl, int);
	else
	{
		while (flag[i + len + 1] <= '9' && flag[i + len + 1] >= '0')
			len++;
		str = ft_strsub(flag, i + 1, len);
		prec = ft_atoi(str);
		free(str);
	}
	return (prec);
}

void	ft_longlongint(char *flag, t_data *var, t_flags *x)
{
	long long int	nb;
	char			*nbr;
	int				last;
	int				width;
	int				prec;

	nb = va_arg(var->vl, long long int);
	nbr = ft_itoab(nb);
	last = ft_strlen(flag);
	if (x->moin && !x->plus)
		ft_putcharlen('-', var);
	if (x->plus && nb >=0)
		ft_putcharlen('+', var);
	if (x->space && !x->plus)
		ft_putcharlen(' ', var);
	width = ft_width(flag);
	if (width != -1)
		ft_printf("[%d]", width);
	if (x->prec)
		ft_printf("[%d]",ft_precision(flag, var));
	if (flag[last - 1] == 'd')
		ft_putstrlen(nbr, var);
}

void	ft_longint(char *flag, t_data *var, t_flags *x)
{
	long int	nb;
	char		*nbr;
	int			last;
	int			width;

	nb = va_arg(var->vl, long int);
	nbr = ft_itoab((long long int)nb);
	last = ft_strlen(flag);
	if (x->moin && !x->plus)
		ft_putcharlen('-', var);
	if (x->plus && nb >=0)
		ft_putcharlen('+', var);
	if (x->space && !x->plus)
		ft_putcharlen(' ', var);
	if (ft_width(flag) != -1)
		ft_printf("[width]");
	if (flag[last - 1] == 'd')
		ft_putstrlen(nbr, var);

}

void	ft_normalint(char *flag, t_data *var, t_flags *x)
{
	int		nb;
	char	*nbr;
	int		last;

	nb = va_arg(var->vl, int);
	nbr = ft_itoab(nb);
	last = ft_strlen(flag);
	if (flag[last - 1] == 'd')
		ft_putstrlen(nbr, var);
}

void	ft_int(char *flag, t_data *var)
{
	t_flags x;

	ft_initflags(&x);
	ft_checkflags(&x, flag);
	if (x.ln && !x.lnln)
		ft_longint(flag, var, &x);
	else if(x.lnln)
		ft_longlongint(flag, var, &x);
	else
		ft_normalint(flag, var, &x);
}