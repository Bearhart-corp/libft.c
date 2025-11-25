# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbelard <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/18 18:38:08 by tbelard           #+#    #+#              #
#    Updated: 2025/11/18 18:38:10 by tbelard          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = gnl.a

CC = cc

CFLAGS = -Wall -Werror -Wextra

SRC = get_next_line_utils.c \
		 get_next_line.c

OBJ = $(SRC:.c=.o)

all: $(NAME)
$(NAME) : $(OBJ)
	ar rsc $(NAME) $(OBJ)
bonus: $(NAME)

%.o: %.c get_next_line.h
	$(CC) $(CFLAGS) -c $< -o $@

clean: 
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean bonus re
