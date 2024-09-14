NAME = the_game
UNAME = $(shell uname -s)

ifeq ($(UNAME),Darwin)
	MLX_DIR = mlx_mac
	LDFLAGS = -Lminilibx_macos -lmlx -framework OpenGL -framework AppKit
else
	MLX_DIR = mlx_linux
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

SRCS_NAME = data_from_parsed.c \
			door.c \
			draw_shape_norm_1.c \
			draw_shape.c \
			first_person_view.c \
			for_math.c \
			game_init_norm.c \
			game_init.c \
			horizontal_ray.c \
			image.c \
			input_update_render.c \
			input.c \
			main.c \
			minimap_norm_1.c \
			minimap.c \
			player.c \
			ray_cast_utils.c \
			ray_cast.c \
			render.c \
			the_game.c \
			update_norm_1_norm.c \
			update_norm_1.c \
			update_norm_2.c \
			update.c \
			utils.c \
			vertical_ray.c \
			Y_parsing.c \
			Y_ft_split.c \
			Y_get_next_line.c \
			Y_parsing_utils.c \
			Y_read_file.c \
			Y_get_textures_and_colors.c \
			Y_save_textures.c \
			Y_parsing_memory_management.c \
			Y_validation.c \
			Y_resolve_error.c \
			Y_save_colors.c \
			Y_debug.c \
			Y_libft.c \
			Y_libft2.c \
			Y_libft3.c \
			Y_validate_map_chars.c \
			Y_map_parsing_utils.c \
			Y_map_parsing.c \
			Y_validate_map_scheme.c \
			Y_free_utils.c

OBJS = $(addprefix $(OBJS_DIR), $(OBJS_NAME))
OBJS_NAME = $(SRCS_NAME:.c=.o)

all: create_obj_folder $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c $(addprefix $(HEADERS_DIR), $(HEADERS)) Makefile
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	rm -rf $(OBJS_DIR)

fclean: clean
	$(RM) $(NAME)

re: clean all

create_obj_folder:
	@mkdir -p $(OBJS_DIR)

.PHONY: all clean fclean re create_obj_folder
