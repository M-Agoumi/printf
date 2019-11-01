# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: magoumi <agoumihunter@gmail.com>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/04 22:41:07 by magoumi           #+#    #+#              #
#    Updated: 2018/10/29 13:10:25 by magoumi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
HDIR = $(wildcard *.h)
all: $(NAME)
$(NAME):
	gcc -c $(SRC) -Werror -Wall -Wextra *.c
	ar rc $(NAME) *.o
clean :
	rm -f *.o
fclean : clean
	rm -rf $(NAME)
re : fclean all
