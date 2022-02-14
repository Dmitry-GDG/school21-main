# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: trurgot <trurgot@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/06 07:03:56 by trurgot           #+#    #+#              #
#    Updated: 2022/01/13 08:46:52 by trurgot          ###   ########.fr        #
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
# -O2 - optimization

PUSH_SWAP_SRCS = src/ft_str_int_dup.c  \
			src/index_lst.c src/instructions_p.c  \
			src/instructions_r.c src/instructions_rr.c src/instructions_s.c \
			src/my_atoi.c src/my_freeall.c src/my_sort_dblclst.c \
			src/push_swap_main.c src/push_swap.c 
CHECKER_SRCS = src/get_next_line.c src/ch-instr_p.c src/ch-instr_r.c \
			src/ch-instr_rr.c src/ch-instr_s.c src/checker_main.c \
			src/checker.c src/ft_str_int_dup.c src/my_atoi.c src/my_freeall.c

PUSH_SWAP_OBJS = $(PUSH_SWAP_SRCS:.c=.o)
CHECKER_OBJS = $(CHECKER_SRCS:.c=.o)

HEAD = include/push_swap.h

CC		= gcc
C_FLAGS = -Wall -Wextra -Werror
# C_FLAGS = -Wall -Wextra -Werror  -fsanitize=address

.PHONY: all re clean fclean checker

all: "libft" push_swap
push_swap: "libft" ps
ps:	$(PUSH_SWAP_OBJS) libft/libft.a 
	$(CC) $(C_FLAGS) -o push_swap $(PUSH_SWAP_OBJS) libft/libft.a  

"libft":
	@make -C libft

checker: "libft" ch
ch: $(CHECKER_OBJS) libft/libft.a
	$(CC) $(C_FLAGS) -o checker $(CHECKER_OBJS) libft/libft.a 

%.o : %.c $(HEAD) Makefile
	$(CC) $(C_FLAGS) -c $< -o $@


clean:
	rm -f $(PUSH_SWAP_OBJS) $(CHECKER_OBJS)
	@make -C libft clean
	
fclean: clean
	rm -f push_swap checker libft/libft.a libft.a

re: fclean all
