/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Y_map_parsing_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <yuhayrap@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 14:13:20 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/09/09 14:07:30 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/parsing.h"
#include "../header/the_game.h"

char	*replace_tab_with_spaces(char **map, int i, int j)
{
	char	*new_str;
	int		n;

	new_str = malloc(sizeof(char) * (ft_strlen(map[i]) + 5));
	if (!new_str)
	{
		free_arr(map);
		err_message("Malloc error\n");
	}
	n = -1;
	while (++n < j)
		new_str[n] = map[i][n];
	new_str[n++] = ' ';
	new_str[n++] = ' ';
	new_str[n++] = ' ';
	new_str[n] = ' ';
	while (map[i][++j])
		new_str[++n] = map[i][j];
	new_str[++n] = '\0';
	return (new_str);
}

void	tabs_to_spaces(char **map)
{
	int		i;
	int		j;
	char	*new;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == '\t')
			{
				new = replace_tab_with_spaces(map, i, j);
				free(map[i]);
				map[i] = new;
			}
		}
	}
}

static char	*get_new_row(char *line, int len)
{
	char	*new_line;
	int		i;

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

void	make_map_rectangle(t_parse *p_data)
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
				print_err_message("Malloc error\n");
				clean_exit(p_data, 1);
			}
			free(p_data->map[i]);
			p_data->map[i] = NULL;
			p_data->map[i] = new_line;
		}
		i++;
	}
}
