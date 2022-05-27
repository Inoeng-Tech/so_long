# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aafrida <aafrida@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/30 15:30:41 by aafrida           #+#    #+#              #
#    Updated: 2022/05/21 13:53:39 by aafrida          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	=	so_long.a

CFLAGS	=	-Wall -Werror -Wextra

%.o: %.C
			gcc $(CFLAGS) -Imlx -c $< -o $@

SRC	=	

so_long:	$(OBJS)
					cd mlx && make
					cd ft_printf && make
					gcc $(OBJS) ft_printf/Libft/libft.a libxml.dzlib -o $@

all: 		so_long
 
clean	:
			cd xml && make clean
			cd ft_printf && make clean
			rm -ff $(OBJS)

fclean	:	clean
			rm -rf so_long
			rm -rf ft_printf/Libft/libft.a
			rm -rf libxml.a
re	: fclean all
