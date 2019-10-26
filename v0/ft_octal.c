/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_octal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magoumi <magoumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 00:16:38 by magoumi           #+#    #+#             */
/*   Updated: 2019/04/29 11:06:28 by magoumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

unsigned long long int     to_longlongoctal(unsigned long long int n)
{
    unsigned long long int i;
	unsigned long long int octal;

	octal = 0;
	i = 1;
	while (n > 0)
	{
		octal = octal + (n % 8) * i;
		i = i * 10;
		n = n / 8;
	}
	return (octal);
}

unsigned long long int     to_longoctal(unsigned long int n)
{
    unsigned long int i;
	unsigned long int octal;

	octal = 0;
	i = 1;
	while (n > 0)
	{
		octal = octal + (n % 8) * i;
		i = i * 10;
		n = n / 8;
	}
	return (octal);
}

char *decToOctal(unsigned long long int n)
{
	char	octalNum[100];
	char	*octal;

	int i = 0;
	if (!n)
		return("0");
	while (n != 0)
	{
		octalNum[i] = n % 8 + '0';
		n = n / 8;
		i++;
	}
	octalNum[i] = '\0';
	octal = ft_strrev(octalNum);
	//ft_printf("[%d][%s]", i, octal);
	return (octal);
}

unsigned long long int     to_octal(unsigned int n)
{
    unsigned int i;
	unsigned int octal;

	octal = 0;
	i = 1;
	while (n > 0)
	{
		octal = octal + (n % 8) * i;
		i = i * 10;
		n = n / 8;
	}
	return (octal);
}

static void	ft_put_spaces(int n, char *nbr, t_data *var, t_flags *x)
{
	if ((x->space && !x->negat && nbr[0] != '-'))
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
	//ft_printf("[s-%d-][p-%d-][w-%d-][l-%d-]", spaces, pre, width, len);
	if (x->pnd && ft_strcmp(nbr, "0") && !(pre > len))
		spaces--;
	if (nbr[0] == '-' && x->zero)
		ft_putcharlen('-', var);
	if (!x->moin)
	{
		ft_put_spaces(spaces, nbr,var, x);
		if (x->pnd && ft_strcmp(nbr, "0") && !(pre > len))
			ft_putcharlen('0', var);
		ft_put_prec(nbr, len, pre, var);
	}
	else
	{
		if (x->pnd && ft_strcmp(nbr, "0") && !(pre > len))
			ft_putcharlen('0', var);
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

static void	ft_onlywidth(t_data *var, char *flag, char *nbr, t_flags *x)
{
	int	width;
	int	spaces;
	int len;

	width = ft_width(flag);
	len = ft_strlen(nbr);
	spaces = width - len;
	if (x->pnd && ft_strcmp(nbr, "0"))
		spaces--;
	if (x->moin)
	{
		if (x->pnd && ft_strcmp(nbr, "0"))
			ft_putcharlen('0', var);
		ft_putstrlen(nbr, var);
		ft_put_spaces(spaces, nbr, var, x);
	}
	else
	{
		ft_put_spaces(spaces, nbr,var, x);
		if (x->pnd && ft_strcmp(nbr, "0"))
			ft_putcharlen('0', var);
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
	if (x->pnd && ft_strcmp("0", nbr))
	{
		ft_putcharlen('0', var);
		zeroes--;
	}
	ft_put_zero(zeroes, var, x);
	if (nbr[0] == '-')
		ft_putstrlen(nbr + 1, var);
	else
		ft_putstrlen(nbr, var);
}

static void	ft_longlongoctal(char *flag, t_data *var, t_flags *x)
{
	long long int	nb;
	char			*nbr;
	int				last;

	nb = va_arg(var->vl, long long int);
	nbr = decToOctal(nb);
	last = ft_strlen(flag);
	if (nb < 0)
		x->negat = 1;
	if (x->prec && x->width)
		ft_precandwidth(var, flag, nbr, x);
	else if (x->width && !x->prec)
		ft_onlywidth(var, flag, nbr, x);
	else if (x->prec && !x->width)
		ft_onlypre(var, flag, nbr, x);
	else
	{
		if (x->pnd && nb)
			ft_putcharlen('0', var);
		ft_putstrlen(nbr, var);
	}
}

static void	ft_longoctal(char *flag, t_data *var, t_flags *x)
{
	long int	nb;
	char		*nbr;
	int			last;
	int			prec;

	nb = va_arg(var->vl, long int);
	nbr = decToOctal(nb);
	last = ft_strlen(flag);
	if (nb < 0)
		x->negat = 1;
	if (x->prec && x->width)
		ft_precandwidth(var, flag, nbr, x);
	else if (x->width && !x->prec)
		ft_onlywidth(var, flag, nbr, x);
	else if (x->prec && !x->width)
		ft_onlypre(var, flag, nbr, x);
	else
	{
		if (x->pnd && nb)
			ft_putcharlen('0', var);
		ft_putstrlen(nbr, var);
	}
}

static void	ft_normalocatl(char *flag, t_data *var, t_flags *x)
{
	unsigned int		nb;
	char	*nbr;
	int		last;

	nb = va_arg(var->vl, unsigned int);
	nbr = decToOctal(nb);
	last = ft_strlen(flag);
	if (x->prec && x->width)
		ft_precandwidth(var, flag, nbr, x);
	else if (x->width && !x->prec)
		ft_onlywidth(var, flag, nbr, x);
	else if (x->prec && !x->width)
		ft_onlypre(var, flag, nbr, x);
	else
	{
		if (x->pnd && nb)
			ft_putcharlen('0', var);
		ft_putstrlen(nbr, var);
	}
}

void			ft_octal(char *flag, t_data *var)
{
	t_flags x;

	ft_initflags(&x);
	ft_checkflags(&x, flag);
	if (x.ln && !x.lnln)
		ft_longoctal(flag, var, &x);
	else if(x.lnln)
		ft_longlongoctal(flag, var, &x);
	else
		ft_normalocatl(flag, var, &x);
}