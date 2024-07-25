#ifndef THE_GAME_H
# define THE_GAME_H

# include <stdio.h> // DELETE if needed

# include "../mlx_linux/mlx.h"
# include "utils.h"
# include "image.h"
# include "minimap.h"

# define WINDOW_WIDTH 1600
# define WINDOW_HEIGHT 900
# define GAME_NAME "THE GAME"

typedef struct MainGameData
{
	void	*mlx;
	void	*mlx_window;
	t_Image	minimap;
}	t_GameData;


t_StatusCode	game_data_init(t_GameData *data);

#endif