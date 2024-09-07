#include "../header/the_game.h"

static void gun_textures_init(t_GameData *data)
{
	data->gun[0].img = mlx_xpm_file_to_image(data->mlx, "./texture/gun_00.xpm",
											 &data->gun[0].size.x, &data->gun[0].size.y);
	if (!data->gun[0].img)
	{
		fprintf(stderr, "Error: Failed to load texture 'gun_00.xpm'\n");
		exit(1);
	}
	data->gun[0].addr = mlx_get_data_addr(data->gun[0].img, &data->gun[0].bits_per_pixel,
										  &data->gun[0].line_length, &data->gun[0].endian);
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	data->gun[1].img = mlx_xpm_file_to_image(data->mlx, "./texture/gun_01.xpm",
											 &data->gun[1].size.x, &data->gun[0].size.y);
	if (!data->gun[1].img)
	{
		fprintf(stderr, "Error: Failed to load texture 'gun_01.xpm'\n");
		exit(1);
	}
	data->gun[1].addr = mlx_get_data_addr(data->gun[1].img, &data->gun[1].bits_per_pixel,
										  &data->gun[1].line_length, &data->gun[1].endian);
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	data->gun[2].img = mlx_xpm_file_to_image(data->mlx, "./texture/gun_02.xpm",
											 &data->gun[2].size.x, &data->gun[2].size.y);
	if (!data->gun[2].img)
	{
		fprintf(stderr, "Error: Failed to load texture 'gun_02.xpm'\n");
		exit(1);
	}
	data->gun[2].addr = mlx_get_data_addr(data->gun[2].img, &data->gun[2].bits_per_pixel,
										  &data->gun[2].line_length, &data->gun[2].endian);
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	data->gun[3].img = mlx_xpm_file_to_image(data->mlx, "./texture/gun_03.xpm",
											 &data->gun[3].size.x, &data->gun[3].size.y);
	if (!data->gun[3].img)
	{
		fprintf(stderr, "Error: Failed to load texture 'gun_03.xpm'\n");
		exit(1);
	}
	data->gun[3].addr = mlx_get_data_addr(data->gun[3].img, &data->gun[3].bits_per_pixel,
										  &data->gun[3].line_length, &data->gun[3].endian);
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	data->gun[4].img = mlx_xpm_file_to_image(data->mlx, "./texture/gun_04.xpm",
											 &data->gun[4].size.x, &data->gun[4].size.y);
	if (!data->gun[4].img)
	{
		fprintf(stderr, "Error: Failed to load texture 'gun_04.xpm'\n");
		exit(1);
	}
	data->gun[4].addr = mlx_get_data_addr(data->gun[4].img, &data->gun[4].bits_per_pixel,
										  &data->gun[4].line_length, &data->gun[4].endian);
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	data->door_tex.img = mlx_xpm_file_to_image(data->mlx, "./texture/gate.xpm",
											   &data->door_tex.size.x, &data->door_tex.size.y);
	if (!data->door_tex.img)
	{
		fprintf(stderr, "Error: Failed to load texture 'gate.xpm'\n");
		exit(1);
	}
	data->door_tex.addr = mlx_get_data_addr(data->door_tex.img, &data->door_tex.bits_per_pixel,
											&data->door_tex.line_length, &data->door_tex.endian);
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
}

static void wall_textures_init(t_GameData *data)
{
	data->north_wall.img = mlx_xpm_file_to_image(data->mlx, "./texture/bluestone.xpm",
												 &data->north_wall.size.x, &data->north_wall.size.y);
	if (!data->north_wall.img)
	{
		fprintf(stderr, "Error: Failed to load texture 'bluestone.xpm'\n");
		exit(1);
	}
	data->north_wall.addr = mlx_get_data_addr(data->north_wall.img, &data->north_wall.bits_per_pixel,
											  &data->north_wall.line_length, &data->north_wall.endian);
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	data->south_wall.img = mlx_xpm_file_to_image(data->mlx, "./texture/greystone.xpm",
												 &data->south_wall.size.x, &data->south_wall.size.y);
	if (!data->south_wall.img)
	{
		fprintf(stderr, "Error: Failed to load texture 'greystone.xpm'\n");
		exit(1);
	}
	data->south_wall.addr = mlx_get_data_addr(data->south_wall.img, &data->south_wall.bits_per_pixel,
											  &data->south_wall.line_length, &data->south_wall.endian);
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	data->west_wall.img = mlx_xpm_file_to_image(data->mlx, "./texture/redbrick.xpm",
												&data->west_wall.size.x, &data->west_wall.size.y);
	if (!data->west_wall.img)
	{
		fprintf(stderr, "Error: Failed to load texture 'redbrick.xpm'\n");
		exit(1);
	}
	data->west_wall.addr = mlx_get_data_addr(data->west_wall.img, &data->west_wall.bits_per_pixel,
											 &data->west_wall.line_length, &data->west_wall.endian);
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	data->east_wall.img = mlx_xpm_file_to_image(data->mlx, "./texture/colorstone.xpm",
												&data->east_wall.size.x, &data->east_wall.size.y);
	if (!data->east_wall.img)
	{
		fprintf(stderr, "Error: Failed to load texture 'colorstone.xpm'\n");
		exit(1);
	}
	data->east_wall.addr = mlx_get_data_addr(data->east_wall.img, &data->east_wall.bits_per_pixel,
											 &data->east_wall.line_length, &data->east_wall.endian);
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	data->view.ceiling_color = COLOR_CEILING;
	data->view.floor_color = COLOR_FLOOR;
}

void the_game(char *path)
{
	t_GameData data;
	t_parse p_data;
	t_StatusCode status;

	// game_nullify_pointers(&data);
	// status = game_mlx_init(&data);
	// if (status != SUCCESS_EXIT)
	// {
	// 	game_data_delete(&data);
	// 	error_exit(status, "mlx and mlx window init failed.");
	// }
	
	
	
	p_data = parsing(path);
	clean_Pdata(&p_data);   // When you fix this, remove this line !!!!!!!!!!


	// status = game_data_init(&data, p_data.map, p_data.block_count);
	// if (status != SUCCESS_EXIT)
	// {
	// 	game_data_delete(&data);
	// 	error_exit(status, "Game data init failed.");
	// }
	// status = set_all_parsed_data(&data, &p_data);
	// clean_Pdata_except_map(&p_data);
	// if (status != SUCCESS_EXIT)
	// {
	// 	game_data_delete(&data);
	// 	error_exit(status, "Parsed data set failed.");
	// }
	// gun_textures_init(&data);
	// data.anim_start = B_FALSE;
	// data.last_update_time = get_time();
	// input_reset_all(&data.input);
	// input_update_render(&data);
	// game_data_delete(&data);
	// success_exit(status, "Game Ended");
}
