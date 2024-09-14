/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <yuhayrap@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 14:20:37 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/09/14 14:20:45 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/the_game.h"

static t_statuscode	door_texture_init(t_gamedata *data)
{
	data->door_tex.img = mlx_xpm_file_to_image(data->mlx, "./texture/gate.xpm",
			&data->door_tex.size.x, &data->door_tex.size.y);
	if (!data->door_tex.img)
		return (DOOR_TEXTURE_ERROR);
	data->door_tex.addr = mlx_get_data_addr(data->door_tex.img,
			&data->door_tex.bits_per_pixel, &data->door_tex.line_length,
			&data->door_tex.endian);
	data->easter_tex.img = mlx_xpm_file_to_image(data->mlx,
			"./texture/flag.xpm", &data->easter_tex.size.x,
			&data->easter_tex.size.y);
	if (!data->easter_tex.img)
		return (DOOR_TEXTURE_ERROR);
	data->easter_tex.addr = mlx_get_data_addr(data->easter_tex.img,
			&data->easter_tex.bits_per_pixel, &data->easter_tex.line_length,
			&data->easter_tex.endian);
	data->easter_found = B_FALSE;
	return (SUCCESS_EXIT);
}

static t_statuscode	gun_textures_init_norm(t_gamedata *data)
{
	data->gun[2].img = mlx_xpm_file_to_image(data->mlx, "./texture/gun_02.xpm",
			&data->gun[2].size.x, &data->gun[2].size.y);
	if (!data->gun[2].img)
		return (GUN_TEXTURE_ERROR);
	data->gun[2].addr = mlx_get_data_addr(data->gun[2].img,
			&data->gun[2].bits_per_pixel, &data->gun[2].line_length,
			&data->gun[2].endian);
	data->gun[3].img = mlx_xpm_file_to_image(data->mlx, "./texture/gun_03.xpm",
			&data->gun[3].size.x, &data->gun[3].size.y);
	if (!data->gun[3].img)
		return (GUN_TEXTURE_ERROR);
	data->gun[3].addr = mlx_get_data_addr(data->gun[3].img,
			&data->gun[3].bits_per_pixel, &data->gun[3].line_length,
			&data->gun[3].endian);
	data->gun[4].img = mlx_xpm_file_to_image(data->mlx, "./texture/gun_04.xpm",
			&data->gun[4].size.x, &data->gun[4].size.y);
	if (!data->gun[4].img)
		return (GUN_TEXTURE_ERROR);
	data->gun[4].addr = mlx_get_data_addr(data->gun[4].img,
			&data->gun[4].bits_per_pixel, &data->gun[4].line_length,
			&data->gun[4].endian);
	return (SUCCESS_EXIT);
}

static t_statuscode	gun_textures_init(t_gamedata *data)
{
	t_statuscode	status;

	data->gun[0].img = mlx_xpm_file_to_image(data->mlx, "./texture/gun_00.xpm",
			&data->gun[0].size.x, &data->gun[0].size.y);
	if (!data->gun[0].img)
		return (GUN_TEXTURE_ERROR);
	data->gun[0].addr = mlx_get_data_addr(data->gun[0].img,
			&data->gun[0].bits_per_pixel, &data->gun[0].line_length,
			&data->gun[0].endian);
	data->gun[1].img = mlx_xpm_file_to_image(data->mlx, "./texture/gun_01.xpm",
			&data->gun[1].size.x, &data->gun[0].size.y);
	if (!data->gun[1].img)
		return (GUN_TEXTURE_ERROR);
	data->gun[1].addr = mlx_get_data_addr(data->gun[1].img,
			&data->gun[1].bits_per_pixel, &data->gun[1].line_length,
			&data->gun[1].endian);
	status = gun_textures_init_norm(data);
	return (status);
}

static void	the_game_norm(t_gamedata *data, t_statuscode status)
{
	status = gun_textures_init(data);
	if (status != SUCCESS_EXIT)
	{
		game_data_delete(data);
		error_exit(status, "Gun textures init failed.");
	}
	status = door_texture_init(data);
	if (status != SUCCESS_EXIT)
	{
		game_data_delete(data);
		error_exit(status, "Door textures init failed.");
	}
	data->anim_start = B_FALSE;
	data->last_update_time = get_time();
	input_reset_all(&data->input);
	input_update_render(data);
	game_data_delete(data);
	success_exit(status, "Game Ended");
}

// I added the t_StatusCode parameter just for norminette...
void	the_game(char *path, t_statuscode status)
{
	t_gamedata	data;
	t_parse		p_data;

	game_nullify_pointers(&data);
	status = game_mlx_init(&data);
	if (status != SUCCESS_EXIT)
	{
		game_data_delete(&data);
		error_exit(status, "mlx and mlx window init failed.");
	}
	p_data = parsing(path);
	status = game_data_init(&data, p_data.map, p_data.block_count);
	if (status != SUCCESS_EXIT)
	{
		game_data_delete(&data);
		error_exit(status, "Game data init failed.");
	}
	status = set_all_parsed_data(&data, &p_data);
	clean_pdata_except_map(&p_data);
	if (status != SUCCESS_EXIT)
	{
		game_data_delete(&data);
		error_exit(status, "Parsed data set failed.");
	}
	the_game_norm(&data, status);
}
