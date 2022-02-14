# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmitry <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/26 17:59:18 by dmitry            #+#    #+#              #
#    Updated: 2021/09/26 17:59:22 by dmitry           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= ft_display_file
HEADERS		:= -I includes/ft.h
SRC_FILES	:= ft_display_file.c ft_putchar.c ft_putstr.c
SRC_DIR		:= ./srcs/
SRCS		:= $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ_FILES	:= $(SRC_FILES:.c=.o)
OBJ_DIR		:= ./srcs/
OBJS		:= $(addprefix $(OBJ_DIR), $(OBJ_FILES))
CC			:= gcc
CFLAGS		:= -Wall -Wextra -Werror -c
LFLAGS		:= -Wall -Wextra -Werror -o
RM			:= /bin/rm -f

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) $< -o $@ $(HEADER)

$(NAME):	$(OBJS)
	$(CC) $(LFLAGS) $(NAME) $(OBJS) $(HEADER)

all:	$(SRCS) $(NAME)

clean:
		$(RM) $(OBJS)

fclean:	clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re