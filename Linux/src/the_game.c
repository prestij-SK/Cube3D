#include "../header/the_game.h"

static void	wall_textures_init(t_GameData *data)
{
	data->north_wall.img = mlx_xpm_file_to_image(data->mlx, "/home/steve/Desktop/the_game/Linux/texture/bluestone.xpm",
												&data->north_wall.size.x, &data->north_wall.size.y);
	if (!data->north_wall.img)
	{
		fprintf(stderr, "Error: Failed to load texture 'bluestone.xpm'\n");
		exit(1);
	}
	data->north_wall.addr = mlx_get_data_addr(data->north_wall.img, &data->north_wall.bits_per_pixel,
											 &data->north_wall.line_length, &data->north_wall.endian);
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	data->south_wall.img = mlx_xpm_file_to_image(data->mlx, "/home/steve/Desktop/the_game/Linux/texture/greystone.xpm",
												&data->south_wall.size.x, &data->south_wall.size.y);
	if (!data->south_wall.img)
	{
		fprintf(stderr, "Error: Failed to load texture 'greystone.xpm'\n");
		exit(1);
	}
	data->south_wall.addr = mlx_get_data_addr(data->south_wall.img, &data->south_wall.bits_per_pixel,
											 &data->south_wall.line_length, &data->south_wall.endian);
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	data->west_wall.img = mlx_xpm_file_to_image(data->mlx, "/home/steve/Desktop/the_game/Linux/texture/redbrick.xpm",
												&data->west_wall.size.x, &data->west_wall.size.y);
	if (!data->west_wall.img)
	{
		fprintf(stderr, "Error: Failed to load texture 'redbrick.xpm'\n");
		exit(1);
	}
	data->west_wall.addr = mlx_get_data_addr(data->west_wall.img, &data->west_wall.bits_per_pixel,
											 &data->west_wall.line_length, &data->west_wall.endian);
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	data->east_wall.img = mlx_xpm_file_to_image(data->mlx, "/home/steve/Desktop/the_game/Linux/texture/colorstone.xpm",
												&data->east_wall.size.x, &data->east_wall.size.y);
	if (!data->east_wall.img)
	{
		fprintf(stderr, "Error: Failed to load texture 'colorstone.xpm'\n");
		exit(1);
	}
	data->east_wall.addr = mlx_get_data_addr(data->east_wall.img, &data->east_wall.bits_per_pixel,
											 &data->east_wall.line_length, &data->east_wall.endian);

	data->view.ceiling_color = COLOR_CEILING;
	data->view.floor_color = COLOR_FLOOR;
}

void	the_game(char *path)
{
	t_GameData		data;
	t_Point2D		block_count;
	t_StatusCode	status;
	char			**map;

	game_nullify_pointers(&data);
	status = game_mlx_init(&data);
	if (status != SUCCESS_EXIT)
	{
		game_data_delete(&data);
		error_exit(status, "mlx and mlx window init failed.");
	}

	int size_y = 10;
	int	size_x = 9;
	int	i = 0;
	int	j = 0;

	map = (char **)malloc(sizeof(char *) * size_y);
	i = 0;
	while (i < size_y)
	{
		map[i] = (char *)malloc(sizeof(char) * size_x);
		++i;
	}
	
	char	other_map[10][9] =
	{
		{'1', '1', '1', '1', '1', '1', '1', '1', '1'},
		{'1', '0', '0', '0', '0', '0', '0', '0', '1'},
		{'1', '0', '1', '0', '0', '0', '1', '0', '1'},
		{'1', '0', '0', '0', '1', '0', '0', '0', '1'},
		{'1', '0', '1', '0', '0', '0', '1', '0', '1'},
		{'1', '0', '0', '0', '1', '0', '0', '0', '1'},
		{'1', '0', '1', '0', '0', '0', '1', '0', '1'},
		{'1', '0', '0', 'P', '1', '0', '0', '0', '1'},
		{'1', '0', '0', '0', '0', '0', '0', '0', '1'},
		{'1', '1', '1', '1', '1', '1', '1', '1', '1'}
	};

	i = 0;
	while (i < size_y)
	{
		j = 0;
		while (j < size_x)
		{
			map[i][j] = other_map[i][j];
			++j;
		}
		++i;
	}
	
	block_count.x = size_x;
	block_count.y = size_y;
	// Yura's function must called like this:
	// map = map_parsing(&data, &block_count);   ->   char	**map_parsing(t_GameData *data, t_Point2D *block_count);
	status = game_data_init(&data, map, block_count);
	if (status != SUCCESS_EXIT)
	{
		game_data_delete(&data);
		error_exit(status, "Game data init failed.");
	}
	wall_textures_init(&data); // Yura must do this in his function. But it must always be after game_data_init !
	data.last_update_time = get_time();
	input_reset_all(&data.input);
	input_update_render(&data);
	success_exit(status, "Game Ended");
}