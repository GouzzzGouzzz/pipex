# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmorandi <nmorandi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/18 15:58:39 by nmorandi          #+#    #+#              #
#    Updated: 2023/02/01 15:50:19 by nmorandi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=pipex
CC=cc
CFLAGS=-Wall -Werror -Wextra -g
FILES=main.c			\
	utils.c				\
	utils2.c			\
	func/ft_memcpy.c	\
	func/ft_strlen.c	\
	func/ft_strncmp.c	\
	func/ft_strjoin.c	\
	func/ft_split.c		\

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
