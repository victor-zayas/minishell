
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/28 12:33:28 by vzaya-s           #+#    #+#              #
#    Updated: 2023/02/23 16:44:38 by vzayas-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# NAME #
NAME = minishell

# COMPILATION #
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3 #-fsanitize=address
RM = /bin/rm -rf
LREADLINE_FLAGS = -lreadline -L/Users/$(USER)/.brew/opt/readline/lib/
READLINE = -I/Users/$(USER)/.brew/opt/readline/include/
LINUX_READLINE = -lreadline -L/usr/lib/x86_64-linux-gnu/

# OBJS #
OBJS = $(SRCS:.c=.o)

# SRC #
SRCS = main.c \
	get_data.c \
	utils_iterator.c \
	tokens.c \
	lexer.c \
	lexer2.c \
	builtings.c \
	pwd.c \
	env.c \
	echo.c \
	exit.c \
	cd.c \
	export_unset.c \
	inter.c \
	pipes.c \
	utils_pipes.c \
	cmd.c \
	redir.c \
	print.c \
	utils_cmd.c

# MAKEFILE ART #
# COLORS #
BLACK=\033[0;30m
RED=\033[0;31m
GREEN=\033[0;32m
YELLOW=\033[0;33m
BLUE=\033[0;34m
MAG=\033[0;35m
CYAN=\033[0;36m
WHITE=\033[0;37m
PAPYRUS=\033[38;5;223m
END=\033[0m

define MINISHELL
$(RED)

███╗   ███╗██╗███╗   ██╗██╗██╗  ██╗███████╗██╗     ██╗     
████╗ ████║██║████╗  ██║██║██║  ██║██╔════╝██║     ██║     
██╔████╔██║██║██╔██╗ ██║██║███████║█████╗  ██║     ██║     
██║╚██╔╝██║██║██║╚██╗██║██║██╔══██║██╔══╝  ██║     ██║     
██║ ╚═╝ ██║██║██║ ╚████║██║██║  ██║███████╗███████╗███████╗
╚═╝     ╚═╝╚═╝╚═╝  ╚═══╝╚═╝╚═╝  ╚═╝╚══════╝╚══════╝╚══════╝
                                                           
$(END)
endef
export MINISHELL

define JOKIN
	  ▄▌▐▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▌\n
   ▄▄██▌█ BEEP! BEEP!					   \n
▄▄▄▌▐██▌█ -3 Evaluations points DELIVERY   \n
███████▌█▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▌\n
▀(⊙)▀▀▀▀▀▀▀(⊙)(⊙)▀▀▀▀▀▀▀▀▀▀(⊙)(⊙)▀▀▀▀▀(⊙)▀ \n
endef
export JOKIN

# RULES #
.SILENT:

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(READLINE) -c $^ -o $@

$(NAME): $(OBJS)
	make -C libft all
#	$(CC) $(CFLAGS) $(LREADLINE_FLAGS) $(READLINE) libft/libft.a $^ -o $(NAME)
	$(CC) $(CFLAGS) $^ $(LREADLINE_FLAGS) $(LINUX_READLINE) libft/libft.a -o $(NAME)
	echo "$(BLUE)༺ library created༻$(END)"
	echo "$$MINISHELL"
	echo "Special thanks to $(GREEN)༺ HELECHO༻$(END)  & $(GREEN)༺ Arteria༻$(END)"
ifeq ($(USER), $(filter $(USER), jaizpuru))
		echo $$JOKIN
		osascript -e "set Volume 2"
		say --voice="Luciana" O líder do ginásio Jokin the calisthenics desafia você.
endif

clean:
	make -C libft clean
	$(RM) $(OBJS)
		echo "$(RED)༺ Objs deleted༻$(END)"

fclean: clean
	make -C libft fclean
	$(RM) $(NAME)
		echo "$(YELLOW)༺ Executable deleted༻$(END)"

re: fclean all

.PHONY: all clean fclean re
