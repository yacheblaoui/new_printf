# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yachebla <yachebla@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/16 12:53:34 by yachebla          #+#    #+#              #
#    Updated: 2023/03/18 14:05:24 by yachebla         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

HEADER = ft_printf.h

FILES = ft_printf.c ft_printf_utils.c

 OBJ = $(FILES:.c=.o)
 
 all: $(NAME)
 $(NAME): $(HEADER) $(OBJ)
		ar src  $(NAME) $(OBJ)

%.o: %.c ft_printf.h
	$(CC) ${CFLAGS} $< -o $@ -c
	
clean: 
	rm -rf $(OBJ)
fclean: clean
	rm -rf $(NAME)
re : fclean all