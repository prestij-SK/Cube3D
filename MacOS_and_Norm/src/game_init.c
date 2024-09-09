#include "../header/the_game.h"

static void map_del(t_Minimap *minimap)
{
	int	i;

	i = 0;
	while (minimap->map[i])
	{
		free(minimap->map[i]);
		minimap->map[i] = NULL;
		++i;
	}
	free(minimap->map[i]);
	minimap->map[i] = NULL;
	free(minimap->map);
	minimap->map = NULL;
}

void	game_data_delete(t_GameData *data)
{
	if (!data)
		return ;
	map_del(&data->minimap);
	image_delete(&data->minimap.origin_image, data->mlx);
	image_delete(&data->minimap.small_image, data->mlx);
	image_delete(&data->view.image, data->mlx);
	image_delete(&data->north_wall, data->mlx);
	image_delete(&data->south_wall, data->mlx);
		printf("here\n");
	image_delete(&data->west_wall, data->mlx);
	image_delete(&data->east_wall, data->mlx);
	image_delete(&data->door_tex, data->mlx);
	image_delete(&data->gun[0], data->mlx);
	image_delete(&data->gun[1], data->mlx);
	image_delete(&data->gun[2], data->mlx);
	image_delete(&data->gun[3], data->mlx);
	image_delete(&data->gun[4], data->mlx);
	if (data->mlx && data->mlx_window)
		mlx_destroy_window(data->mlx, data->mlx_window);
	// if (data->mlx)
	// 	mlx_destroy_display(data->mlx);
}

void	game_nullify_pointers(t_GameData *data)
{
	if (!data)
		return ;
	data->mlx = NULL;
	data->mlx_window = NULL;
	data->tex_p = NULL;
	data->minimap.map = NULL;
	data->minimap.small_image.img = NULL;
	data->minimap.small_image.addr = NULL;
	data->minimap.origin_image.img = NULL;
	data->minimap.origin_image.addr = NULL;
	data->view.image.img = NULL;
	data->view.image.addr = NULL;
	data->north_wall.img = NULL;
	data->north_wall.addr = NULL;
	data->south_wall.img = NULL;
	data->south_wall.addr = NULL;
	data->west_wall.img = NULL;
	data->west_wall.addr = NULL;
	data->east_wall.img = NULL;
	data->east_wall.addr = NULL;
	data->door_tex.img = NULL;
	data->door_tex.addr = NULL;
	data->gun[0].img = NULL;
	data->gun[0].addr = NULL;
	data->gun[1].img = NULL;
	data->gun[1].addr = NULL;
	data->gun[2].img = NULL;
	data->gun[2].addr = NULL;
	data->gun[3].img = NULL;
	data->gun[3].addr = NULL;
	data->gun[4].img = NULL;
	data->gun[4].addr = NULL;
}

static t_Point2D	player_location(char **map, t_Point2D block_count)
{
	t_Point2D	pos;
	int			i;
	int			j;

	pos.x = -1;
	pos.y = -1;
	if (!map)
		return (pos);
	i = 0;
	while (i < block_count.y)
	{
		j = 0;
		while (j < block_count.x)
		{
			if (map[i][j] == 'N' || map[i][j] == 'S' ||
				map[i][j] == 'E' || map[i][j] == 'W')
			{
				pos.x = j;
				pos.y = i;
				return (pos);
			}
			++j;
		}
		++i;
	}
	return (pos);
}

t_StatusCode	game_mlx_init(t_GameData *data)
{
	if (!data)
		return (NULL_POINTER_ERROR);
	data->mlx = mlx_init();
	if (!data->mlx)
		return (MLX_ERROR);
	data->mlx_window = mlx_new_window(data->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, GAME_NAME);
	if (!data->mlx_window)
		return (MLX_WINDOW_ERROR);
	return (SUCCESS_EXIT);
}

t_StatusCode	game_data_init(t_GameData *data, char **map, t_Point2D block_count)
{
	t_StatusCode	status;
	t_Point2D		pos;

	if (!data || !map)
		return (NULL_POINTER_ERROR);
	status = minimap_init(&data->minimap, data->mlx, map, block_count);
	if (status != SUCCESS_EXIT)
		return (status);
	pos = player_location(map, block_count);
	status = player_init(&data->player, &data->minimap, pos, data->minimap.block_size);
	if (status != SUCCESS_EXIT)
		return (status);
	status = fp_view_init(&data->view, data->mlx);
	if (status != SUCCESS_EXIT)
		return (status);
	status = doors_data_init(data->minimap.doors, &data->minimap.door_count, data->minimap.map, data->minimap.block_count);
	if (status != SUCCESS_EXIT)
		return (status);
	input_reset_all(&data->input);
	return (SUCCESS_EXIT);
}