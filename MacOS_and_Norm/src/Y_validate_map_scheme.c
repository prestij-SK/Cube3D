/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Y_validate_map_scheme.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skedikia <skedikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 14:45:53 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/09/14 13:43:41 by skedikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/parsing.h"
#include "../header/the_game.h"

static int	is_border_empty(t_parse *p_data, t_point2d cur)
{
	if (cur.x == 0 || cur.y == 0 || cur.x == p_data->block_count.x - 1 || \
		cur.y == p_data->block_count.y - 1)
	{
		return (p_data->map_cpy[cur.y][cur.x] == '0' || \
			p_data->map_cpy[cur.y][cur.x] == 'D');
	}
	return (0);
}

void	validate_invalid_path(t_parse *p_data, t_point2d size, t_point2d cur,
		char to_fill)
{
	if (cur.y < 0 || cur.y >= size.y || cur.x < 0 || cur.x >= size.x)
		return ;
	if (ft_strchr("ENSWD", p_data->map_cpy[cur.y][cur.x]))
		p_data->map_cpy[cur.y][cur.x] = '0';
	if (p_data->map_cpy[cur.y][cur.x] != to_fill)
	{
		if (p_data->map_cpy[cur.y][cur.x] == ' ')
		{
			print_err_message("Invalid path\n");
			clean_exit(p_data, 1);
		}
		return ;
	}
	else if (is_border_empty(p_data, cur))
	{
		print_err_message("Invalid path\n");
		clean_exit(p_data, 1);
	}
	p_data->map_cpy[cur.y][cur.x] = 'F';
	validate_invalid_path(p_data, size, (t_point2d){cur.x - 1, cur.y}, to_fill);
	validate_invalid_path(p_data, size, (t_point2d){cur.x + 1, cur.y}, to_fill);
	validate_invalid_path(p_data, size, (t_point2d){cur.x, cur.y - 1}, to_fill);
	validate_invalid_path(p_data, size, (t_point2d){cur.x, cur.y + 1}, to_fill);
}

static int	door_condition(char **map, int i, int j, t_point2d size)
{
	int	vertical;
	int	horizontal;

	vertical = 0;
	horizontal = 0;
	if (i > 0 && i != size.y - 1)
	{
		if (map[i - 1][j] == '1' && map[i + 1][j] == '1')
			vertical++;
	}
	else
		vertical++;
	if (j > 0 && j != size.x - 1)
	{
		if (map[i][j - 1] == '1' && map[i][j + 1] == '1')
			horizontal++;
	}
	else
		horizontal++;
	return (vertical || horizontal);
}

void	validate_doors(t_parse *p_data)
{
	int	i;
	int	j;

	i = -1;
	while (p_data->map[++i])
	{
		j = -1;
		while (p_data->map[i][++j])
		{
			if (p_data->map[i][j] == 'D' && \
				!door_condition(p_data->map, i, j, p_data->block_count))
			{
				print_err_message("Doors should be surounded by walls line: ");
				ft_putstr_fd(YELLOW, STD_ERR);
				ft_putnbr_fd(i + 1, STD_ERR);
				ft_putstr_fd("\n", STD_ERR);
				ft_putendl_fd(p_data->map[i], STD_ERR);
				ft_putstr_fd(DEFAULT, STD_ERR);
				clean_exit(p_data, 1);
			}
		}
	}
}
