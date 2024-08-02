SRC = errors.c main.c push_swap_utils.c push_swap_utils_1.c sort.c \
	sort_plus5.c sort_utils.c moves.c
OBJS = $(SRC:.c=.o)
NAME = ../push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

%.o : %.c push_swap.h
	@$(CC) $(CFLAGS) -c $< -o $@

clean :
	@rm -rf $(OBJS)

fclean : clean
	@rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re
