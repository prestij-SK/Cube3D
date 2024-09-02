/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Y_validate_map_chars.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <yuhayrap@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 13:23:07 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/08/31 17:41:19 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/the_game.h"
#include "../header/parsing.h"

static int	resolve_char_error(char ch)
{
	write(2, "Invalid char in map: ", 21);
	write(2, &ch, 1);
	write(2, "\n", 1);
	return (0);
}

static int	check_chars(char ch, t_parse *p_data)
{
	if (ch == 'N')
		p_data->elements.north++;
	else if (ch == 'W')
		p_data->elements.west++;
	else if (ch == 'S')
		p_data->elements.south++;
	else if (ch == 'E')
		p_data->elements.east++;
	else if (ch == 'D')
		p_data->elements.door++;
	else if (ch == '1' || ch == ' ' || ch == '0')
		return (1);
	else
		return (resolve_char_error(ch));
	return (1);
}

static void	too_many_err(t_parse *p_data, char *str)
{
	write(2, "Error\n", 6);
	write(2, "several player positon set for ", 31);
	write(2, str, ft_strlen(str));
	write(2, " : \"", 4);
	write(2, str, 1);
	write(2, "\"\n", 2);
	clean_exit(p_data, 1);
}

static int	check_if_only_one_player(t_parse *p_data)
{
	if (p_data->elements.north == 1 && (p_data->elements.west > 0 || \
		p_data->elements.south > 0 || p_data->elements.east > 0))
		return (0);
	else if (p_data->elements.west == 1 && (p_data->elements.north > 0 || \
		p_data->elements.south > 0 || p_data->elements.east > 0))
		return (0);
	else if (p_data->elements.east == 1 && (p_data->elements.west > 0 || \
		p_data->elements.south > 0 || p_data->elements.north > 0))
		return (0);
	else if (p_data->elements.south == 1 && (p_data->elements.west > 0 || \
		p_data->elements.north > 0 || p_data->elements.east > 0))
		return (0);
	return (1);
}

//we can also add doors validation 
static void	check_player_count(t_parse *p_data)
{
	if (p_data->elements.north > 1)
		too_many_err(p_data, "North");
	else if (p_data->elements.west > 1)
		too_many_err(p_data, "West");
	else if (p_data->elements.east > 1)
		too_many_err(p_data, "East");
	else if (p_data->elements.south > 1)
		too_many_err(p_data, "South");
	if (p_data->elements.north == 0 && p_data->elements.west == 0 && \
		p_data->elements.east == 0 && p_data->elements.south == 0)
	{
		write(2, "Error\n", 6);
		write(2, "No player position set\n", 23);
		clean_exit(p_data, 1);
	}
	if (!check_if_only_one_player(p_data))
	{
		write(2, "Error\n", 6);
		write(2, "different player positon set\n", 29);
		clean_exit(p_data, 1);
	}
}

void	validate_map_chars(t_parse *p_data)
{
	int	i;
	int	j;

	i = 0;
	while (p_data->map[i])
	{
		j = 0;
		while (p_data->map[i][j])
		{
			if (!check_chars(p_data->map[i][j], p_data))
				clean_exit(p_data, 1);
			j++;
		}
		i++;
	}
	check_player_count(p_data);
}
