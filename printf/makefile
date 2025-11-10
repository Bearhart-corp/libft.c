# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbelard <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/07 14:06:08 by tbelard           #+#    #+#              #
#    Updated: 2025/11/07 14:06:10 by tbelard          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Werror -Wextra

SRC = ft_putchar_fd.c \
	ft_putnbr_fd.c \
	ft_putstr_fd.c \
	ft_strlen.c \
	ft_tolower.c \
	ft_putfloat.c \
	ft_toupper.c 

OBJ = $(SRC:.c=.o)

all: $(NAME)
$(NAME) : $(OBJ)
	ar rsc $(NAME) $(OBJ)

%.o: %.c libftprintf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean: 
	rm -rf $(OBJ) 

fclean: clean
	rm -rf $(NAME)

re: fclean clean

.PHONY: all clean fclean re
