/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magoumi <magoumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 11:46:29 by magoumi           #+#    #+#             */
/*   Updated: 2019/03/13 14:29:56 by magoumi          ###   ########.fr       */
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
	int		tmp;
	int		x;
	va_list	vl;
}				t_data;

// main function declaration
int				ft_printf(char *str, ...);
// checkers functions
int				ft_argornot(char c);
int				ft_var(t_data *var);
// writing to the consol functions
void			ft_putcharlen(char c, t_data *var);
void			ft_putnbrlen(int nbr, t_data *var);
void			ft_putstrb(char const *str, t_data *var);
int				ft_putstrlen(char *str, int limit, t_data *var);
int				ft_putintlen(int nbr, int limit, t_data *var);
int				ft_putintlenb(int nbr, int x, int limit, t_data *var);
void			ft_putspace(int lim, int nb, t_data *var, int x);
void			ft_put_spaces(int n, t_data *var);
void			ft_putstrb(char const *str, t_data *var);
int				ft_putzeros(char *str, int i, t_data *var);
void			ft_putz(int lim, int nb, t_data *var);
void			ft_putspacebackward(int lim, int nb, t_data *var, int x);
int				ft_putwildstr(int num, char *str, t_data *var);
// functions for the % of ft_printf
int				ft_precision(t_data *var, int i);
int				ft_precisiontwo(char *str, int i, t_data *var);
int				ft_precisiontpre(t_data *var, int i);
int				ft_precisionb(int num, int i, t_data *var);
int				ft_precisiona(t_data *var, int i, int nbr);
int				ft_wildcard(char *str, int i, t_data *var);
int				ft_widthwildtwo(int num, t_data *var);
int				ft_address(char *str, int index, long int decimal, t_data *var);
int				ft_putfloat(t_data *var);
int				ft_dash(int i, t_data *var);
int				ft_widthwild(char *str, int i, t_data *var, int x);//NotItsPlace
// the counters functions
int				ft_nbrlen(int nb);
// the converters functions
int				ft_octal(int n);
// <---(other functions with explainations)--->
// to scap any space when we found one
void			ft_skipspaces(t_data *var, int i);

#endif
