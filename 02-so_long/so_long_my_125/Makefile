# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: trurgot <trurgot@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/10 13:05:59 by trurgot           #+#    #+#              #
#    Updated: 2022/01/15 19:50:30 by trurgot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	so_long
NAME_BONUS	=	so_long_bonus
LIBFT		=	libft/libft.a
MINILIBX	=	minilibx/libmlx.dylib

SRCS		= 	src/free_all.c src/main.c src/so_long.c src/so_long_utils.c \
				src/check_map.c src/play_game.c src/make_step.c

SRCS_BONUS	=	src_bonus/check_map_bonus.c src_bonus/free_all_bonus.c \
				src_bonus/main_bonus.c src_bonus/make_step_bonus.c \
				src_bonus/play_game_bonus.c src_bonus/so_long_bonus.c \
				src_bonus/so_long_utils_bonus.c src_bonus/put_text_bonus.c \
				src_bonus/store_imgs_bonus.c

OBJS		=	$(SRCS:.c=.o)
OBJS_BONUS	=	$(SRCS_BONUS:.c=.o)

HEAD		=	src/so_long.h
HEAD_BONUS	=	src_bonus/so_long_bonus.h
CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
# C_FLAGS = -Wall -Wextra -Werror -fsanitize=address

.PHONY		:	all clean fclean re libfta bonus 

all			:	$(NAME)

$(NAME)		:	$(LIBFT) $(MINILIBX) $(OBJS)
				$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -L minilibx -lmlx -framework OpenGL -framework AppKit -lz -o $(NAME)

bonus		:	$(LIBFT) $(MINILIBX)
				@make NAME="$(NAME_BONUS)" OBJS="$(OBJS_BONUS)" HEAD="$(HEAD_BONUS)" all

%.o			:	%.c $(HEAD) Makefile
				$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT)	:
				@make -C libft

$(MINILIBX)	:
				@make -C minilibx
				cp $(MINILIBX) .

clean		:
				rm -f $(OBJS) $(OBJS_BONUS)
				@make -C minilibx clean
				@make -C libft clean
	
fclean		:	clean
				rm -f so_long so_long_bonus libft/libft.a libmlx.dylib 

re			:	fclean all
