#include "../header/minimap.h"

static void	small_map_draw_part_norm(t_minimap *minimap, t_Point2D pos, t_Point2D size)
{
	if (minimap->map[minimap->norm_i][minimap->norm_j] == '1')
		draw_rectangle_filled(&minimap->small_image, pos, size, minimap->wall_color);
	else if (minimap->map[minimap->norm_i][minimap->norm_j] == 'D')
	{
		if (door_is_closed(minimap->doors, minimap->door_count, minimap->norm_i, minimap->norm_j) == B_TRUE)
			draw_rectangle_filled(&minimap->small_image, pos, size, COLOR_RED);
		else
			draw_rectangle_filled(&minimap->small_image, pos, size, COLOR_GREEN);
	}
	else
		draw_rectangle_filled(&minimap->small_image, pos, size, minimap->floor_color);
}

// small minimap
void	minimap_draw_small(t_minimap *minimap)
{
	t_Point2D size;
	t_Point2D pos;

	if (!minimap)
		return;
	size.x = minimap->block_size / MINIMAP_SIZE_DIVISER;
	size.y = minimap->block_size / MINIMAP_SIZE_DIVISER;
	minimap->norm_i = 0;
	while (minimap->norm_i < minimap->block_count.y)
	{
		minimap->norm_j = 0;
		while (minimap->norm_j < minimap->block_count.x)
		{
			pos.x = (minimap->norm_j * minimap->block_size) / MINIMAP_SIZE_DIVISER;
			pos.y = (minimap->norm_i * minimap->block_size) / MINIMAP_SIZE_DIVISER;
			small_map_draw_part_norm(minimap, pos, size);
			++minimap->norm_j;
		}
		++minimap->norm_i;
	}
}