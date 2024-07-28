#ifndef THE_GAME_H
# define THE_GAME_H

# include "../mlx_linux/mlx.h"

# include "utils.h"
# include "image.h"
# include "minimap.h"
# include "player.h"
# include "draw_shape.h"

# define WINDOW_WIDTH 1600
# define WINDOW_HEIGHT 900
# define GAME_NAME "THE GAME"

typedef struct MainGameData
{
	void		*mlx;
	void		*mlx_window;
	t_Minimap	minimap;
	t_Player	player;
}	t_GameData;

t_StatusCode	game_data_init(t_GameData *data, char **map, t_Point2D block_count);

void	input_update_render(t_GameData *data);

/*
	input.c functions
*/
int		input_key_press(int key, t_GameData *data);

#endif