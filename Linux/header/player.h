#ifndef PLAYER_H
# define PLAYER_H

# include "image.h"
# include "utils.h"
# include "color.h"
# include "draw_shape.h"
# include "for_math.h"

# define PLAYER_NAME "ABUBA"
# define PLAYER_ANGLE_DEFAULT 0
# define PLAYER_ROTATE_SPEED 0.1 // in Radians
# define PLAYER_MOVE_SPEED_MULTIPLIER 5

typedef struct PlayerData
{
	char		*name;
	t_Point2D	initial_pos;
	t_Point2D	size;
	int			color;
	double		angle;
	t_Point2D_d	delta;
	int			r_x; // delete
	int			r_y; // delete
}	t_Player;


t_StatusCode	player_init(t_Player *player, void *mlx, t_Point2D block_pos, int block_size);
void			player_draw(t_Image *image, t_Player *player);

#endif