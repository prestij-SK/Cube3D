#ifndef PLAYER_H
# define PLAYER_H

# include "image.h"
# include "utils.h"
# include "color.h"
# include "draw_shape.h"
# include "for_math.h"
# include "minimap.h"

# define PLAYER_NAME "ABUBA"
# define PLAYER_ANGLE_DEFAULT 90 // South
# define PLAYER_ROTATE_SPEED 0.05 // in Radians
# define PLAYER_MOUSE_SENSITIVITY 0.008 // in Radians
# define PLAYER_MOVE_SPEED 5

typedef struct playerdata
{
	char		*name;
	t_minimap	*minimap; // The pointer to the same minimap
	t_Point2D	pos;
	t_Point2D	size;
	int			color;
	double		angle;
	t_point2d_d	delta;
	double		move_speed;
	double		rotate_speed;
	double		mouse_sens; // mouse sensetivity
}	t_player;

t_statuscode	player_init(t_player *player, t_minimap *minimap, t_Point2D block_pos, int block_size);
void			player_on_minimap_draw_origin(t_image *image, t_player *player);
void			player_on_minimap_draw_small(t_image *image, t_player *player);

#endif