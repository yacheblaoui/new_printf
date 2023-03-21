# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yachebla <yachebla@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/16 12:53:34 by yachebla          #+#    #+#              #
#    Updated: 2023/03/20 12:01:59 by yachebla         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CFLAGS = -Wall -Wextra -Werror

HEADER = ft_printf.h

FILES = ft_printf.c ft_printf_utils.c

 OBJ = $(FILES:.c=.o)
 
 all: $(NAME)
 $(NAME): $(OBJ)
		ar src  $(NAME) $(OBJ)

%.o: %.c $(HEADER)
	$(CC) ${CFLAGS} -c $< -o $@ 
	
clean: 
	rm -rf $(OBJ)
fclean: clean
	rm -rf $(NAME)
re : fclean all