/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Y_parsing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <yuhayrap@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 13:03:35 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/09/09 14:50:56 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/the_game.h"
#include "../header/parsing.h"

static int	is_file_empty(char **file)
{
	int	i;

	i = 0;
	while (file[i])
	{
		if (!is_empty(file[i]))
			return (0);
		i++;
	}
	return (1);
}

static void	parsing1(t_parse *p_data, char *path)
{
	int		fd;
	int		status;

	fd = open_file(path);
	p_data->file = read_file(fd);
	close(fd);
	if (!p_data->file || is_file_empty(p_data->file))
	{
		if (p_data->file)
			free_arr(p_data->file);
		err_message("File is empty\n");
	}
	tabs_to_spaces(p_data->file);
	status = get_textures_and_colors(p_data);
	if (status < 0)
		clean_exit(p_data, 1);
	status = check_textures_and_colors(p_data);
	if (status < 0)
	{
		if (status == -1)
			print_err_message("textures missing\n");
		if (status == -2)
			print_err_message("colors missing\n");
		clean_exit(p_data, 1);
	}
}

static void	parsing2(t_parse *p_data)
{
	int	status;

	status = init_map(p_data);
	if (status < 0)
	{
		clean_pdata(p_data);
		err_message("Malloc Error\n");
	}
	if (!p_data->map || !p_data->map[0])
	{
		clean_pdata(p_data);
		err_message("Map is Empty\n");
	}
}

//need to write Error\n before every error !!!!!//
t_parse	parsing(char *path)
{
	t_parse	p_data;
	int		i;
	int		max;

	if (!is_valid_map_name(path))
		err_message("Invalid map name maps should have '.cub' format\n");
	p_data = init_pdata();
	parsing1(&p_data, path);
	parsing2(&p_data);
	i = 1;
	max = ft_strlen(p_data.map[0]);
	while (p_data.map[i])
	{
		if (ft_strlen(p_data.map[i]) > max)
			max = ft_strlen(p_data.map[i]);
		i++;
	}
	p_data.block_count.x = max;
	p_data.block_count.y = i;
	validate_data(&p_data);
	return (p_data);
}
