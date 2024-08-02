SRCS = errors.c get_next_line_utils.c get_next_line.c main.c \
	moves.c moves1.c utils.c utils1.c utils2.c
OBJS = errors.o get_next_line_utils.o get_next_line.o \
	main.o moves.o moves1.o utils.o utils1.o utils2.o
CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = ../checker

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS)  -o $@ $(OBJS)

%.o : %.c checker.h
	@$(CC) $(CFLAGS) -c $< -o $@

clean: 
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re
