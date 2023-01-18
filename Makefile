# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gouz <gouz@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/18 15:58:39 by nmorandi          #+#    #+#              #
#    Updated: 2023/01/18 04:34:58 by gouz             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=pipex
CC=cc
CFLAGS=-g
FILES=main.c			\
	parse.c				\
	utils/ft_memcpy.c	\
	utils/ft_strlen.c	\
	utils/ft_strncmp.c	\
	utils/ft_strjoin.c	\
	utils/ft_split.c	\

OBJ=$(FILES:.c=.o)

%.o : %.c
	$(CC) -c $(CFLAGS) -o $@ $<

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all re clean fclean
