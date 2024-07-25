#ifndef MINIMAP_H
# define MINIMAP_H

# include "image.h"
# include "utils.h"
# include "color.h"

# define MINIMAP_NAME "Minimap"
# define MINIMAP_BACKGROUND_COLOR 
# define MINIMAP_POSITION_X 0
# define MINIMAP_POSITION_Y 0

t_StatusCode	minimap_init(t_Image *image, void *mlx, int size_x, int size_y);

#endif