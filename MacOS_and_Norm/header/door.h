#ifndef DOOR_H
# define DOOR_H

# define DOOR_COUNT 20

# include "image.h"
# include "utils.h"

typedef struct doordata
{
	t_Point2D	arr_pos;
	short		is_closed;
}	t_door;

t_statuscode	doors_data_init(t_door *doors, int *count, char **map, t_Point2D map_size);
int				door_is_closed(t_door *door, int count, int arr_y, int arr_x);
void			door_open(t_door *door, int count, int arr_y, int arr_x);
void			door_close(t_door *door, int count, int arr_y, int arr_x);

#endif