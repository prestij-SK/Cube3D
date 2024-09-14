/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skedikia <skedikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 13:38:13 by skedikia          #+#    #+#             */
/*   Updated: 2024/09/14 13:43:41 by skedikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/door.h"

int	door_is_closed(t_door *door, int count, int arr_y, int arr_x)
{
	int	i;

	if (!door)
		return (B_FALSE);
	i = 0;
	while (i < count)
	{
		if (door[i].arr_pos.x == arr_x && door[i].arr_pos.y == arr_y)
		{
			if (door[i].is_closed == B_TRUE)
				return (B_TRUE);
			else
				return (B_FALSE);
		}
		++i;
	}
	return (B_FALSE);
}

void	door_open(t_door *door, int count, int arr_y, int arr_x)
{
	int	i;

	if (!door)
		return ;
	i = 0;
	while (i < count)
	{
		if (door[i].arr_pos.x == arr_x && door[i].arr_pos.y == arr_y)
		{
			door[i].is_closed = B_FALSE;
			return ;
		}
		++i;
	}
}

void	door_close(t_door *door, int count, int arr_y, int arr_x)
{
	int	i;

	if (!door)
		return ;
	i = 0;
	while (i < count)
	{
		if (door[i].arr_pos.x == arr_x && door[i].arr_pos.y == arr_y)
		{
			door[i].is_closed = B_TRUE;
			return ;
		}
		++i;
	}
}

t_statuscode	doors_data_init(t_door *doors, int *count, char **map,
		t_point2d map_size)
{
	int	i;
	int	j;

	if (!doors || !map)
		return (NULL_POINTER_ERROR);
	*count = 0;
	i = -1;
	while (++i < map_size.y)
	{
		j = 0;
		while (j < map_size.x)
		{
			if (map[i][j] == 'D')
			{
				if (*count == DOOR_COUNT)
					return (DOOR_NUMBER_ERROR);
				doors[*count].arr_pos.x = j;
				doors[*count].arr_pos.y = i;
				doors[*count].is_closed = B_TRUE;
				++(*count);
			}
			++j;
		}
	}
	return (SUCCESS_EXIT);
}
