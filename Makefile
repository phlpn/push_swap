# Final executable name
NAME = push_swap
BNS_NAME = checker

# Compiler and compiler flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -Iinclude

# Directories
INCLUDE_DIR = include
SRC_DIR = src
BNS_DIR = $(SRC_DIR)/bonus
BUILD_DIR = build

# Define the source files

CMN_FILES = ops_push.c \
			ops_rotate.c \
			ops_rrotate.c \
			ops_swap.c \
			utils_checksort.c \
			utils_input.c \
			utils_misc.c \
			utils_list.c \
			utils_split.c \
			printing.c \
			utils_debug.c 

SRC_FILES =	push_swap.c \
			ranking.c \
			sorting_a.c \
			sorting_b.c \
			utils_minmax.c \
			exits_mgmt.c \
			utils_sort.c

BNS_FILES = checker_bonus.c \
			exits_mgmt.c


# Define the path of the SRC_FILES
SRCS = $(addprefix $(SRC_DIR)/,$(SRC_FILES)) 
CMN_SRCS = $(addprefix $(SRC_DIR)/,$(CMN_FILES)) 
BNS_SRCS = $(addprefix $(BNS_DIR)/,$(BNS_FILES))

# Derive object file names from .c files in the build directory
OBJS = $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SRCS))
CMN_OBJS = $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(CMN_SRCS))
BNS_OBJS = $(patsubst $(BNS_DIR)/%.c,$(BUILD_DIR)/%.o,$(BNS_SRCS))

# Rule to build the executables
$(NAME): $(OBJS) $(CMN_SRCS)
	$(CC) $(CFLAGS) -o $@ $^

$(BNS_NAME): $(BNS_OBJS) $(CMN_OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Rule to build object files from .c files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/%.o: $(BNS_DIR)/%.c
	mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Phony target to build the main executable
all: $(NAME)

# Phony target to build the bonus executable
bonus: $(BNS_NAME) 

# Phony target to clean generated files
clean:
	rm -rf $(BUILD_DIR)

# Phony target to remove the executables and object files
fclean: clean
	rm -f $(NAME) $(BNS_NAME)

# Phony target to perform a full re-build
re: fclean all

.SILENT:
.PHONY: all bonus clean fclean re
