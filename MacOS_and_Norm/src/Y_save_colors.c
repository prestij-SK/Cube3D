/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Y_save_colors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <yuhayrap@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 17:49:01 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/09/09 15:22:16 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/parsing.h"
#include "../header/the_game.h"

static int	check_is_digit(char **colors)
{
	int	i;

	i = 0;
	while (colors[0][i])
	{
		if (!ft_isdigit(colors[0][i]))
			return (0);
		i++;
	}
	i = 0;
	while (colors[1][i])
	{
		if (!ft_isdigit(colors[1][i]))
			return (0);
		i++;
	}
	i = 0;
	while (colors[2][i])
	{
		if (!ft_isdigit(colors[2][i]))
			return (0);
		i++;
	}
	return (1);
}

static t_rgb	fill_color(char **colors)
{
	t_rgb	color;

	color.r = ft_atoi_check(colors[0]);
	color.g = ft_atoi_check(colors[1]);
	color.b = ft_atoi_check(colors[2]);
	free_arr(colors);
	return (color);
}

static int	get_color(char *line)
{
	char	**colors;
	t_rgb	rgb;

	if (ft_strstr(line, ",,"))
		return (DOUBLE_COMMAS);
	if (line[0] == ',' || line[ft_strlen(line) - 1] == ',')
		return (COMMA_EDGE);
	colors = ft_split(line, ',');
	if (!colors)
		return (MALLOC);
	if (arr_len(colors) != 3)
	{
		free_arr(colors);
		return (TOO_MANY_VALUES);
	}
	if (!check_is_digit(colors))
	{
		free_arr(colors);
		return (INVALID_COLOR_VALUES);
	}
	rgb = fill_color(colors);
	if (rgb.r < 0 || rgb.g < 0 || rgb.b < 0 || rgb.r > 255 || rgb.g > 255
		|| rgb.b > 255)
		return (INVALID_RANGE);
	return ((rgb.r << 16) + (rgb.g << 8) + rgb.b);
}

int	save_floor_color(t_parse *p_data, char *str)
{
	char	**key_value;
	int		len;

	if (p_data->floor_c != -1)
		return (DOUBLICATE);
	key_value = ft_split(str, ' ');
	if (!key_value)
		return (MALLOC);
	len = arr_len(key_value);
	if (len != 2)
	{
		free_arr(key_value);
		return (resolve_type(len));
	}
	if (ft_strcmp(key_value[0], "F") != 0)
	{
		free_arr(key_value);
		return (INVALID_KEY);
	}
	p_data->floor_c = get_color(key_value[1]);
	free_arr(key_value);
	if (p_data->floor_c < 0)
		return (p_data->floor_c);
	return (1);
}

int	save_ceill_color(t_parse *p_data, char *str)
{
	char	**key_value;
	int		len;

	if (p_data->ceiling_c != -1)
		return (DOUBLICATE);
	key_value = ft_split(str, ' ');
	if (!key_value)
		return (MALLOC);
	len = arr_len(key_value);
	if (len != 2)
	{
		free_arr(key_value);
		return (resolve_type(len));
	}
	if (ft_strcmp(key_value[0], "C") != 0)
	{
		free_arr(key_value);
		return (INVALID_KEY);
	}
	p_data->ceiling_c = get_color(key_value[1]);
	free_arr(key_value);
	if (p_data->ceiling_c < 0)
		return (p_data->ceiling_c);
	return (1);
}
