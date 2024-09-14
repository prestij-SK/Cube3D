/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <yuhayrap@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 14:19:55 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/09/14 14:27:31 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minimap.h"

static t_statuscode	minimap_small_image_init(t_minimap *minimap, void *mlx,
		t_point2d pos, t_point2d size)
{
	t_point2d	new_size;

	new_size.x = size.x / MINIMAP_SIZE_DIVISER;
	new_size.y = size.y / MINIMAP_SIZE_DIVISER;
	return (image_init(&minimap->small_image, mlx, pos, new_size));
}

static void	block_count_resolving_norm(t_minimap *minimap,
		t_point2d block_count)
{
	minimap->block_count.x = block_count.x;
	minimap->block_count.y = block_count.y;
	if (block_count.x > block_count.y)
		minimap->block_max = block_count.x;
	else
		minimap->block_max = block_count.y;
}

t_statuscode	minimap_init(t_minimap *minimap, void *mlx, char **map,
		t_point2d block_count)
{
	t_statuscode	status;
	t_point2d		pos;
	t_point2d		size;

	if (!minimap || !mlx)
		return (NULL_POINTER_ERROR);
	pos.x = MINIMAP_POSITION_X;
	pos.y = MINIMAP_POSITION_Y;
	minimap->block_size = (int)pow(2, MINIMAP_BLOCK_SIZE_POWER);
	size.x = (block_count.x * minimap->block_size);
	size.y = (block_count.y * minimap->block_size);
	status = image_init(&minimap->origin_image, mlx, pos, size);
	if (status != SUCCESS_EXIT)
		return (status);
	status = minimap_small_image_init(minimap, mlx, pos, size);
	if (status != SUCCESS_EXIT)
		return (status);
	minimap->name = MINIMAP_NAME;
	minimap->map = map;
	block_count_resolving_norm(minimap, block_count);
	minimap->wall_color = COLOR_WHITE;
	minimap->floor_color = COLOR_BLUE;
	minimap->map_draw_flag = B_FALSE;
	return (SUCCESS_EXIT);
}

static void	big_map_draw_part_norm(t_minimap *minimap, t_point2d pos,
		t_point2d size)
{
	if (minimap->map[minimap->norm_i][minimap->norm_j] == '1')
		draw_rectangle_filled(&minimap->origin_image, pos, size,
			minimap->wall_color);
	else if (minimap->map[minimap->norm_i][minimap->norm_j] == 'D')
	{
		if (door_is_closed(minimap->doors, minimap->door_count, minimap->norm_i,
				minimap->norm_j) == B_TRUE)
			draw_rectangle_filled(&minimap->origin_image, pos, size, COLOR_RED);
		else
			draw_rectangle_filled(&minimap->origin_image, pos, size,
				COLOR_GREEN);
	}
	else
		draw_rectangle_filled(&minimap->origin_image, pos, size,
			minimap->floor_color);
}

void	minimap_draw_origin(t_minimap *minimap)
{
	t_point2d	size;
	t_point2d	pos;

	if (!minimap)
		return ;
	size.x = minimap->block_size;
	size.y = minimap->block_size;
	minimap->norm_i = 0;
	while (minimap->norm_i < minimap->block_count.y)
	{
		minimap->norm_j = 0;
		while (minimap->norm_j < minimap->block_count.x)
		{
			pos.x = (minimap->norm_j * minimap->block_size);
			pos.y = (minimap->norm_i * minimap->block_size);
			big_map_draw_part_norm(minimap, pos, size);
			++minimap->norm_j;
		}
		++minimap->norm_i;
	}
}
