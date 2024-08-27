#ifndef DOOR_H
# define DOOR_H

# define DOOR_COUNT 20 // maximum number of doors in game

# include "image.h"
# include "utils.h"

typedef struct DoorData
{
	t_Point2D	arr_pos;
	short		is_closed;
}	t_Door;

t_StatusCode	doors_data_init(t_Door *doors, int *count, char **map, t_Point2D map_size);
int				door_is_closed(t_Door *door, int count, int arr_y, int arr_x);
void			door_open(t_Door *door, int count, int arr_y, int arr_x);
void			door_close(t_Door *door, int count, int arr_y, int arr_x);

#endif