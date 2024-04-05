NAME		:= miniRT
INC			:= $(shell find . -name "*.h" -exec dirname {} \; | sort -u | sed 's/^/-I /') -I ./mlx
SRCS_DIR	:= ./srcs
SRCS		:= $(shell find . -name "*.c" | grep -v mlx)
OBJS_DIR	:= ./objs
OBJS		:= $(subst $(SRCS_DIR), $(OBJS_DIR), $(SRCS:.c=.o))
DEPS		:= $(subst $(SRCS_DIR), $(OBJS_DIR), $(SRCS:.c=.d))

CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror $(INC) -MMD -MP

# Debug
ifeq ($(MAKECMDGOALS), debug)
	CFLAGS += -DDEBUG
endif

ifeq ($(MAKECMDGOALS), address)
	CFLAGS += -g3 -fsanitize=address
endif

all			: $(NAME)

$(NAME)	: $(OBJS)
	$(MAKE) -C ./mlx
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L./mlx -lmlx -framework OpenGL -framework AppKit

$(OBJS_DIR)/%.o: srcs/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -o $@ -c $<

clean		:
	make -C ./mlx fclean
	rm -rf $(OBJS_DIR)

fclean		: clean
	make -C ./mlx fclean
	$(RM) $(NAME)

re			: fclean all

debug		: re

address		: re

norm		:
	norminette srcs includes libft

help		: Makefile
	@echo "Usage: make [target]"
	@echo ""
	@echo "Targets:"
	@echo "  all		- build $(NAME)"
	@echo "  clean		- remove object files"
	@echo "  fclean	- remove object files and $(NAME)"
	@echo "  re		- remove object files and $(NAME) then build"
	@echo "  debug		- build $(NAME) with debug flag"
	@echo "  help		- show this help"

.PHONY		: all clean fclean re debug address help

-include $(DEPS)
