
# LIB #
NAME = libft.a

# SRCS #
SRC = ft_isalnum.c \
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
		ft_doublefree.c \
		ft_isspace.c \
		ft_isnot_empty_str.c \
		ft_chr_in_set.c \
		ft_lstnew.c \
		ft_lstadd_front.c \
		ft_lstsize.c \
		ft_lstlast.c \
		ft_lstadd_back.c \
		ft_lstdelone.c \
		ft_lstclear.c \
		ft_lstiter.c \
		ft_lstmap.c

# RULES #
OBJDIR = libft_objs/
OBJS := $(addprefix $(OBJDIR), $(SRC:.c=.o))
SRCDIR = ./

# FLAGS #
CFLAGS = -Wall -Wextra -Werror

# INCLUDES #
INCLUDES = -I ../includes/

# COMPILATION #
all: $(NAME)

$(OBJDIR)%.o: $(SRCDIR)%.c
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $^ -o $@

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

clean:
	@rm -rf $(OBJDIR) $(OBJ_BONUS)

fclean: clean
	@rm -f $(OBJS) $(OBJ_BONUS) $(NAME)

re: fclean all

.PHONY: all clean fclean re

