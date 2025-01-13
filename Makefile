NAME=libftprintf.a
FLAGS=-Wall -Wextra -Werror
CC=cc
HDRS=ft_printf.h
SRCS=ft_printf.c libft_tools.c print_functions.c print_functions2.c
OBJS=$(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

%.o: %.c $(HDRS)
	$(CC) $(FLAGS) -I $(HDRS) -c $<

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
