# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: magoumi <magoumi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/20 15:06:21 by magoumi           #+#    #+#              #
#    Updated: 2019/02/20 15:26:48 by magoumi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a 
all: $(NAME)
$(NAME):
	gcc -c -Werror -Wall -Wextra libft/*.c
	ar rc libft.a *.o
	gcc ft_printf.c libft.a -c
	ar rc $(NAME) *.o
clean :
	rm -f *.o
fclean : clean
	rm -rf $(NAME) libft.a
re : fclean all
