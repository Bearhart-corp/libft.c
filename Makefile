# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbelard <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/29 15:59:23 by tbelard           #+#    #+#              #
#    Updated: 2025/10/29 15:59:25 by tbelard          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc

CFLAGS = -Werror -Wextra -Wall

SRC = $(wildcard ft_*.c)

SRC_BONUS = $(wildcard ft_lst*.c)

OBJ_BONUS = $(SRC_BONUS:.c=.o)

OBJ = $(SRC:.c=.o)

preums: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

bonus: $(OBJ) $(OBJ_BONUS)
	ar rcs $(NAME) $(OBJ) $(OBJ_BONUS)

%.o: %.c libft.h
	$(CC) $(CFLAGS) -c $< -o $@
#EQUIVALENT cc -Wall -Wextra -Werror -c main.c -o main.o
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(SNAME)

re: fclean preums

.PHONY: preums clean fclean re