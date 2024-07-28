#ifndef PLAYER_H
# define PLAYER_H

# include "image.h"
# include "utils.h"
# include "color.h"
# include "draw_shape.h"

# define PLAYER_NAME "ABUBA"

typedef struct PlayerData
{
	char		*name;
	t_Point2D	pos;
	t_Point2D	size;
	int			color;
}	t_Player;


t_StatusCode	player_init(t_Player *player, void *mlx, t_Point2D block_pos, int block_size);
void			player_draw(t_Image *image, t_Player *player);

#endif