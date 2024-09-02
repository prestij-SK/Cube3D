NAME = the_game
UNAME = $(shell uname -s)

ifeq ($(UNAME),Darwin)
	MLX_DIR = mlx_mac
	LDFLAGS = -Lminilibx_macos -lmlx -framework OpenGL -framework AppKit
else
	MLX_DIR = mlx_mac
	LDFLAGS = -L./${MLX_DIR} -lmlx -lXext -lX11 -lm -lbsd
endif

CC = cc
CFLAGS = -I ${MLX_DIR} #-fsanitize=address #-Wall -Wextra -Werror

SRCS_DIR = src/
OBJS_DIR = obj/
HEADERS_DIR = header/

HEADERS = color.h \
		  door.h \
		  draw_shape.h \
		  first_person_view.h \
		  for_math.h \
		  image.h \
		  input.h \
		  minimap.h \
		  player.h \
		  the_game.h \
		  utils.h \
		  parsing.h

SRCS_NAME = door.c \
			draw_shape.c \
			first_person_view.c \
			for_math.c \
			game_init.c \
			horizontal_ray.c \
			image.c \
			input_update_render.c \
			input.c \
			main.c \
			minimap.c \
			player.c \
			ray_cast_utils.c \
			ray_cast.c \
			render.c \
			the_game.c \
			update.c \
			utils.c \
			vertical_ray.c \
			parsing_utils.c \
			parsing.c \
			ft_split.c \
			get_next_line.c \
			parsing_basic_utils.c \
			read_file.c \
			get_textures_and_colors.c \
			save_textures.c \
			parsing_memory_management.c \
			validation.c \
			resolve_error.c \
			save_colors.c \
			debug.c \
			libft.c \
			validate_map_chars.c \
			map_parsing_utils.c \
			validate_map_scheme.c

OBJS = $(addprefix $(OBJS_DIR), $(OBJS_NAME))
OBJS_NAME = $(SRCS_NAME:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c $(addprefix $(HEADERS_DIR), $(HEADERS)) Makefile
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: clean all

.PHONY: all clean fclean re
