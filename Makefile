NAME		:= miniRT
INC			:= -I ./includes -I ./mlx -I ./srcs/libft/includes
SRCS_DIR	:= ./srcs
SRCS		:= ./srcs/libft/ctype/ft_isalnum.c ./srcs/libft/ctype/ft_isalpha.c ./srcs/libft/ctype/ft_isascii.c ./srcs/libft/ctype/ft_isblank.c ./srcs/libft/ctype/ft_isdigit.c ./srcs/libft/ctype/ft_isdouble.c ./srcs/libft/ctype/ft_isint.c ./srcs/libft/ctype/ft_islower.c ./srcs/libft/ctype/ft_isnumber.c ./srcs/libft/ctype/ft_isprint.c ./srcs/libft/ctype/ft_isspace.c ./srcs/libft/ctype/ft_isstrspace.c ./srcs/libft/ctype/ft_isupper.c ./srcs/libft/ctype/ft_tolower.c ./srcs/libft/ctype/ft_toupper.c ./srcs/libft/list/ft_lstadd_back.c ./srcs/libft/list/ft_lstadd_front.c ./srcs/libft/list/ft_lstclear.c ./srcs/libft/list/ft_lstdelone.c ./srcs/libft/list/ft_lstiter.c ./srcs/libft/list/ft_lstlast.c ./srcs/libft/list/ft_lstmap.c ./srcs/libft/list/ft_lstnew.c ./srcs/libft/list/ft_lstsize.c ./srcs/libft/stdio/ft_printf.c ./srcs/libft/stdio/ft_putchar_fd.c ./srcs/libft/stdio/ft_putdbl_fd.c ./srcs/libft/stdio/ft_putendl_fd.c ./srcs/libft/stdio/ft_putnbr_fd.c ./srcs/libft/stdio/ft_putstr_fd.c ./srcs/libft/stdio/ft_vdprintf.c ./srcs/libft/stdio/get_next_line.c ./srcs/libft/stdlib/ft_abs.c ./srcs/libft/stdlib/ft_atof.c ./srcs/libft/stdlib/ft_atoi.c ./srcs/libft/stdlib/ft_atol.c ./srcs/libft/stdlib/ft_atoll.c ./srcs/libft/stdlib/ft_calloc.c ./srcs/libft/stdlib/ft_itoa.c ./srcs/libft/stdlib/ft_strtol.c ./srcs/libft/string/ft_bzero.c ./srcs/libft/string/ft_memchr.c ./srcs/libft/string/ft_memcmp.c ./srcs/libft/string/ft_memcpy.c ./srcs/libft/string/ft_memmove.c ./srcs/libft/string/ft_memset.c ./srcs/libft/string/ft_split.c ./srcs/libft/string/ft_strcat.c ./srcs/libft/string/ft_strchr.c ./srcs/libft/string/ft_strcmp.c ./srcs/libft/string/ft_strcpy.c ./srcs/libft/string/ft_strdup.c ./srcs/libft/string/ft_striteri.c ./srcs/libft/string/ft_strjoin.c ./srcs/libft/string/ft_strlcat.c ./srcs/libft/string/ft_strlcpy.c ./srcs/libft/string/ft_strlen.c ./srcs/libft/string/ft_strmapi.c ./srcs/libft/string/ft_strncat.c ./srcs/libft/string/ft_strncmp.c ./srcs/libft/string/ft_strncpy.c ./srcs/libft/string/ft_strndup.c ./srcs/libft/string/ft_strnstr.c ./srcs/libft/string/ft_strrchr.c ./srcs/libft/string/ft_strstr.c ./srcs/libft/string/ft_strtrim.c ./srcs/libft/string/ft_substr.c ./srcs/main.c ./srcs/parser/ambient_lightning.c ./srcs/parser/camera.c ./srcs/parser/check_argument.c ./srcs/parser/cylinder.c ./srcs/parser/double.c ./srcs/parser/input_file.c ./srcs/parser/is_in_range.c ./srcs/parser/is_split_count.c ./srcs/parser/light.c ./srcs/parser/list.c ./srcs/parser/parser.c ./srcs/parser/plane.c ./srcs/parser/rgb.c ./srcs/parser/sphere.c ./srcs/parser/vector.c ./srcs/print_object.c ./srcs/ray/cylinder.c ./srcs/ray/get_camera_ray.c ./srcs/ray/get_shine_rate.c ./srcs/ray/get_shine_rate2.c ./srcs/ray/get_shine_rate3.c ./srcs/ray/plane.c ./srcs/ray/put_pixel.c ./srcs/ray/sphere.c ./srcs/render/hook.c ./srcs/render/init.c ./srcs/render/pixel_put.c ./srcs/render/render.c ./srcs/utils/color.c ./srcs/utils/open.c ./srcs/utils/print_error.c ./srcs/utils/split_string_by.c ./srcs/utils/vector/addition.c ./srcs/utils/vector/cross_product.c ./srcs/utils/vector/distance.c ./srcs/utils/vector/division.c ./srcs/utils/vector/dot_product.c ./srcs/utils/vector/magnitude.c ./srcs/utils/vector/magnitude_squared.c ./srcs/utils/vector/multiplication.c ./srcs/utils/vector/normalize.c ./srcs/utils/vector/scale.c ./srcs/utils/vector/subtraction.c
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
	norminette srcs includes

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
