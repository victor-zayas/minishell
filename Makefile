# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vzaya-s <vzaya-s@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/28 12:33:28 by vzaya-s           #+#    #+#              #
#    Updated: 2023/01/10 19:08:20 by vzaya-s          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# NAME #
NAME = minishell

# COMPILATION #
CC = gcc
CFLAGS = #-Wall -Wextra -Werror -g3 #$-fsanitize=address
RM = /bin/rm -rf
READLINE_PATH = ~/.brew/opt/readline
READLINE = -I$(READLINE_PATH)/include -lreadline -L $(READLINE_PATH)/lib 

# OBJS #
OBJS = $(SRCS:.c=.o)

# SRC #
SRCS = main.c

# RULES #
.SILENT:

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(READLINE)-o $(NAME)
	echo "$(BLUE)༺ library created༻$(END)"

clean: 
	$(RM) $(OBJS)
	echo "$(RED)༺ Objs deleted༻$(END)"

fclean: clean
	$(RM) $(NAME)
		echo "$(YELLOW)༺ Executable deleted༻$(END)"

re: fclean all

.PHONY: all clean fclean re