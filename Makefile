NAME = push_swap

SRC = 	errors.c \
		push_swap.c \
		rotate.c \
		split.c \
		swap.c \
		init_a_to_b.c \
		init_b_to_a.c \
		sort_stacks.c \
		stack_init.c \
		push.c  \
		rev_rotate.c \
		sort_three.c \
		stack_utils.c \

OBJS = $(SRC:.c=.o)

HDRS = /push_swap.h

RM = rm -f

CC = gcc -Wall -Wextra -Werror -fPIE

LIBFT = libft/libft.a

.c.o:
	${CC} -I ${HDRS} -c $< -o ${<:.c=.o}

$(NAME): $(OBJS)
	$(MAKE) -C libft
	${CC} -o $(NAME) $(OBJS) $(LIBFT)
all: $(NAME)

clean:
	${RM} $(OBJS)
	$(MAKE) -C libft clean

fclean: clean
	${RM} $(NAME)
	$(MAKE) -C libft fclean

re: fclean all

.PHONY: all clean fclean re
