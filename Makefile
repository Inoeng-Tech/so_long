# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aafrida <aafrida@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/30 15:30:41 by aafrida           #+#    #+#              #
#    Updated: 2022/04/30 16:47:52 by aafrida          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	=	so_long.a
CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra -Imlx

SRCS	=	

OBJS	=	
RM		=	rm -rf
OPTION 	=	-C 

all: $(NAME)

$(NAME) :
			$(OBJS) GNL(OBJS)

clean	:
			{RM} ${OBJS} $(BONUS_OBJS)

			${RM} */*.o

fclean	:	clean
			${RM}
			${RM} Libft/libft.a

re	: fclean all

PHONY: all clean fclean re