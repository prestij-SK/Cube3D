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
			write(2, "Error\n", 6);
			write(2, "Map is divided to several pieces\n", 33);
			clean_exit(p_data, 1);
		}
		i++;
	}
}

char	*get_new_row(char *line, int len)
{
	char	*new_line;
	int	i;

	new_line = (char *)malloc(sizeof(char) * len + 1);
	if (!new_line)
		return (NULL);
	i = 0;
	while (line[i])
	{
		new_line[i] = line[i];
        i++;
	}
    while (i < len)
    {
    	new_line[i] = ' ';
    	i++;
    }
    new_line[i] = '\0';
    return (new_line);
}

void	make_map_rectangle(t_parse	*p_data)
{
  	int		i;
    char	*new_line;

    i = 0;
    new_line = NULL;
    while (p_data->map[i])
    {
    	if (ft_strlen(p_data->map[i]) < p_data->block_count.x)
        {
          new_line = get_new_row(p_data->map[i], p_data->block_count.x);
          if (!new_line)
          {
          	write(3, "Error\nMalloc Error\n", 19);
            clean_exit(p_data, 1);
          }
       		free_ptr(p_data->map[i]);
          p_data->map[i] = new_line;
        }
        i++;
    }
}

void	validate_map_borders(t_parse *p_data)
{
	int	i;
    int	j;

    i = 0;
}

void	flood_fill(t_parse *p_data, t_Point2D size, t_Point2D cur, char to_fill)
{
	if (cur.y < 0 || cur.y >= size.y || cur.x < 0 || cur.x >= size.x)
		return ;
	if (ft_strchr("ENSWD", p_data->map_cpy[cur.y][cur.x]))
		p_data->map_cpy[cur.y][cur.x] = '0';
	if (p_data->map_cpy[cur.y][cur.x] != to_fill)
    {
		if (p_data->map_cpy[cur.y][cur.x] == ' ')
	    {
	          printf("Error\nInvalid path\n");
	          clean_exit(p_data, 1);
	    }
		return ;
    }
	p_data->map_cpy[cur.y][cur.x] = 'F';
	flood_fill(p_data, size, (t_Point2D){cur.x - 1, cur.y}, to_fill);
	flood_fill(p_data, size, (t_Point2D){cur.x + 1, cur.y}, to_fill);
	flood_fill(p_data, size, (t_Point2D){cur.x, cur.y - 1}, to_fill);
	flood_fill(p_data, size, (t_Point2D){cur.x, cur.y + 1}, to_fill);
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

char	**ft_arrdup(char **env)
{
	int		i;
	char	**res;

	if (!env)
		return (NULL);
	i = 0;
	while (env[i])
		i++;
	res = (char **)malloc(sizeof(char *) * (i + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (env[i])
	{
		res[i] = ft_strdup(env[i]);
		if (!res[i])
		{
			free_arr(res);
			return (NULL);
		}
		i++;
	}
	res[i] = NULL;
	return (res);
}

void	validate_data(t_parse *p_data)
{
  t_Point2D	player_pos;
  
  	player_pos = get_player_pos(p_data->map);
//	validate_map_chars(p_data);
	validate_map_completeness(p_data);
    make_map_rectangle(p_data);
	p_data->map_cpy = ft_arrdup(p_data->map);
    flood_fill(p_data, p_data->block_count, player_pos, '0');
//    validate_map_emptyness(p_data);
//    validate_map_borders(p_data);
    validate_doors(p_data);
}
