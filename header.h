/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magoumi <magoumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 11:46:29 by magoumi           #+#    #+#             */
/*   Updated: 2019/04/24 14:41:17 by magoumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include "libft/libft.h"
# include <stdarg.h>
# include <stdio.h>

// the data structure for this project
typedef	struct	s_data
{
	char	*str;
	int		i;
	int		len;
	va_list	vl;
}				t_data;

typedef	struct	s_case
{
	char	h;
	char	zero;
	char	plus;
	char	moin;
	char	ln;
	char	lnln;
	char	prec;
	char	width;
	char	space;
	char	negat;
	char	piont;
	char	pnd;
	char	star;
}				t_flags;

int		ft_printf(char *str, ...);
void    ft_putcharlen(char c, t_data *var);
void    ft_putstrlen(char *str, t_data *var);
int		ft_var(t_data *var);
void	ft_int(char *flag, t_data *var);
char	*ft_itoab(long long int n);
void	ft_str(char *flag, t_data *var);
void	ft_initflags(t_flags *flag);
void	ft_checkflags(t_flags *flag, char *flags);
int		ft_checkpiont(char *flag);
int		ft_checkforzero(char *flag);
int		ft_width(char *flag);
int		ft_precision(char *flag, t_data *var);
void	ft_address(t_data *var, char *flag);
void	ft_octal(char *flag, t_data *var);
void	ft_put_prec(char *nbr, int len, int pre, t_data *var);
char	*ft_itoac(long long int n);
void    ft_char(char *flag, t_data *var);
void	ft_intx(char *flag, t_data *var);
int		ft_precentage(t_data *var, int i);

#endif
