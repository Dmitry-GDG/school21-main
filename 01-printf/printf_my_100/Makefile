# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: trurgot <trurgot@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/06 07:03:56 by trurgot           #+#    #+#              #
#    Updated: 2021/11/21 12:47:07 by trurgot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# gcc -Wall -Wextra -Werror -c *.c
# ar rc libft.a *.o
# ranlib libft.a;
# rm *.o;
# 
# $@ is the name of the target being generated, and $< the first prerequisite 
# (usually a source file). 
# You can find a list of all these special variables in the GNU Make manual.  
# For example, consider the following declaration:  
# 	all: library.cpp main.cpp  
# In this case:  
# $@ evaluates to all  
# $< evaluates to library.cpp  
# $^ evaluates to library.cpp main.cpp
# 
# -o - оптимизация

NAME	= libftprintf.a
HEAD	= ft_printf.h
SRCS	= 	ft_print_cs.c \
			ft_print_d.c \
			ft_print_p.c \
			ft_print_u.c \
			ft_print_xx.c \
			ft_printf.c 

OBJS	= $(SRCS:.c=.o)
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

.PHONY : all re clean fclean

all : $(NAME)

$(NAME) : $(OBJS) $(HEAD)
	ar rcs $(NAME) $?

%.o : %.c
	$(CC) -O2 $(CFLAGS) -c $< -o $@

clean :
	rm -f $(OBJS) $(OBJS_BONUS)

fclean : clean
	rm -f $(NAME)

re : fclean all
