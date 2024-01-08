NAME = miniRT

SRC = main.c \

PARSER_SRC = parser.c

SRCDIR = srcs
SRCS = $(addprefix $(SRCDIR)/, $(SRC))
SRCS += $(addprefix $(SRCDIR)/parser/, $(PARSER_SRC))
MAKE_DIR = parser

OBJDIR = objs
OBJS = $(subst $(SRCDIR), $(OBJDIR), $(SRCS:.c=.o))
DEPS = $(OBJS:.o=.d)
MAKE_DIRS = $(addprefix $(OBJDIR)/, $(MAKE_DIR))

CFLAGS = -Wall -Wextra -Werror -MP -MMD -O3
RM = rm -rf
INC = -I./includes/ -I./libft/includes -I./mlx

LIBFT = libft/libft.a

ifeq ($(MAKECMDGOALS), debug)
	CFLAGS += -DDEBUG
endif

ifeq ($(MAKECMDGOALS), address)
	CFLAGS += -g3 -fsanitize=address
endif

CHECK		= \033[32m[✔]\033[0m
REMOVE		= \033[31m[✘]\033[0m
GENERATE	= \033[33m[➤]\033[0m
BLUE		= \033[1;34m
YELLOW		= \033[1;33m
RESET		= \033[0m

TOTAL_FILES := $(shell echo $(words $(SRCS)))
CURRENT_FILE = 1

define progress
    @printf "$(GENERATE) $(YELLOW)MiniRT obj file gen Progress: %3d%% (%d/%d)$(RESET)\r" $$(($(CURRENT_FILE)*100/$(TOTAL_FILES))) $(CURRENT_FILE) $(TOTAL_FILES)
    @$(eval CURRENT_FILE=$(shell echo $$(($(CURRENT_FILE)+1))))
    @if [ $(CURRENT_FILE) -gt $(TOTAL_FILES) ]; then \
        printf "$(GENERATE) $(YELLOW)Finish Generating MINIRT Object files !%-50.50s\n$(RESET)"; \
    fi
endef

all : $(NAME)

$(NAME): $(OBJS)
	@ $(MAKE) -C ./libft
	@ $(MAKE) -C ./mlx
	@ $(CC) $(CFLAGS) -o $@ $^ $(LIBFT) -Lmlx -lmlx -framework OpenGL -framework AppKit
	@ printf "$(CHECK) $(BLUE)Compiling miniRT ...%-50.50s\n$(RESET)"

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@ mkdir -p $(MAKE_DIRS)
	@ $(CC) $(CFLAGS) $(INC) -o $@ -c $<
	$(call progress)

clean :
	@ $(MAKE) -C ./libft clean
	@ $(MAKE) -C ./mlx clean
	@ $(RM) $(OBJDIR)
	@ echo "$(REMOVE) $(BLUE)Remove miniRT object files. $(RESET)"

fclean :
	@ $(MAKE) -C ./libft fclean
	@ $(MAKE) -C ./mlx fclean
	@ $(RM) $(OBJDIR) $(NAME)
	@ echo "$(REMOVE) $(BLUE)Remove miniRT object files and $(NAME). $(RESET)"

re : fclean all

debug : re

address : re

norm :
	norminette srcs includes libft

.PHONY : all clean fclean re debug norm address

-include $(DEPS)
