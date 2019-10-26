# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: magoumi <magoumi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/26 05:22:07 by magoumi           #+#    #+#              #
#    Updated: 2019/10/26 09:53:13 by magoumi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_PATH = src

SRC_NAME = main.c \
			ft_printf.c \
			ft_char.c

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

OBJ_PATH = obj

OBJ_NAME = $(SRC_NAME:.c=.o)

OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

CPPFLAGS =-Iinclude -Ilibft/include

LDFLAGS = -Llibft

LDLIBS = -lft

NAME = test

CC = gcc

CFLAGS = -Wall -Wextra -Werror

.PHONY: all, clean, fclean, re

all: $(NAME)

$(NAME): $(OBJ) 
	   @cd libft ; make
	   $(CC) $^ -o $@ $(LDFLAGS) $(LDLIBS)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	   @mkdir $(OBJ_PATH) 2> /dev/null || true
	   $(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

clean:
	@make -C libft clean
	@rm -vf $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true

fclean: clean
	@make -C libft fclean
	@rm -vf $(NAME)

re: fclean all
