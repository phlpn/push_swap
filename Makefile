# Final executable name
NAME = push_swap

# Compiler and compiler flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -Iinclude

# Directories
INCLUDE_DIR = include
SRC_DIR = src
BUILD_DIR = build

# Define the source files
SRC_FILES = ops_push.c \
			ops_rotate.c \
			ops_rrotate.c \
			ops_swap.c \
			printing.c \
			push_swap.c \
			ranking.c \
			sorting_a.c \
			sorting_b.c \
			utils_checksort.c \
			utils_debug.c \
			utils_input.c \
			utils_list.c \
			utils_minmax.c \
			utils_misc.c \
			utils_sort.c \
			utils_split.c

# Define the path of the SRC_FILES
SRCS = $(addprefix $(SRC_DIR)/,$(SRC_FILES))

# Derive object file names from .c files in the build directory
OBJS = $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SRCS))

# Rule to build the executable
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Rule to build object files from .c files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Phony target to build the executable
all: $(NAME)

# Phony target to clean generated files
clean:
	rm -rf $(BUILD_DIR)

# Phony target to remove the executable and object files
fclean: clean
	rm -f $(NAME)

# Phony target to perform a full re-build
re: fclean all

.SILENT:
.PHONY: all clean fclean re
