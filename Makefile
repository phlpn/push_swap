NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -I.
SRCS = debug.c \
		ops_push.c \
		ops_rotate.c \
		ops_rrotate.c \
		ops_swap.c \
		push_swap.c \
		ranking.c \
		sorting_a.c \
		sorting_b.c \
		utils_checksort.c \
		utils_input.c \
		utils_list.c \
		utils_minmax.c \
		utils_print.c \
		utils_sort.c \
		utils_split.c \
		utils.c

OBJ_DIR = Objs
OBJS = $(addprefix $(OBJ_DIR)/,$(SRCS:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
