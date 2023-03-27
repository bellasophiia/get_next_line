CC=cc 
CFLAGS=-Wall -Wextra -Werror
NAME=libget_next_line.a
DEPS=get_next_line.h
MANDATORY= get_next_line_utils.c get_next_line.c 
OBJS=$(MANDATORY:.c=.o)

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJS)
	ar -crs $@ $^ 

all: $(NAME)

test: $(OBJS) main.o
	$(CC) $(CFLAGS) $^ && ./a.out

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY:
	all clean fclean re
 