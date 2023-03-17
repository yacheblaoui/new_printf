# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yachebla <yachebla@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/16 12:53:34 by yachebla          #+#    #+#              #
#    Updated: 2023/03/17 17:39:45 by yachebla         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CFLAGS = -Wall -Wextra -Werror

CC = cc

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