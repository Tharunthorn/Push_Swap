# Makefile

# Compiler
CC = cc

# Compiler flags
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g

# Directories
LIBFT_DIR = lib/libft

# Libraries
LIBFT = $(LIBFT_DIR)/libft.a

# Include paths
INCLUDES = -I$(LIBFT_DIR)

# Source files
SRCS = lib/stack/swap.c lib/stack/push.c lib/stack/reverse_rotate.c lib/stack/rotate.c lib/stack/stack.c \
		src/main/main.c src/main/push_swap.c \
		src/algorithm/insert_sort.c

# Bonus source files
SRCS_BONUS =

# Object files
OBJS = $(SRCS:.c=.o)

# Bonus object files
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

# Executable
TARGET = push_swap

# Rule to build the executable
$(TARGET): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ $(OBJS) $(LIBFT)

# Rule to compile source files
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Rule to build libft
$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

.PHONY: clean fclean re

	$(CC) $(CFLAGS) $(INCLUDES) -o $(TARGET) $(OBJS_BONUS) $(LIBFT)

clean:
	@$(MAKE) -C $(LIBFT_DIR) clean
	@rm -f $(OBJS)
	@rm -f $(OBJS_BONUS)

fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@rm -f $(TARGET)


re: fclean $(TARGET)

bonus_re: fclean bonus

.SUFFIXES: .c .o
