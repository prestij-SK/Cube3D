/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <yuhayrap@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 14:49:50 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/09/14 14:49:55 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOOR_H
# define DOOR_H

# define DOOR_COUNT 20

# include "image.h"
# include "utils.h"

typedef struct doordata
{
	t_point2d	arr_pos;
	short		is_closed;
}	t_door;

t_statuscode	doors_data_init(t_door *doors, int *count, char **map, \
	t_point2d map_size);
int				door_is_closed(t_door *door, int count, int arr_y, int arr_x);
void			door_open(t_door *door, int count, int arr_y, int arr_x);
void			door_close(t_door *door, int count, int arr_y, int arr_x);

#endif