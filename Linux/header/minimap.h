#ifndef MINIMAP_H
# define MINIMAP_H

# include "image.h"
# include "utils.h"
# include "color.h"

# define MINIMAP_NAME "Minimap"
# define MINIMAP_POSITION_X 0
# define MINIMAP_POSITION_Y 0
# define MINIMAP_SQUARE_SIZE_X 50
# define MINIMAP_SQUARE_SIZE_Y 50

typedef struct MinimapData
{
	char		*name;
	t_Point2D	pos;
	t_Point2D	size;
	t_Image		image;
	int			wall_color; // This will be changed in 4 colors, north, south, easy, west wall colors
	int			floor_color;
}	t_Minimap;

t_StatusCode	minimap_init(t_Minimap *minimap, void *mlx, int size_x, int size_y);

#endif