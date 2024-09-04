/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Y_validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <yuhayrap@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 17:00:53 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/08/31 18:49:57 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/the_game.h"
#include "../header/parsing.h"

int	is_valid_map_name(char *name)
{
	int	i;

	i = ft_strlen(name) - 1;
	if (name[i--] != 'b')
		return (0);
	if (name[i--] != 'u')
		return (0);
	if (name[i--] != 'c')
		return (0);
	if (name[i--] != '.')
		return (0);
	return (1);
}

int	check_textures_and_colors(t_parse *p_data)
{
	if (!p_data->north || !p_data->west || !p_data->east || !p_data->south)
		return (-1);
	if (p_data->floor_c == -1 || p_data->ceiling_c == -1)
		return (-2);
	return (1);
}

void	validate_map_completeness(t_parse *p_data)
{
	int	i;

	i = 0;
	while (p_data->map[i])
	{
		if (is_empty(p_data->map[i]))
		{
			ft_putstr_fd(RED, STD_ERR);
			ft_putstr_fd("Error\n", STD_ERR);
			ft_putstr_fd(YELLOW, STD_ERR);
			ft_putstr_fd("Map is divided to several pieces\n", STD_ERR);
			ft_putstr_fd(DEFAULT, STD_ERR);
			clean_exit(p_data, 1);
		}
		i++;
	}
}

t_Point2D get_player_pos(char **map)
{
  t_Point2D	pos;
  
  pos.y = 0;
  while (map[pos.y])
  {
    pos.x = 0;
    while ( map[pos.y][pos.x])
    {
      	if (map[pos.y][pos.x] == 'N' || map[pos.y][pos.x] == 'E' || \
          	map[pos.y][pos.x] == 'W' || map[pos.y][pos.x] == 'S')
         	return (pos);
        pos.x++;
    }
    pos.y++;
  }
  return (pos);
}

void	validate_data(t_parse *p_data)
{
  t_Point2D	player_pos;

	validate_map_chars(p_data);
	validate_map_completeness(p_data);
    make_map_rectangle(p_data);
	p_data->map_cpy = ft_arrdup(p_data->map);
    if (!p_data->map_cpy)
    {
    	ft_putstr_fd(RED, STD_ERR);
    	ft_putstr_fd("Error\n", STD_ERR);
    	ft_putstr_fd(YELLOW, STD_ERR);
    	ft_putstr_fd("Malloc error\n", STD_ERR);
    	ft_putstr_fd(DEFAULT, STD_ERR);
    	clean_exit(p_data, 1);
    }
  	player_pos = get_player_pos(p_data->map);
    validate_invalid_path(p_data, p_data->block_count, player_pos, '0');
	validate_borders(p_data);
    validate_doors(p_data);
}
