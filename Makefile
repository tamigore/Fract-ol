NAME = fractol

LIB = lib/

LIBFT = $(LIB)libft

LIBMATH = $(LIB)libmath

DIR_S = srcs/

HEADER = includes/

SOURCES =	main.c 			\
			mlx_img.c		\
			init.c			\
			graphic_loop.c	\
			fractol.c		\
			mouse.c			\
			render.c

SRCS = $(addprefix $(DIR_S),$(SOURCES))

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Werror -Wextra -I $(HEADER) -D NUM_THREADS=$(NUM_THREADS)

FLAGS = -L $(LIBFT) -lft -L $(LIBMATH) -lmath

MACOS_MACRO = -D MACOS

LINUX_MACRO = -D LINUX

MACOS_FLAGS = -L $(LIB)minilibx_opengl_20191021 -lmlx -framework Appkit -framework OpenGL

LINUX_FLAGS = -L $(LIB)minilibx-linux -lmlx -lm -lX11 -lXext -lpthread

UNAME := $(shell uname)

ifeq ($(UNAME),Darwin)
	NUM_THREADS = $(shell sysctl -n hw.ncpu)
	CFLAGS += $(MACOS_MACRO)
	FLAGS += $(MACOS_FLAGS)
endif
ifeq ($(UNAME),Linux)
	NUM_THREADS = $(shell nproc --all)
	CFLAGS += $(LINUX_MACRO)
	FLAGS += $(LINUX_FLAGS)
endif

all: $(NAME)

$(NAME): $(OBJS) $(HEADER) $(LIBFT)
	make -C $(LIBFT)
	gcc -g $(CFLAGS) $(OBJS) $(FLAGS) -o $(NAME)

norme:
	norminette ./$(LIB)
	@echo
	norminette ./$(HEADER)
	@echo
	norminette ./$(DIR_S)

bonus: all

clean:
	@rm -f $(OBJS)
	@make clean -C $(LIBFT)
	@make clean -C $(LIBMATH)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT)
	@make clean -C $(LIBMATH)

re: fclean all