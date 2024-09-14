#ifndef MINIMAP_H
# define MINIMAP_H

# include "image.h"
# include "utils.h"
# include "color.h"
# include "draw_shape.h"
# include "door.h"

# define MINIMAP_NAME "Minimap"
# define MINIMAP_POSITION_X 0
# define MINIMAP_POSITION_Y 0
# define MINIMAP_BLOCK_SIZE_POWER 6 // for 2^6 = 64

typedef struct minimapdata
{
	t_image		origin_image;
	t_image		small_image;
	char		*name;
	char		**map;
	int			block_size;
	t_point2d	block_count;
	int			wall_color; // This will be changed in 4 colors, north, south, easy, west wall colors
	int			floor_color;
	short		map_draw_flag; // determines if small or origin (big) map must be drawn
	t_door		doors[DOOR_COUNT];
	int			door_count;
	int			norm_i;
	int			norm_j;
	int			block_max;
}	t_minimap;

t_statuscode	minimap_init(t_minimap *minimap, void *mlx, char **map, t_point2d block_count);
void			minimap_draw_origin(t_minimap *minimap);
void			minimap_draw_small(t_minimap *minimap);
void			minimap_delete(t_minimap *minimap);

#endif