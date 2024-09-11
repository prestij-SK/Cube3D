/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Y_validate_map_chars.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <yuhayrap@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 13:23:07 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/09/09 14:11:25 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/parsing.h"
#include "../header/the_game.h"

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
	{
		ft_putstr_fd(RED, STD_ERR);
		ft_putstr_fd("Error\n", STD_ERR);
		ft_putstr_fd(YELLOW, STD_ERR);
		ft_putstr_fd("Invalid char in map: ", STD_ERR);
		ft_putchar_fd(ch, STD_ERR);
		ft_putstr_fd("\n", STD_ERR);
		ft_putstr_fd(DEFAULT, STD_ERR);
		return (0);
	}
	return (1);
}

static void	too_many_err(t_parse *p_data, char *str)
{
	ft_putstr_fd(RED, STD_ERR);
	ft_putstr_fd("Error\n", STD_ERR);
	ft_putstr_fd(YELLOW, STD_ERR);
	ft_putstr_fd("several player positon set for ", STD_ERR);
	ft_putstr_fd(str, STD_ERR);
	ft_putstr_fd(" : \"", STD_ERR);
	ft_putchar_fd(str[0], STD_ERR);
	ft_putstr_fd("\"\n", STD_ERR);
	ft_putstr_fd(DEFAULT, STD_ERR);
	clean_exit(p_data, 1);
}

static int	check_if_only_one_player(t_parse *p_data)
{
	if (p_data->elements.north == 1 && (p_data->elements.west > 0
			|| p_data->elements.south > 0 || p_data->elements.east > 0))
		return (0);
	else if (p_data->elements.west == 1 && (p_data->elements.north > 0
			|| p_data->elements.south > 0 || p_data->elements.east > 0))
		return (0);
	else if (p_data->elements.east == 1 && (p_data->elements.west > 0
			|| p_data->elements.south > 0 || p_data->elements.north > 0))
		return (0);
	else if (p_data->elements.south == 1 && (p_data->elements.west > 0
			|| p_data->elements.north > 0 || p_data->elements.east > 0))
		return (0);
	return (1);
}

// we can also add doors validation
// Need to add funciton which just print error message and change this
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
	if (p_data->elements.north == 0 && p_data->elements.west == 0
		&& p_data->elements.east == 0 && p_data->elements.south == 0)
	{
		print_err_message("No player position set\n");
		clean_exit(p_data, 1);
	}
	if (!check_if_only_one_player(p_data))
	{
		print_err_message("different player positon set\n");
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
