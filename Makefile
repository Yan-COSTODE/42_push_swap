CC=cc
NAME = push_swap
INCPATH = includes/
SRCPATH = srcs/
SRCS = push_swap.c stack.c parse.c sort.c utils.c brut.c find.c first_sort.c extreme.c leaks.c
HEADER = libft.h push_swap.h
OBJS = $(SRCS:.c=.o)
SRCSINC = $(addprefix $(SRCPATH), $(SRCS))
HEADINC = $(addprefix $(INCPATH), $(HEADER))
OBJS = $(SRCSINC:.c=.o)
CFLAGS = -Wall -Wextra -Werror -g
LDFLAGS = -L./$(INCPATH) -lft

all:$(NAME)

$(NAME): $(OBJS)
	@make bonus -j 40 --no-print-directory -C libft
	@cp libft/libft.a ./$(INCPATH)
	@$(CC) $(OBJS) $(LDFLAGS) -o $(NAME)
	@printf "\033[1;32mCompilation Finished !\n\033[0m"

%.o : %.c $(HEADINC)
	@$(CC) $(CFLAGS) -I./$(INCPATH) $< -c -o $@

fclean: clean
	@rm -f $(NAME)
	@make fclean --no-print-directory -C libft
	@printf "\033[1;31mProgram Deleted !\n\033[0m"

clean:
	@rm -f $(OBJS)
	@make clean --no-print-directory -C libft
	@printf "\033[1;31mObjects Deleted !\n\033[0m"

re: fclean all

.PHONY: all fclean clean re
