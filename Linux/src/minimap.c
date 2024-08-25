#include "../header/minimap.h"

void	minimap_delete(t_Minimap *minimap)
{
	if (!minimap)
		return ;
	int i = 0;
	while (i < minimap->block_count.y)
	{
		free(minimap->map[i]);
		++i;
	}
	free(minimap->map);
	minimap->map = NULL;
}

t_StatusCode	minimap_init(t_Minimap *minimap, void *mlx, char **map, t_Point2D block_count)
{
	t_StatusCode status;
	t_Point2D pos;
	t_Point2D size;

	if (!minimap || !mlx)
		return (NULL_POINTER_ERROR);
	pos.x = MINIMAP_POSITION_X;
	pos.y = MINIMAP_POSITION_Y;
	minimap->block_size = (int) pow(2, MINIMAP_BLOCK_SIZE_POWER);
	size.x = block_count.x * minimap->block_size;
	size.y = block_count.y * minimap->block_size;
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
	size.x = minimap->block_size;
	size.y = minimap->block_size;
	i = 0;
	while (i < minimap->block_count.y)
	{
		j = 0;
		while (j < minimap->block_count.x)
		{
			pos.x = j * minimap->block_size;
			pos.y = i * minimap->block_size;
			if (minimap->map[i][j] == '1')
				draw_rectangle_filled(&minimap->image, pos, size, minimap->wall_color);
			else // if (minimap->map[i][j] == '0') // change this to else
				draw_rectangle_filled(&minimap->image, pos, size, minimap->floor_color);
			++j;
		}
		++i;
	}
}