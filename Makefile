# Final executable name
NAME = push_swap

# Compiler and compiler flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -Iinclude

# Directories
SRC_DIR = src
INCLUDE_DIR = include
BUILD_DIR = build

# Get all .c files in the src directory
SRCS = 	$(SRC_DIR)/ops_push.c \
		$(SRC_DIR)/ops_rotate.c \
		$(SRC_DIR)/ops_rrotate.c \
		$(SRC_DIR)/ops_swap.c \
		$(SRC_DIR)/printing.c \
		$(SRC_DIR)/push_swap.c \
		$(SRC_DIR)/ranking.c \
		$(SRC_DIR)/sorting_a.c \
		$(SRC_DIR)/sorting_b.c \
		$(SRC_DIR)/utils_checksort.c \
		$(SRC_DIR)/utils_debug.c \
		$(SRC_DIR)/utils_input.c \
		$(SRC_DIR)/utils_list.c \
		$(SRC_DIR)/utils_minmax.c \
		$(SRC_DIR)/utils_misc.c \
		$(SRC_DIR)/utils_sort.c \
		$(SRC_DIR)/utils_split.c

# Derive object file names from .c files in the build directory
OBJS = $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SRCS))

# Rule to build the executable
$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -o $@ $^

# Rule to build object files from .c files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(BUILD_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

# Phony target to build the executable
all: $(NAME)

# Phony target to clean generated files
clean:
	@rm -rf $(BUILD_DIR)

# Phony target to remove the executable and object files
fclean: clean
	@rm -f $(NAME)

# Phony target to perform a full re-build
re: fclean all

.PHONY: all clean fclean re
