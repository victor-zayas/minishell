# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaizpuru <jaizpuru@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/21 15:33:18 by jaizpuru          #+#    #+#              #
#    Updated: 2023/01/10 20:19:13 by jaizpuru         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

#Variables to hold paths of files or single files

LIBFT = libft.a

D_LIBFT = ../

D_R_LIBFT= ../libft.a

# Variables used to hold names of source code and object files

UTILS = pipex.c \
		utils.c \

OBJS = $(UTILS:.c=.o)

#Variables used for compiling & flags

CC = gcc

CFLAGS = -Wall -Wextra -Werror

#Variables used for executing different commands along with flags

MV = mv

RM = rm

RM_FLAGS = -rf

all: $(NAME)

$(NAME) : $(LIBFT) $(UTILS)
	@$(CC) $(CFLAGS) -c $(UTILS)
	@$(CC) $(CFLAGS) $(LIBFT) $(OBJS) -o $(NAME)
	@echo "PIPEX has succesfully been created"

$(LIBFT): $(D_LIBFT)
	@make -C $(D_LIBFT) $(LIBFT)
	@cp $(D_R_LIBFT) .

clean:
	@make -C $(D_LIBFT) clean
	@$(RM) $(RM_FLAGS) $(OBJS)
	@$(RM) $(RM_FLAGS) $(LIBFT)

fclean: clean
	@make -C $(D_LIBFT) fclean
	@$(RM) $(RM_FLAGS) $(NAME)

re : fclean all

.PHONY: all clean fclean re
