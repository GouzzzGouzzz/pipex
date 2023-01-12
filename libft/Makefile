# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmorandi <nmorandi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/06 14:02:56 by nmorandi          #+#    #+#              #
#    Updated: 2022/12/15 14:33:49 by nmorandi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft.a
CFLAGS=-Wall -Werror -Wextra
CC=cc
MANDATORY=ft_atoi.c	 			\
		ft_bzero.c	 			\
		ft_calloc.c	 			\
		ft_isalnum.c			\
		ft_isalpha.c			\
		ft_isascii.c			\
		ft_isdigit.c			\
		ft_isprint.c 			\
		ft_itoa.c 				\
		ft_memchr.c 			\
		ft_memcmp.c 			\
		ft_memcpy.c 			\
		ft_memmove.c 			\
		ft_memset.c 			\
		ft_putchar_fd.c 		\
		ft_putendl_fd.c 		\
		ft_putnbr_fd.c 			\
		ft_putstr_fd.c 			\
		ft_split.c 				\
		ft_strchr.c 			\
		ft_strdup.c 			\
		ft_striteri.c 			\
		ft_strjoin.c 			\
		ft_strlcat.c 			\
		ft_strlcpy.c 			\
		ft_strlen.c 			\
		ft_strmapi.c 			\
		ft_strncmp.c 			\
		ft_strnstr.c 			\
		ft_strrchr.c			\
		ft_strtrim.c 			\
		ft_substr.c 			\
		ft_tolower.c 			\
		ft_toupper.c 			\
		get_next_line.c 		\
		get_next_line_utils.c	\

BONUS=ft_lstsize.c		\
	ft_lstnew.c			\
	ft_lstmap.c 		\
	ft_lstlast.c 		\
	ft_lstiter.c 		\
	ft_lstdelone.c 		\
	ft_lstclear.c 		\
	ft_lstadd_front.c	\
	ft_lstadd_back.c 	\

OBJ=$(MANDATORY:.c=.o)

ifdef DO_BONUS
	MANDATORY += $(BONUS)
endif

all: $(NAME)

%.o : %.c
	$(CC) -c $(CFLAGS) -o $@ $<

$(NAME): $(OBJ)
	$(CC) $(CLFAGS) -c $(MANDATORY)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus:
	make DO_BONUS=1;

.PHONY: all clean fclean re bonus