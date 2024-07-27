#ifndef PLAYER_H
# define PLAYER_H

# include "image.h"
# include "utils.h"
# include "color.h"

# define PLAYER_NAME "ABUBA"
# define PLAYER_MINIMAP_SIZE_X 5
# define PLAYER_MINIMAP_SIZE_Y 5

typedef struct PlayerData
{
	char		*name;
	t_Point2D	pos;
	t_Point2D	size;
	int			color;
}	t_Player;


t_StatusCode	player_init(t_Player *player, void *mlx, int pos_x, int pos_y);

#endif