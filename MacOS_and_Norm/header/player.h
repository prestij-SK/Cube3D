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

typedef struct PlayerData
{
	char		*name;
	t_Minimap	*minimap; // The pointer to the same minimap
	t_Point2D	pos;
	t_Point2D	size;
	int			color;
	double		angle;
	t_Point2D_d	delta;
	double		move_speed;
	double		rotate_speed;
	double		mouse_sens; // mouse sensetivity
}	t_Player;

t_StatusCode	player_init(t_Player *player, t_Minimap *minimap, t_Point2D block_pos, int block_size);
void			player_on_minimap_draw_origin(t_Image *image, t_Player *player);
void			player_on_minimap_draw_small(t_Image *image, t_Player *player);

#endif