/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intxa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magoumi <magoumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 05:40:44 by magoumi           #+#    #+#             */
/*   Updated: 2019/04/29 02:17:53 by magoumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"


char *to_hexa(unsigned long long int decimalnum)
{
	long long quotient, remainder;
	int i, j = 0;
	char hexadecimalnum[100];
	char *str;
	int r;
 
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
	return (str);
}

char *to_hex(unsigned long long int decimalnum)
{
	long long quotient, remainder;
	int i, j = 0;
	char hexadecimalnum[100];
	char *str;
	int r;
 
	quotient = decimalnum;
	if (!quotient)
		return ("0");
	while (quotient != 0)
	{
		remainder = quotient % 16;
		if (remainder < 10)
			hexadecimalnum[j++] = 48 + remainder;
		else
			hexadecimalnum[j++] = 55 + remainder;
		quotient = quotient / 16;
	}
	hexadecimalnum[j] = '\0';
	str = ft_strrev(hexadecimalnum);
	return (str);
}

static void	ft_put_spaces(int n, char *nbr, t_data *var, t_flags *x)
{
	if (n > 0)
	{
		if (!x->zero || (x->zero && x->moin) || (x->prec && !x->zero) ||
		(x->piont && x->zero) || (x->prec && x->zero && !x->negat) || (x->prec && x->width))
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

static void		ft_zx(char *flag, int len, t_data *var)
{
	ft_putcharlen('0', var);
	ft_putcharlen(flag[len], var);
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
	spaces = pre >= len ? width - pre - (x->pnd * 2): (width - len) - (x->pnd * 2);
	if (x->pnd && x->moin)
		ft_zx(flag, ft_strlen(flag) - 1, var);//ft_putstrlen("0x", var);
	if (!x->moin)
	{
		ft_put_spaces(spaces, nbr,var, x);
		if (x->pnd && !x->moin)
			ft_zx(flag, ft_strlen(flag) - 1, var);//ft_putstrlen("0x", var);
		ft_put_prec(nbr, len, pre, var);
	}
	else
	{
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
		ft_putcharlen(nbr[i], var);
}

static void	ft_onlywidth(t_data *var, char *flag, char *nbr, t_flags *x)
{
	int	width;
	int	spaces;
	int len;

	width = ft_width(flag);
	len = ft_strlen(nbr);
	spaces = width - len - (x->pnd * 2);
	if (!(x->pnd && !x->zero) && x->pnd)
			ft_zx(flag, ft_strlen(flag) - 1, var);//ft_putstrlen("0x", var);
	if (x->moin)
	{
		if (x->pnd)
			ft_zx(flag, ft_strlen(flag) - 1, var);//ft_putstrlen("0x", var);
		ft_putstrlen(nbr, var);
		ft_put_spaces(spaces, nbr, var, x);
	}
	else
	{
		ft_put_spaces(spaces, nbr,var, x);
		if (x->pnd && !x->zero)
			ft_zx(flag, ft_strlen(flag) - 1, var);//ft_putstrlen("0x", var);
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
	if (x->pnd)
		ft_zx(flag, ft_strlen(flag) - 1, var);//ft_putstrlen("0x", var);
	ft_put_zero(zeroes, var, x);
	ft_putstrlen(nbr, var);
}

static char		*ft_zxjoin(char *flag, int len, char *nbr, t_data *var)
{
	if (flag[len] == 'x')
		return (ft_strjoin("0x", nbr));
	else
		return (ft_strjoin("0X", nbr));
}
static void	ft_longlongint(char *flag, t_data *var, t_flags *x)
{
	unsigned long long int	nb;
	char			*nbr;
	int				last;

	nb = va_arg(var->vl, unsigned long long int);
	nbr = ft_itoac(nb);
	nbr = flag[ft_strlen(flag) - 1] == 'x' ? to_hexa(nb) : to_hex(nb);
	last = ft_strlen(flag);
	if (x->pnd && !x->prec && !x->width)
		nbr = ft_zxjoin(flag, ft_strlen(flag) - 1, nbr, var);//nbr = ft_strjoin("0x", nbr);
	if (x->prec && x->width)
		ft_precandwidth(var, flag, nbr, x);
	else if (x->width && !x->prec)
		ft_onlywidth(var, flag, nbr, x);
	else if (x->prec && !x->width)
		ft_onlypre(var, flag, nbr, x);
	else
		ft_putstrlen(nbr, var);
	free(nbr);
}

static void	ft_longint(char *flag, t_data *var, t_flags *x)
{
	unsigned long int	nb;
	char		*nbr;
	int			last;
	int			prec;

	nb = va_arg(var->vl, unsigned long int);
	nbr = flag[ft_strlen(flag) - 1] == 'x' ? to_hexa(nb) : to_hex(nb);
	last = ft_strlen(flag);
	if (x->pnd && !x->prec && !x->width)
		nbr = ft_zxjoin(flag, ft_strlen(flag) - 1, nbr, var);//nbr = ft_strjoin("0x", nbr);
	if (x->prec && x->width)
		ft_precandwidth(var, flag, nbr, x);
	else if (x->width && !x->prec)
		ft_onlywidth(var, flag, nbr, x);
	else if (x->prec && !x->width)
		ft_onlypre(var, flag, nbr, x);
	else
		ft_putstrlen(nbr, var);
	free(nbr);
}

static void	ft_normalint(char *flag, t_data *var, t_flags *x)
{
	unsigned int		nb;
	char	*nbr;
	int		last;

	nb = va_arg(var->vl, unsigned int);
	nbr = flag[ft_strlen(flag) - 1] == 'x' ? to_hexa(nb) : to_hex(nb);
	last = ft_strlen(flag);
	if (x->pnd && !x->prec && !x->width)
		nbr = ft_zxjoin(flag, ft_strlen(flag) - 1, nbr, var);//nbr = ft_strjoin("0x", nbr);
	if (x->prec && x->width)
		ft_precandwidth(var, flag, nbr, x);
	else if (x->width && !x->prec)
		ft_onlywidth(var, flag, nbr, x);
	else if (x->prec && !x->width)
		ft_onlypre(var, flag, nbr, x);
	else
		ft_putstrlen(nbr, var);
	free(nbr);
}

void		ft_intx(char *flag, t_data *var)
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