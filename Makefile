# Compiler
CC = cc

# Compiler flags
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g

# Directories
LIBFT_DIR = lib/libft
OBJ_DIR = obj

# Libraries
LIBFT = $(LIBFT_DIR)/libft.a

# Include paths
INCLUDES = -I$(LIBFT_DIR)

# Source files
SRCS = lib/stack/swap.c lib/stack/push.c lib/stack/reverse_rotate.c lib/stack/rotate.c lib/stack/stack.c lib/stack/utility.c \
		src/main/main.c src/main/push_swap.c \
		src/algorithm/brute_force_sort.c src/algorithm/radix_sort.c \
		src/utility/input_checker.c src/utility/utility.c

# Object files
OBJS = $(patsubst %.c, $(OBJ_DIR)/%.o, $(SRCS))

# Executable
TARGET = push_swap

# Colors for terminal output
GREEN = \033[0;32m
YELLOW = \033[0;33m
RESET = \033[0m

# Rule to build the executable
$(TARGET): $(OBJS) $(LIBFT)
	@echo "$(GREEN)Building $(TARGET)...$(RESET)"
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ $(OBJS) $(LIBFT)
	@echo "$(GREEN)$(TARGET) is ready!$(RESET)"

# Rule to compile source files
$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(@D)
	@echo "$(YELLOW)Compiling $<...$(RESET)"
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Rule to build libft
$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

.PHONY: clean fclean re

clean:
	@$(MAKE) -C $(LIBFT_DIR) clean
	@rm -rf $(OBJ_DIR)
	@echo "$(GREEN)Cleaned all object files!$(RESET)"

fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@rm -f $(TARGET)
	@echo "$(GREEN)Removed $(TARGET)!$(RESET)"

re: fclean $(TARGET)

.SUFFIXES: .c .o
