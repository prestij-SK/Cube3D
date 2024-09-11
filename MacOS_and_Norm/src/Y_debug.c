/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Y_debug.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <yuhayrap@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 19:03:44 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/09/09 14:05:00 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/parsing.h"
#include "../header/the_game.h"

void	print_map(char **map, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	printf("Printing map:[%dx%d] 🗺\n\n", x, y);
	if (!map)
	{
		printf("Map is NULL\n");
		return ;
	}
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '\t')
			{
				printf("TAAAAAAAAB❌\n\n\n");
			}
			j++;
		}
		printf("%s\n", map[i]);
		i++;
	}
	printf("=========================================\n");
}

void	print_line_by_char(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		printf("%d\n", str[i]);
		i++;
	}
	printf("%d\n", str[i]);
}

void	print_pdata(t_parse *p_data)
{
	printf("Textures: 🚪\n");
	printf("\tNO => %s\n", p_data->north);
	printf("\tEA => %s\n", p_data->east);
	printf("\tWE => %s\n", p_data->west);
	printf("\tSO => %s\n", p_data->south);
	printf("Colors: 🎨\n");
	printf("\tF => %d\n", p_data->floor_c);
	printf("\tC => %d\n\n", p_data->ceiling_c);
	print_map(p_data->map, p_data->block_count.x, p_data->block_count.y);
}
