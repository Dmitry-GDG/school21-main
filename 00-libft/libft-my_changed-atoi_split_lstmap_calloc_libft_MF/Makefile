# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: trurgot <trurgot@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/06 07:03:56 by trurgot           #+#    #+#              #
#    Updated: 2021/11/26 08:01:09 by trurgot          ###   ########.fr        #
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

NAME	:= libft.a
HEAD	:= libft.h
SRCS	:= 	ft_atoi.c \
			ft_bzero.c \
			ft_calloc.c \
			ft_isalnum.c \
			ft_isalpha.c \
			ft_isascii.c \
			ft_isdigit.c \
			ft_isprint.c \
			ft_itoa.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_memset.c \
			ft_putchar_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_putstr_fd.c \
			ft_split.c \
			ft_strchr.c \
			ft_strdup.c \
			ft_striteri.c \
			ft_strjoin.c \
			ft_strlcat.c \
			ft_strlcpy.c \
			ft_strlen.c \
			ft_strmapi.c \
			ft_strncmp.c \
			ft_strnstr.c \
			ft_strrchr.c \
			ft_strtrim.c \
			ft_substr.c \
			ft_tolower.c \
			ft_toupper.c

OBJS	:= $(SRCS:.c=.o)
SRCS_BONUS	:= 	ft_lstadd_back.c \
			ft_lstadd_front.c \
			ft_lstclear.c \
			ft_lstdelone.c \
			ft_lstiter.c \
			ft_lstlast.c \
			ft_lstmap.c \
			ft_lstnew.c \
			ft_lstsize.c 

OBJS_BONUS	:= $(SRCS_BONUS:.c=.o)
CC		:= gcc
CFLAGS	:= -Wall -Wextra -Werror -c

.PHONY : all re clean fclean bonus relax

all : $(NAME)

$(NAME) : $(OBJS) $(HEAD)
	ar rcs $(NAME) $?

#$(NAME): $(OBJS)
#	@echo "==============================================================="
#	ar rc $(NAME) $?
#	@echo "$(NAME) created"
#	@echo "==============================================================="
#	ranlib $(NAME)
#	@echo "$(NAME) indexed"

%.o : %.c $(HEAD)
	$(CC) $(CFLAGS) $< -o $@ -I $(HEAD)

bonus : $(OBJS_BONUS) 
	@make OBJS="$(OBJS_BONUS)" 

clean :
#	@echo "===============================================================" 
	/bin/rm -f $(OBJS) $(OBJS_BONUS)
#	@echo "$(RED) ̄\_(ツ)_/ ̄ Objects were removed!$(NOC)"

fclean :		clean
#	@echo "==============================================================="
	/bin/rm -f $(NAME)
#	@echo "$(RED) ̄\_(ツ)_/ ̄ library was removed!$(NOC)"

re :	fclean all

relax :
	@clear
	@echo 
	@echo		.
	@echo		╲╲╭━┻┻┻┻━╮╱╱┏┓╱╱
	@echo		╲╭┫╭━╮╭━┓┣╮╱┣┫╱╱
	@echo		┈┃┃┃▆┃┃▋┃┃┃╭╯╰╮┈
	@echo		┈╰┫┗━╭╮━╯┣╯┃╭╮┃┈
	@echo		┈┈┃╰┳┳━━╯┃┈┃╳╳┃┈
	@echo		╱╱┃╲╰╯╱╱╱┃╲┃╰╯┃╲
	@echo		╱╱╰━┳━━┳━╯╲┗━━┛╲
	@echo
