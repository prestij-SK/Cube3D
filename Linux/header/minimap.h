#ifndef MINIMAP_H
# define MINIMAP_H

# include "image.h"
# include "utils.h"
# include "color.h"
# include "draw_shape.h"

# define MINIMAP_NAME "Minimap"
# define MINIMAP_POSITION_X 0
# define MINIMAP_POSITION_Y 0
# define MINIMAP_BLOCK_SIZE_POWER 5

typedef struct MinimapData
{
	t_Image		origin_image;
	t_Image		small_image;
	char		*name;
	char		**map;
	int			block_size;
	t_Point2D	block_count;
	int			wall_color; // This will be changed in 4 colors, north, south, easy, west wall colors
	int			floor_color;
	short		map_draw_flag; // determines if small or origin (big) map must be drawn
}	t_Minimap;

t_StatusCode	minimap_init(t_Minimap *minimap, void *mlx, char **map, t_Point2D block_count);
void			minimap_draw_origin(t_Minimap *minimap);
void			minimap_draw_small(t_Minimap *minimap);
void			minimap_delete(t_Minimap *minimap);

#endif