NAME = libftprintf.a

SRC = ft_printf.c \
      print_char.c \
      print_str.c \
      print_int.c \
      print_unsigned.c \
      print_hex.c \
      print_ptr.c 

OBJ = $(SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

RM = rm -f
AR = ar rcs

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
