# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fde-fram <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/22 14:09:57 by fde-fram          #+#    #+#              #
#    Updated: 2019/11/09 14:21:13 by simoulin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

HEADERS = ./

CC = gcc

WALL = -Wall -Wextra -Werror

SRC = ft_atoi.c ft_isdigit.c ft_printf.c ft_putnbr_base.c ft_strlen.c

OBJ = $(SRC:.c=.o)

all	: $(NAME)

%.o: %.c
	$(CC) -I $(HEADERS) -c $(WALL) $< -o $@

$(NAME) : $(OBJ)
	ar -rc $(NAME) $(OBJ)

clean :
	rm -f $(OBJ) $(OBJB)

fclean : clean
	rm -f $(NAME)

re : fclean all
