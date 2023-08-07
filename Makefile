# Final executable name
NAME = push_swap

# Compiler and compiler flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -Iinclude
DFLAGS = -g -DDEBUG

# Directories
SRC_DIR = src
BUILD_DIR = build

# Define the source files
SRC_FILES =	ops_push.c \
			ops_rotate.c \
			ops_rrotate.c \
			ops_swap.c \
			utils_checksort.c \
			utils_input.c \
			utils_misc.c \
			utils_list.c \
			utils_split.c \
			printing.c \
			exits_mgmt.c \
			utils_debug.c \
			push_swap.c \
			ranking.c \
			sorting_a.c \
			sorting_b.c \
			utils_minmax.c \
			utils_sort.c

# Define the path of the sources files
SRCS = $(addprefix $(SRC_DIR)/,$(SRC_FILES)) 

# Derive object file names from .c files in the build directory
OBJS = $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SRCS))

# Rule to build the executables
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Rule to build object files from .c files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Phony target to build the main executable
all: $(NAME)

# Phony target to clean generated files
clean:
	rm -rf $(BUILD_DIR)

# Phony target to remove the executables and object files
fclean: clean
	rm -f $(NAME)

# Phony target to perform a full re-build
re: fclean all

# Rule to build with debug flags
debug: CFLAGS += $(DEBUG_CFLAGS)
debug: all

.SILENT:
.PHONY: all bonus clean fclean re
