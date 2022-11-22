SRCS = ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
	   ft_memcpy.c ft_memmove.c ft_memset.c ft_strlcat.c ft_strlcpy.c ft_strlen.c \
	   ft_toupper.c ft_tolower.c ft_memchr.c ft_memcmp.c ft_strchr.c ft_strncmp.c \
	   ft_strrchr.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_strjoin.c \
	   ft_substr.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_putchar_fd.c \
	   ft_striteri.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

OBJS = $(SRCS:.c=.o)

SRCS_B = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
		ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJS_B = $(SRCS_B:.c=.o)

NAME = libft.a

GCC = gcc -Wall -Werror -Wextra

${NAME} : $(OBJS)
	ar rcs libft.a $(OBJS)

bonus : $(OBJS) $(OBJS_B)
	ar rcs libft.a $(NAME) $(OBJS_B)

compilation :
	${GCC} -I libft.h -c $< -o ${<:.c=.o}

all : ${NAME}

clean :
	rm -f $(OBJS) $(OBJS_B)

fclean : clean
	rm -f libft.a

re : fclean all

.PHONY: all re clean fclean bonus compilation
