NAME = the_game

CC = cc #-Wall -Wextra -Werror
CFLAGS = -I minilibx_macos
LDFLAGS = -Lminilibx_macos -lmlx -framework OpenGL -framework AppKit

SRCS_DIR = src/
OBJS_DIR = obj/
HEADERS_DIR = header/

HEADERS = color.h \
		  draw_shape.h \
		  image.h \
		  minimap.h \
		  player.h \
		  the_game.h \
		  utils.h \

SRCS_NAME = draw_shape.c \
			image.c \
			main.c \
			minimap.c \
			player.c \
			the_game.c \

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