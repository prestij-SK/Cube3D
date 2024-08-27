NAME = the_game

CC = cc #-Wall -Wextra -Werror
CFLAGS = -I minilibx_macos
LDFLAGS = -Lminilibx_macos -lmlx -framework OpenGL -framework AppKit

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

OBJS = $(addprefix $(OBJS_DIR), $(OBJS_NAME))
OBJS_NAME = $(SRCS_NAME:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c $(addprefix $(HEADERS_DIR), $(HEADERS)) Makefile
	$(CC) $(CFLAGS) -c $< -o $@

%.o: %.c
	$(CC) -I/usr/include -Imlx_linux -O3 -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: clean all

.PHONY: all clean fclean re