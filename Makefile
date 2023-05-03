
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

# FLAGS #
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address
RM = /bin/rm -rf

# READLINE #
LREADLINE_FLAGS = -lreadline -L/Users/$(USER)/.brew/opt/readline/lib/
READLINE = -I/Users/$(USER)/.brew/opt/readline/include/
#LINUX_READLINE = -lreadline -L/usr/lib/x86_64-linux-gnu/

# INCLUDES #
INCDIR = includes/
INCLUDES = -I $(INCDIR)

# OBJS #

OBJ = $(addsuffix .o, $(BUILTINS)) \
	  $(addsuffix .o, $(MAIN)) \
	  $(addsuffix .o, $(MAS)) \
	  $(addsuffix .o, $(PIPES)) \
	  $(addsuffix .o, $(REDIR)) \
	  $(addsuffix .o, $(LEXER)) \
	  $(addsuffix .o, $(CMD))

SRCDIR := src/

# SRCS #

BUILTINS = builtings cd echo env exit export ft_env_strdup pwd unset

MAIN = ft_check_prompt init_struct main print rstio signal

MAS = get_data utils_iterator

PIPES = pipes utils_pipe_fd utils_pipes error

REDIR = input output redir

CMD = cmd exec init_cmd utils_cmd

LEXER = inter lexer lexer2 token_append tokens

# SRCS #

BUILTINS = builtings cd echo env exit export ft_env_strdup pwd unset

MAIN = ft_check_prompt init_struct main print rstio signal

MAS = get_data utils_iterator

PIPES = pipes utils_pipe_fd utils_pipes error

REDIR = input output redir

CMD = cmd exec init_cmd utils_cmd

LEXER = inter lexer lexer2 token_append tokens

SRCS := $(addsuffix .c, $(addprefix src/builtings/, $(BUILTINS))) \
	  $(addsuffix .c, $(addprefix src/main/, $(MAIN))) \
	  $(addsuffix .c, $(addprefix src/mas/, $(MAS))) \
	  $(addsuffix .c, $(addprefix src/pipes/, $(PIPES))) \
	  $(addsuffix .c, $(addprefix src/redir/, $(REDIR))) \
	  $(addsuffix .c, $(addprefix src/lexer/, $(LEXER))) \
	  $(addsuffix .c, $(addprefix src/cmd/, $(CMD)))

SRC := $(addprefix $(SRCDIR), $(SRCS))

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

# MAKEFILE ART #
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

# COMPILATION #
#.SILENT:

all: $(NAME)

$(OBJ) : $(SRCS)
	$(CC) $(CFLAGS) $(READLINE) $(INCLUDES) -c $^

objs/ :
	mkdir objs/

$(NAME): $(OBJ) objs/
	make -C libft all
	mv $(OBJ) objs/
#	$(CC) $(CFLAGS) $(LREADLINE_FLAGS) $(READLINE) libft/libft.a $^ -o $(NAME)
	$(CC) $(CFLAGS) $(addprefix objs/, $(OBJ)) $(LREADLINE_FLAGS) $(LINUX_READLINE) libft/libft.a -o $(NAME)
	echo "$(BLUE)༺ library created༻$(END)"
	echo "$$MINISHELL"
	echo "Special thanks to $(GREEN)༺ HELECHO༻$(END)  & $(GREEN)༺ Arteria༻$(END)"

clean:
	make -C libft clean
	$(RM) $(addprefix objs/, $(OBJ))
		echo "$(RED)༺ Objs deleted༻$(END)"

fclean: clean
	make -C libft fclean
	$(RM) $(NAME)
		echo "$(YELLOW)༺ Executable deleted༻$(END)"

re: fclean all

.PHONY: all clean fclean re
