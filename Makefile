# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmorandi <nmorandi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/18 15:58:39 by nmorandi          #+#    #+#              #
#    Updated: 2023/01/17 13:14:14 by nmorandi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=pipex
CC=cc
CFLAGS=-g
FILES=main.c		\
	parse.c			\


OBJ=$(FILES:.c=.o)

%.o : %.c
	$(CC) -c $(CFLAGS) -o $@ $<

all: submake $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -L ./libft -lft -o $(NAME)

submake:
	(cd ./libft; make all)

subclean:
	(cd ./libft; make clean)

subfclean:
	(cd ./libft; make fclean)

clean: subclean
	rm -f $(OBJ)

fclean: clean subfclean
	rm -f $(NAME)

re: fclean all

.PHONY: all re clean fclean
