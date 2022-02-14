# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: trurgot <trurgot@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/26 09:53:40 by trurgot           #+#    #+#              #
#    Updated: 2022/02/13 12:51:57 by trurgot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	philo_bonus

HEAD	=	philo.h

SRCS	=	philo.c \
			play_game.c \
			return_mssgs.c \
			utils.c \
			start_game.c 

OBJS	=	$(SRCS:.c=.o)

CC		=	cc
CFLAGS	=	-O2 -Wall -Wextra -Werror
# CFLAGS 	=	-Wall -Wextra -Werror -g -fsanitize=address
# CFLAGS 	=	-Wall -Wextra -Werror -g -fsanitize=thread

RM		=	rm -f

.PHONY	:	all clean fclean re

all		:	$(NAME)

$(NAME)	:	$(OBJS)
			$(CC) $(CFLAGS) -o $@ $(OBJS) 

%.o		:	%.c $(HEAD) Makefile
			$(CC) -Wall -Wextra -Werror -c $< -o $@

clean	:
			$(RM) $(OBJS)

fclean	:	clean
			$(RM) $(NAME)

re		:	fclean all
