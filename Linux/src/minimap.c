#include "../header/minimap.h"

t_StatusCode	minimap_init(t_Minimap *minimap, void *mlx, char **map, t_Point2D block_count)
{
	t_StatusCode status;
	t_Point2D pos;
	t_Point2D size;

	if (!minimap || !mlx)
		return (NULL_POINTER_ERROR);
	pos.x = MINIMAP_POSITION_X;
	pos.y = MINIMAP_POSITION_Y;
	size.x = block_count.x * MINIMAP_BLOCK_SIZE;
	size.y = block_count.y * MINIMAP_BLOCK_SIZE;
	status = image_init(&minimap->image, mlx, pos, size);
	if (status != SUCCESS_EXIT)
		return (status);
	minimap->name = MINIMAP_NAME;
	minimap->map = map;
	minimap->block_count.x = block_count.x;
	minimap->block_count.y = block_count.y;
	minimap->wall_color = COLOR_WHITE;
	minimap->floor_color = COLOR_BLUE;
	return (SUCCESS_EXIT);
}

void	minimap_draw(t_Minimap *minimap)
{
	t_Point2D size;
	t_Point2D pos;
	int i;
	int j;

	if (!minimap)
		return;
	size.x = MINIMAP_BLOCK_SIZE;
	size.y = MINIMAP_BLOCK_SIZE;
	i = 0;
	while (i < minimap->block_count.y)
	{
		j = 0;
		while (j < minimap->block_count.x)
		{
			pos.x = j * MINIMAP_BLOCK_SIZE;
			pos.y = i * MINIMAP_BLOCK_SIZE;
			if (minimap->map[i][j] == '1')
				draw_rectangle_filled(&minimap->image, pos, size, minimap->wall_color);
			// else if (minimap->map[i][j] == '0') // change this to else
			else {
				draw_rectangle_filled(&minimap->image, pos, size, minimap->floor_color);
			}
			++j;
		}
		++i;
	}
}