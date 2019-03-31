/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magoumi <magoumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 05:40:44 by magoumi           #+#    #+#             */
/*   Updated: 2019/03/30 18:29:54 by magoumi          ###   ########.fr       */
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
	flag->width = 0;
	flag->negat = 0;
	flag->piont = 0;
	flag->star = 0;
}

// int		ft_width(char *flag);

int		ft_checkforzero(char *flag)
{
	int i;

	i = 0;
	while (flag[i] == ' ' || flag[i] == '+' || flag[i] == '-' || flag[i] == '#')
		i++;
	if (flag[i] == '0')
		return (1);
	else
		return (0);
}

int		ft_checkpiont(char *flag)
{
	int i;

	i = 0;
	while (flag[i])
	{
		if (flag[i] == '.')
			if (!(flag[i + 1] <= '9' && flag[i + 1] >= '0'))
				return (1);
		i++;
	}
	return (0);
}

void	ft_checkflags(t_flags *flag, char *flags)
{
	int i;
	int	width;

	i = -1;
	if (ft_checkforzero(flags))
		flag->zero = 1;
	while(flags[++i])
	{
		if (flags[i] == 'h')
			flag->h = 1;
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
		if (ft_checkpiont(flags))
			flag->piont = 1;
	}
	width = ft_width(flags);
	if (width && width != -1)
		flag->width = 1;
}

int		ft_width(char *flag)
{
	int		width;
	char	*str;
	int		i;
	int		start;
	int		len;

	i = 0;
	while (!(flag[i] <= '9' && flag[i] >= '1') && flag[i] != '\0')
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
	while (flag[i] != '.' /*&& flag[i]*/)
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

void	ft_put_spaces(int n, char *nbr, t_data *var, t_flags *x)
{
	if ((x->space && !x->negat && nbr[0] != '-') || (x->plus && nbr[0] != '-'))
		n--;
	if (n > 0)
	{
		if (!x->zero || (x->zero && x->moin) || (x->prec && !x->zero) ||
		(x->piont && x->zero) || (x->prec && x->zero && !x->negat))
			while (n--)
				ft_putcharlen(' ', var);
		else
			while (n--)
				ft_putcharlen('0', var);
	}
}

void	ft_put_zero(int n, t_data *var, t_flags *x)
{

	if (n > 0)
		while (n--)
			ft_putcharlen('0', var);
}

void	ft_put_prec(char *nbr, int len, int pre, t_data *var)
{
	int zeros;

	if (pre <= len)
		ft_putstrlen(nbr, var);
	else
	{
		zeros = pre - len;
		while (zeros--)
			ft_putcharlen('0', var);
		ft_putstrlen(nbr, var);	
	}
}

void	ft_precandwidth(t_data *var, char *flag, char *nbr, t_flags *x)
{
	int	width;
	int	pre;
	int	spaces;
	int len;

	width = ft_width(flag);
	pre = ft_precision(flag, var);
	len = ft_strlen(nbr);
	spaces = pre >= len ? width - pre : width - len;
	if (nbr[0] == '-' && x->zero)
		ft_putcharlen('-', var);
	if (!x->moin)
	{
		ft_put_spaces(spaces, nbr,var, x);
		if (x->plus && nbr[0] != '-')
			ft_putcharlen('+', var);
		if (nbr[0] == '-' && x->zero)
			ft_put_prec(nbr + 1, len, pre, var);
		else
			ft_put_prec(nbr, len, pre, var);
	}
	else
	{
		if (x->plus && nbr[0] != '-')
			ft_putcharlen('+', var);
		if (nbr[0] == '-' && x->zero)
			ft_put_prec(nbr + 1, len, pre, var);
		else
			ft_put_prec(nbr, len, pre, var);
		ft_put_spaces(spaces, nbr, var, x);
	}
}

void	ft_putnbrstr(char *nbr, t_flags *x, t_data *var)
{
	int i;

	i = -1;
	if (nbr[0] == '-' && x->zero)
		i++;
	while (nbr[++i] != '\0')
	{
		//ft_putchar('[');ft_putnbr(i);ft_putchar(']');
		ft_putcharlen(nbr[i], var);
	}
}

void	ft_onlywidth(t_data *var, char *flag, char *nbr, t_flags *x)
{
	int	width;
	int	spaces;
	int len;

	width = ft_width(flag);
	len = ft_strlen(nbr);
	spaces = nbr[0] == '-' ? width - len : width - len;
	if (x->plus && nbr[0] != '-' && (!x->zero || (x->zero && x->moin)) && !x->width)
			ft_putcharlen('+', var);
	if ((x->zero && nbr[0] == '-') || (x->moin && nbr[0] == '-'))
		ft_putcharlen('-', var);
	if (x->moin)
	{
		if (x->plus && nbr[0] != '-')
			ft_putcharlen('+', var);
		if (nbr[0] == '-')
			ft_putstrlen(nbr + 1, var);
		else
			ft_putstrlen(nbr, var);
		ft_put_spaces(spaces, nbr, var, x);
	}
	else
	{
		ft_put_spaces(spaces, nbr,var, x);
		if (x->plus && nbr[0] != '-' && !x->zero)
			ft_putcharlen('+', var);
		ft_putnbrstr(nbr, x, var);
	}
}

void	ft_zero(t_flags *x, t_data *var, char *flag)
{
	int width;

	width = ft_width(flag);
	if (width > 0)
		while (width--)
			ft_putcharlen(' ', var);
	return ;
}

void	ft_onlypre(t_data *var, char *flag, char *nbr, t_flags *x)
{
	int	pre;
	int	zeroes;
	int len;

	pre = ft_precision(flag, var);
	len = ft_strlen(nbr);
	if (!ft_strcmp(nbr, "0") && !pre)
		return (ft_zero(x, var, flag));
	if (pre == 0 && !ft_strcmp(nbr, "0"))
		return ;
	zeroes = nbr[0] == '-' ? pre - len + 1: pre - len;
	if (x->plus && nbr[0] != '-')
		ft_putcharlen('+', var);
	if (nbr[0] == '-')
		ft_putcharlen('-', var);
	ft_put_zero(zeroes, var, x);
	if (nbr[0] == '-')
		ft_putstrlen(nbr + 1, var);
	else
		ft_putstrlen(nbr, var);
}

void	ft_longlongint(char *flag, t_data *var, t_flags *x)
{
	long long int	nb;
	char			*nbr;
	int				last;

	nb = va_arg(var->vl, long long int);
	nbr = flag[ft_strlen(flag) - 1] == 'd' ? ft_itoab(nb) : ft_itoab(ft_octal(nb));
	last = ft_strlen(flag);
	if (nb < 0)
		x->negat = 1;
	if (x->space && !x->plus && nb > 0)
		ft_putcharlen(' ', var);
	if (x->prec && x->width)
		ft_precandwidth(var, flag, nbr, x);
	else if (x->width && !x->prec)
		ft_onlywidth(var, flag, nbr, x);
	else if (x->prec && !x->width)
		ft_onlypre(var, flag, nbr, x);
	else//if (flag[last - 1] == 'd')
		ft_putstrlen(nbr, var);
}

void	ft_longint(char *flag, t_data *var, t_flags *x)
{
	long int	nb;
	char		*nbr;
	int			last;
	int			prec;

	nb = va_arg(var->vl, long int);
	nbr = ft_itoab(nb);
	last = ft_strlen(flag);
	if (nb < 0)
		x->negat = 1;
	if (x->space && !x->plus && nb > 0)
		ft_putcharlen(' ', var);
	if (x->prec && x->width)
		ft_precandwidth(var, flag, nbr, x);
	else if (x->width && !x->prec)
		ft_onlywidth(var, flag, nbr, x);
	else if (x->prec && !x->width)
		ft_onlypre(var, flag, nbr, x);
	else//if (flag[last - 1] == 'd')
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
	if (nb < 0)
		x->negat = 1;
	if (x->plus && nb >= 0 && !x->piont && !(x->prec && x->width))
		ft_putcharlen('+', var);
	if (x->space && !x->plus && nb > 0)
		ft_putcharlen(' ', var);
	if (x->prec && x->width)
		ft_precandwidth(var, flag, nbr, x);
	else if (x->width && !x->prec)
		ft_onlywidth(var, flag, nbr, x);
	else if (x->prec && !x->width)
		ft_onlypre(var, flag, nbr, x);
	else
		ft_putstrlen(nbr, var);
}

void	ft_int(char *flag, t_data *var)
{
	t_flags x;

	ft_initflags(&x);
	ft_checkflags(&x, flag);
	//printf("{[%d][%d][%d][%d]}", x.moin, x.plus, x.prec, x.width);
	if (x.ln && !x.lnln)
		ft_longint(flag, var, &x);
	else if(x.lnln)
		ft_longlongint(flag, var, &x);
	else
		ft_normalint(flag, var, &x);
}