#include "../header/door.h"

int	door_is_closed(t_Door *door, int count, int arr_y, int arr_x)
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
		}
		++i;
	}
	return (B_FALSE);	
}

void	door_open(t_Door *door, int count, int arr_y, int arr_x)
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

void	door_close(t_Door *door, int count, int arr_y, int arr_x)
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

t_StatusCode	doors_data_init(t_Door *doors, int *count, char **map, t_Point2D map_size)
{
	int	i;
	int	j;

	if (!doors || !map)
		return (NULL_POINTER_ERROR);
	*count = 0;
	i = 0;
	while (i < map_size.y)
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
		++i;
	}
	return (SUCCESS_EXIT);
}