# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: trurgot <trurgot@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/06 07:03:56 by trurgot           #+#    #+#              #
#    Updated: 2022/01/10 13:47:23 by trurgot          ###   ########.fr        #
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

SERVER_SRCS = server.c server2.c
CLIENT_SRCS = client.c
SERVER_BONUS_SRCS = server_bonus.c server2_bonus.c
CLIENT_BONUS_SRCS = client_bonus.c

SERVER_OBJS = $(SERVER_SRCS:.c=.o)
CLIENT_OBJS = $(CLIENT_SRCS:.c=.o)
SERVER_BONUS_OBJS = $(SERVER_BONUS_SRCS:.c=.o)
CLIENT_BONUS_OBJS = $(CLIENT_BONUS_SRCS:.c=.o)

HEAD = include/minitalk.h include/minitalk_bonus.h

CC		= gcc
C_FLAGS = -Wall -Wextra -Werror
# C_FLAGS = -Wall -Wextra -Werror  -fsanitize=address

.PHONY: all bonus libft clean fclean re

all: libft server client
server: $(SERVER_OBJS) libft/libft.a
	$(CC) $(C_FLAGS) -o $@ $(SERVER_OBJS) libft/libft.a  
client: $(CLIENT_OBJS) libft/libft.a
	$(CC) $(C_FLAGS) -o $@ $(CLIENT_OBJS) libft/libft.a 

bonus:
	@make SERVER_OBJS="$(SERVER_BONUS_OBJS)" CLIENT_OBJS="$(CLIENT_BONUS_OBJS)"

%.o : %.c $(HEAD) Makefile
	$(CC) $(C_FLAGS) -c $< -o $@

libft:
	@make -C libft

clean:
	rm -f $(SERVER_OBJS) $(CLIENT_OBJS) $(SERVER_BONUS_OBJS) $(CLIENT_BONUS_OBJS)
	@make -C libft clean
	
fclean: clean
	rm -f server client libft/libft.a

re: fclean all
