/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magoumi <magoumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 11:46:29 by magoumi           #+#    #+#             */
/*   Updated: 2019/03/18 09:35:46 by magoumi          ###   ########.fr       */
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
	char h;
	char zero;
	char plus;
	char moin;
	char ln;
	char lnln;
	char prec;
	char space;
}				t_flags;

int		ft_printf(char *str, ...);
void    ft_putcharlen(char c, t_data *var);
void    ft_putstrlen(char *str, t_data *var);
int		ft_var(t_data *var);
void	ft_int(char *flag, t_data *var);
char	*ft_itoab(long long int n);

#endif
