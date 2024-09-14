/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_from_parsed.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skedikia <skedikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 13:37:36 by skedikia          #+#    #+#             */
/*   Updated: 2024/09/14 13:38:01 by skedikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/the_game.h"

static t_statuscode	set_wall_textures_norm(t_gamedata *data, t_parse *parse)
{
	data->west_wall.img = mlx_xpm_file_to_image(data->mlx, parse->west,
			&data->west_wall.size.x, &data->west_wall.size.y);
	if (!data->west_wall.img)
		return (WALL_TEXTURE_ERROR);
	data->west_wall.addr = mlx_get_data_addr(data->west_wall.img,
			&data->west_wall.bits_per_pixel, &data->west_wall.line_length,
			&data->west_wall.endian);
	data->east_wall.img = mlx_xpm_file_to_image(data->mlx, parse->east,
			&data->east_wall.size.x, &data->east_wall.size.y);
	if (!data->east_wall.img)
		return (WALL_TEXTURE_ERROR);
	data->east_wall.addr = mlx_get_data_addr(data->east_wall.img,
			&data->east_wall.bits_per_pixel, &data->east_wall.line_length,
			&data->east_wall.endian);
	return (SUCCESS_EXIT);
}

static t_statuscode	set_wall_textures(t_gamedata *data, t_parse *parse)
{
	t_statuscode	status;

	data->north_wall.img = mlx_xpm_file_to_image(data->mlx, parse->north,
			&data->north_wall.size.x, &data->north_wall.size.y);
	if (!data->north_wall.img)
		return (WALL_TEXTURE_ERROR);
	data->north_wall.addr = mlx_get_data_addr(data->north_wall.img,
			&data->north_wall.bits_per_pixel, &data->north_wall.line_length,
			&data->north_wall.endian);
	data->south_wall.img = mlx_xpm_file_to_image(data->mlx, parse->south,
			&data->south_wall.size.x, &data->south_wall.size.y);
	if (!data->south_wall.img)
		return (WALL_TEXTURE_ERROR);
	data->south_wall.addr = mlx_get_data_addr(data->south_wall.img,
			&data->south_wall.bits_per_pixel, &data->south_wall.line_length,
			&data->south_wall.endian);
	status = set_wall_textures_norm(data, parse);
	if (status != SUCCESS_EXIT)
		return (WALL_TEXTURE_ERROR);
	return (SUCCESS_EXIT);
}

t_statuscode	set_all_parsed_data(t_gamedata *data, t_parse *parse)
{
	t_statuscode	status;

	if (!data || !parse)
		return (NULL_POINTER_ERROR);
	status = set_wall_textures(data, parse);
	if (status != SUCCESS_EXIT)
		return (status);
	data->view.ceiling_color = parse->ceiling_c;
	data->view.floor_color = parse->floor_c;
	return (SUCCESS_EXIT);
}
