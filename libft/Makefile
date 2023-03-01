NAME = libft.a

SRCS = ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_strlen.c \
		ft_bzero.c \
		ft_memcpy.c \
		ft_memset.c \
		ft_memmove.c \
		ft_strlcpy.c \
		ft_strlcat.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strncmp.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_strnstr.c \
		ft_atoi.c \
		ft_calloc.c \
		ft_strdup.c \
		ft_substr.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_split.c \
		ft_itoa.c \
		ft_strmapi.c \
		ft_striteri.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_doublestrlen.c \
		ft_doublestrdup.c \
		ft_env_strdup.c \
		ft_doublefree.c \
		ft_isspace.c \
		ft_isnot_empty_str.c \
		ft_chr_in_set.c 

SRC_BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJECTS = $(SRCS:.c=.o)

OBJ_BONUS = $(SRC_BONUS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJECTS)
	ar rc $(NAME) $(OBJECTS)

$(OBJECTS): $(SRCS)
	gcc $(CFLAGS) -c $(SRCS)

$(OBJ_BONUS): $(SRCS) $(SRC_BONUS)
	gcc $(CFLAGS) -c $(SRCS) $(SRC_BONUS)

bonus: $(OBJECTS) $(OBJ_BONUS)
	ar rc $(NAME) $(OBJECTS) $(OBJ_BONUS)

clean:
	@rm -f $(OBJECTS) $(OBJ_BONUS)

fclean: clean
	@rm -f $(OBJECTS) $(OBJ_BONUS) $(NAME)

re: fclean all

.PHONY: all clean fclean re

