/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magoumi <magoumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 05:40:44 by magoumi           #+#    #+#             */
/*   Updated: 2019/04/07 01:50:00 by magoumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	ft_put_spaces(int n, char *nbr, t_data *var, t_flags *x)
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

static void	ft_put_zero(int n, t_data *var, t_flags *x)
{

	if (n > 0)
		while (n--)
			ft_putcharlen('0', var);
}

static void	ft_precandwidth(t_data *var, char *flag, char *nbr, t_flags *x)
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

static void	ft_putnbrstr(char *nbr, t_flags *x, t_data *var)
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

char *to_hexa(unsigned long long int decimalnum)
{
	long long quotient, remainder;
    int i, j = 0;
    char hexadecimalnum[100];
    char *str;
 
    quotient = decimalnum;
    if (!quotient)
        return ("0");
    while (quotient != 0)
    {
        remainder = quotient % 16;
        if (remainder < 10)
            hexadecimalnum[j++] = 48 + remainder;
        else
            hexadecimalnum[j++] = 87 + remainder;
        quotient = quotient / 16;
    }
	hexadecimalnum[j] = '\0';
	str = ft_strrev(hexadecimalnum);
	//ft_printf("[%d][%s]", i, octal);
	return (str);
}
static void	ft_onlywidth(t_data *var, char *flag, char *nbr, t_flags *x)
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

static void	ft_zero(t_flags *x, t_data *var, char *flag)
{
	int width;

	width = ft_width(flag);
	if (width > 0)
		while (width--)
			ft_putcharlen(' ', var);
	return ;
}

static void	ft_onlypre(t_data *var, char *flag, char *nbr, t_flags *x)
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

static void	ft_longlongint(char *flag, t_data *var, t_flags *x)
{
	long long int	nb;
	char			*nbr;
	int				last;

	nb = va_arg(var->vl, long long int);
	nbr = to_hexa(nb);
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

static void	ft_longint(char *flag, t_data *var, t_flags *x)
{
	long int	nb;
	char		*nbr;
	int			last;
	int			prec;

	nb = va_arg(var->vl, long int);
	nbr = to_hexa(nb);
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

static void	ft_normalint(char *flag, t_data *var, t_flags *x)
{
	int		nb;
	char	*nbr;
	int		last;

	nb = va_arg(var->vl, int);
	nbr = to_hexa(nb);
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

void		ft_intx(char *flag, t_data *var)
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