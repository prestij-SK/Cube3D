#include "../header/minimap.h"

t_StatusCode	minimap_init(t_Minimap *minimap, void *mlx, int size_x, int size_y)
{
	t_StatusCode	status;

	if (!minimap)
		return (NULL_POINTER_ERROR);
	status = image_init(&minimap->image, mlx, size_x, size_y);
	if (status != SUCCESS_EXIT)
		return (status);
	minimap->name = MINIMAP_NAME;
	minimap->size.x = size_x;
	minimap->size.y = size_y;
	minimap->pos.x = MINIMAP_POSITION_X;
	minimap->pos.y = MINIMAP_POSITION_Y;
	minimap->floor_color = COLOR_BLUE;
	minimap->wall_color = COLOR_WHITE;
	return (SUCCESS_EXIT);
}

// void	minimap_draw(t_Minimap *minimap, char **map, int size_x, int size_y)
// {
// 	int i = 0;
// 	int j = 0;

// 	i = 0;
// 	while (i < size_x)
// 	{
// 		j = 0;
// 		while (j < size_y)
// 		{

// 			++j;
// 		}
// 		++i;
// 	}
// }