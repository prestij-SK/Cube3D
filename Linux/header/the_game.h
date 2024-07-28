#ifndef THE_GAME_H
# define THE_GAME_H

# include "../mlx_linux/mlx.h"

# include "utils.h"
# include "image.h"
# include "minimap.h"
# include "player.h"
# include "draw_shape.h"

#include <stdlib.h>

# define WINDOW_WIDTH 1600
# define WINDOW_HEIGHT 900
# define GAME_NAME "THE GAME"

typedef struct MainGameData
{
	void		*mlx;
	void		*mlx_window;
	t_Minimap	minimap;
	t_Player	player;
	int			key_pressed;
}	t_GameData;

t_StatusCode	game_data_init(t_GameData *data, char **map, t_Point2D block_count);
void			game_data_delete(t_GameData *data);

void	input_update_render(t_GameData *data);

/*
	input.c functions
*/
int		input_key_press(int key, t_GameData *data);
int		input_close_window(t_GameData *data);

/*
	update.c functions
*/
void	update_A_key(t_Player *player);
void	update_D_key(t_Player *player);
void	update_W_key(t_Player *player);
void	update_S_key(t_Player *player);
void	update_Right_key(t_Player *player);
void	update_Left_key(t_Player *player);

/*
	render.c functions
*/
void	render_image(t_GameData *data, t_Image *image);
void	render_all(t_GameData *data);

#endif