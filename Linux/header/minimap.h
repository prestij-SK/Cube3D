#ifndef MINIMAP_H
# define MINIMAP_H

# include "image.h"
# include "utils.h"
# include "color.h"
# include "draw_shape.h"

# define MINIMAP_NAME "Minimap"
# define MINIMAP_POSITION_X 0
# define MINIMAP_POSITION_Y 0
# define MINIMAP_BLOCK_SIZE 50

typedef struct MinimapData
{
	t_Image		image;
	char		*name;
	char		**map;
	t_Point2D	block_count;
	int			wall_color; // This will be changed in 4 colors, north, south, easy, west wall colors
	int			floor_color;
}	t_Minimap;

t_StatusCode	minimap_init(t_Minimap *minimap, void *mlx, char **map, t_Point2D block_count);
void			minimap_draw(t_Minimap *minimap);

#endif