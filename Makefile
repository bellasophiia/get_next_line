CC=cc 
CFLAGS=-Wall -Wextra -Werror -D -g BUFFER_SIZE=n -fsanitize=address <files>.c
NAME=get_next_line
DEPS=get_next_line.h
MANDATORY= get_next_line_utils.c get_next_line.c main.c

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c $<  -o $@ 

$(NAME): $(OBJ)
	cc $(MANDATORY)

all: $(NAME)

test: $(OBJ)
	$(CC) -o $@ $^ && ./test

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY:
	all clean fclean re
 