/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magoumi <magoumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 06:10:27 by magoumi           #+#    #+#             */
/*   Updated: 2019/10/31 23:00:25 by magoumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include "libft.h"
# include <stdarg.h>

int		ft_printf(char *format, ...);
int		ft_print_char(char *flag, va_list list);
char	*ft_put_width(char *str, char *flag);
int		ft_is_negative(char *flag);
char	*ft_put_precision(char *str, char *flag);
int		ft_print_str(char *flag, va_list list);
int		ft_print_address(char *flag, va_list list);
int		ft_print_int(char *flag, va_list list);
char	*ft_itoa_long(long long int n);
char	*ft_put_prec_int(char *nbr, char *flag);
int		ft_read_precision(char *flag);
int		ft_print_int_x(char *flag, va_list list);
int		is_long(char *flag);
int		is_long_long(char *flag);
#endif