/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <yuhayrap@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 14:20:08 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/09/14 14:20:11 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/the_game.h"

void	set_shortest_ray_dis(t_rcdata *ray_data)
{
	if (!ray_data)
		return ;
	if (ray_data->dis_v < ray_data->dis_h)
	{
		ray_data->dis_f = ray_data->dis_v;
		ray_data->ray_f.x = ray_data->ver.x;
		ray_data->ray_f.y = ray_data->ver.y;
		if (ray_data->v_closed_door == B_TRUE)
			ray_data->f_closed_door = B_TRUE;
	}
	else
	{
		ray_data->dis_f = ray_data->dis_h;
		ray_data->ray_f.x = ray_data->hor.x;
		ray_data->ray_f.y = ray_data->hor.y;
		if (ray_data->h_closed_door == B_TRUE)
			ray_data->f_closed_door = B_TRUE;
	}
}

void	draw_ray_line(t_gamedata *data, t_rcdata *ray_data)
{
	t_line2d	ray_line;

	ray_line.color_end = COLOR_RED;
	ray_line.color_start = COLOR_RED;
	ray_line.start.x = data->player.pos.x;
	ray_line.start.y = data->player.pos.y;
	ray_line.end.x = ray_data->ray_f.x;
	ray_line.end.y = ray_data->ray_f.y;
	draw_line_bresenham(&data->minimap.origin_image, &ray_line);
}
