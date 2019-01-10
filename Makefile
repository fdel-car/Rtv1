TARGET := rtv1
SRCS_DIR := ./srcs
OBJS_DIR := ./objs
CC := clang
CFLAGS := -Wall -Wextra -Werror
MLXFLAGS = -lmlx -framework OpenGL -framework AppKit -lpthread
ignore-warnings : CFLAGS := -w

# Colors
RESET := \033[0m
GREEN := \033[32;01m
ERROR := \033[31;01m
WARN := \033[33;01m
# Formatting
CLEAR_LINE := \033[2K
MOVE_CURSOR_UP := \033[1A

SRCS := $(shell find $(SRCS_DIR) -name *.c)
OBJS := $(patsubst $(SRCS_DIR)%.c,$(OBJS_DIR)%.o,$(SRCS))

all: lib $(OBJS_DIR) $(TARGET)

ignore-warnings: all

$(OBJS_DIR):
	@mkdir -p ./objs

$(TARGET): $(OBJS)
	@$(CC) -I./includes $(MLXFLAGS) -o $@ $^ ./libft/libft.a
	@echo "\n$(GREEN)The target $(TARGET) was compiled successfully!$(RESET)"

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@echo "$(CLEAR_LINE)Creating object of the $(TARGET) with $^...$(MOVE_CURSOR_UP)"
	@$(CC) $(CFLAGS) -c $^ -o $@ -I./libft/includes -I./includes

lib:
	@make -C libft

clean:
	@rm -rf objs/

fclean: clean
	@rm -f $(TARGET)

re: fclean
	@make all

.PHONY: all lib clean fclean re ignore-warnings
