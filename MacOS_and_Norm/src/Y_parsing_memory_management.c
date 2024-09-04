/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Y_parsing_memory_management.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <yuhayrap@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 17:02:34 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/08/31 17:40:52 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/the_game.h"
#include "../header/parsing.h"

void	free_ptr(void *ptr)
{
	free(ptr);
	ptr = NULL;
}

void	*free_arr(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i])
	{
		free(str[i]);
		str[i] = NULL;
		i++;
	}
	free(str[i]);
	str[i] = NULL;
	free(str);
	str = NULL;
	return (NULL);
}

t_parse	init_Pdata(void)
{
	t_parse	p_data;

	p_data.file = NULL;
	p_data.map = NULL;
    p_data.map_cpy = NULL;
	p_data.north = NULL;
	p_data.west = NULL;
	p_data.east = NULL;
	p_data.south = NULL;
	p_data.ceiling_c = -1;
	p_data.floor_c = -1;
	p_data.block_count.x = -1;
	p_data.block_count.y = -1;
	p_data.elements.north = 0;
	p_data.elements.west = 0;
	p_data.elements.east = 0;
	p_data.elements.south = 0;
	p_data.elements.door = 0;
	return (p_data);
}

void	*clean_Pdata(t_parse *p_data)
{
	free_arr(p_data->file);
	free_arr(p_data->map);
	free_arr(p_data->map_cpy);
	p_data->map = NULL;
	p_data->file = NULL;
    p_data->map_cpy = NULL;
	free_ptr(p_data->north);
	free_ptr(p_data->west);
	free_ptr(p_data->east);
	free_ptr(p_data->south);
	return (NULL);
}

void	*clean_exit(t_parse *p_data, int status)
{
	clean_Pdata(p_data);
	p_data = NULL;
	system("leaks the_game");
	exit(status);
}
