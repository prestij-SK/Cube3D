#ifndef PLAYER_H
# define PLAYER_H

# include "image.h"
# include "utils.h"
# include "color.h"
# include "draw_shape.h"
# include "for_math.h"
# include "minimap.h"

# define PLAYER_NAME "ABUBA"
# define PLAYER_ANGLE_DEFAULT 90
# define PLAYER_ROTATE_SPEED 0.08 // in Radians
# define PLAYER_MOVE_SPEED 3

typedef struct PlayerData
{
	char		*name;
	t_Point2D	pos;
	t_Point2D	size;
	int			color;
	double		angle;
	t_Point2D_d	delta;
	int			r_x; // delete
	int			r_y; // delete
}	t_Player;


t_StatusCode	player_init(t_Player *player, void *mlx, t_Point2D block_pos, int block_size);
void			player_on_minimap_draw_origin(t_Image *image, t_Player *player);
void			player_on_minimap_draw_small(t_Image *image, t_Player *player);

#endif