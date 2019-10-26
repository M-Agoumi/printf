# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: magoumi <magoumi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/20 15:06:21 by magoumi           #+#    #+#              #
#    Updated: 2019/04/23 22:04:42 by magoumi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a 
all: $(NAME)
$(NAME):
	gcc -c -Werror -Wall -Wextra libft/*.c
	ar rc libft.a *.o
	gcc -c *.c libft.a
	ar rc $(NAME) *.o
clean :
	rm -f *.o
fclean : clean
	rm -rf $(NAME) libft.a
re : fclean all
