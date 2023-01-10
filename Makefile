# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaizpuru <jaizpuru@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/28 12:33:28 by vzaya-s           #+#    #+#              #
#    Updated: 2023/01/10 20:19:43 by jaizpuru         ###   ########.fr        #
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
SRCS = main.c utils.c

# RULES #
.SILENT:

all: $(NAME)

$(NAME): $(OBJS)
	make -C libft all
	make -C libft/pipex all
	cp libft/libft.a .
	$(CC) $(CFLAGS) $(OBJS) libft.a $(READLINE)-o $(NAME)
	echo "$(BLUE)༺ library created༻$(END)"

clean:
	make -C libft clean
	make -C libft/pipex clean
	$(RM) $(OBJS)
	echo "$(RED)༺ Objs deleted༻$(END)"

fclean: clean
	make -C libft fclean
	make -C libft/pipex fclean
	rm -r libft.a
	$(RM) $(NAME)
		echo "$(YELLOW)༺ Executable deleted༻$(END)"

re: fclean all

.PHONY: all clean fclean re