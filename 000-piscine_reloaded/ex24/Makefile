# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmitry <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/26 12:45:26 by dmitry            #+#    #+#              #
#    Updated: 2021/09/26 12:45:31 by dmitry           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME		:= libft.a
HEADER		:= -I includes/ft.h
SRC_FILES	:= ft_putchar.c ft_putstr.c ft_strcmp.c ft_strlen.c ft_swap.c
SRC_DIR		:= ./srcs/
SRCS		:= $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ_FILES	:= $(SRC_FILES:.c=.o)
OBJ_DIR		:= ./srcs/
OBJS		:= $(addprefix $(OBJ_DIR), $(OBJ_FILES))
CC			:= gcc
CFLAGS		:= -Wall -Wextra -Werror -c
#LFLAGS		:= -Wall -Wextra -Werror -o
RM			:= /bin/rm -f

.c.o:
	$(CC) $(CFLAGS) $< -o $@ $(HEADER)
#			$(CC) $(CFLAGS) $< -o $($<:.c=.o) -I $(HEADER)

$(NAME):	$(OBJS)
			ar rc $(NAME) $(OBJS)
			ranlib $(NAME)

all:		$(NAME)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re