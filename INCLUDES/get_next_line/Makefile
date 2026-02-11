NAME    = gnl.a
CC      = cc
CFLAGS  = -Wall -Werror -Wextra
AR      = ar
ARFLAGS = -rcs

SRCS	= get_next_line.c get_next_line_utils.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re all