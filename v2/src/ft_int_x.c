/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magoumi <magoumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 22:56:00 by magoumi           #+#    #+#             */
/*   Updated: 2019/11/01 00:34:03 by magoumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char *to_hexa(unsigned long long int decimalnum)
{
	long long int	quotient;
	long long int	remainder;
	int				j;
	char			hexadecimalnum[100];
	char			*str;

	j = 0;
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
char	*ft_put_hash(char *flag, char *nbr)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (flag[++i])
		if (flag[i] == '#')
			j = 1;
	if (!j)
		return (nbr);
	if (!ft_strcmp("0", nbr))
		return (nbr);
	return (ft_strjoin("0x", nbr));
}
char	*ft_toupperstring(char *nbr)
{
	int i;

	i = -1;
	while (nbr[++i])
		nbr[i] = ft_toupper(nbr[i]);
	return (nbr);
}

int		ft_print_int_x(char *flag, va_list list)
{
	unsigned long long int	nb;
	char					*nbr;

	if (is_long(flag))
		if (is_long_long(flag))
			nb = va_arg(list, unsigned long long int);
		else
			nb = (unsigned long int)va_arg(list, unsigned long int);
	else
		nb = (unsigned int)va_arg(list, unsigned int);
	nbr = to_hexa(nb);
	nbr = ft_put_prec_int(nbr, flag);
	nbr = ft_put_hash(flag, nbr);
	nbr = ft_put_width(nbr, flag);
	nbr = flag[ft_strlen(flag) - 1] == 'X' ? ft_toupperstring(nbr) : nbr;
	ft_printf("%s", nbr);
	return (ft_strlen(nbr));
}