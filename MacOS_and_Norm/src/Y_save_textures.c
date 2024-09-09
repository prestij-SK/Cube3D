/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Y_save_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <yuhayrap@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 15:38:53 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/09/09 14:31:32 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/parsing.h"
#include "../header/the_game.h"

int	resolve_type(int len)
{
	if (len > 2)
		return (TOO_MANY_VALUES);
	return (TOO_FEW_VALUES);
}

int	save_north(t_parse *p_data, char *str)
{
	char	**key_value;
	int		len;

	if (p_data->north != NULL)
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
	if (ft_strcmp(key_value[0], "NO") != 0)
	{
		free_arr(key_value);
		return (INVALID_KEY);
	}
	p_data->north = ft_strdup(key_value[1]);
	free_arr(key_value);
	if (!p_data->north)
		return (MALLOC);
	return (1);
}

int	save_west(t_parse *p_data, char *str)
{
	char	**key_value;
	int		len;

	if (p_data->west != NULL)
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
	if (ft_strcmp(key_value[0], "WE") != 0)
	{
		free_arr(key_value);
		return (INVALID_KEY);
	}
	p_data->west = ft_strdup(key_value[1]);
	free_arr(key_value);
	if (!p_data->west)
		return (MALLOC);
	return (1);
}

int	save_east(t_parse *p_data, char *str)
{
	char	**key_value;
	int		len;

	if (p_data->east != NULL)
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
	if (ft_strcmp(key_value[0], "EA") != 0)
	{
		free_arr(key_value);
		return (INVALID_KEY);
	}
	p_data->east = ft_strdup(key_value[1]);
	free_arr(key_value);
	if (!p_data->east)
		return (MALLOC);
	return (1);
}

int	save_south(t_parse *p_data, char *str)
{
	char	**key_value;
	int		len;

	if (p_data->south != NULL)
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
	if (ft_strcmp(key_value[0], "SO") != 0)
	{
		free_arr(key_value);
		return (INVALID_KEY);
	}
	p_data->south = ft_strdup(key_value[1]);
	free_arr(key_value);
	if (!p_data->south)
		return (MALLOC);
	return (1);
}
