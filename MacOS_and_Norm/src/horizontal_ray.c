/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horizontal_ray.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <yuhayrap@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 14:18:12 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/09/14 15:03:02 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/the_game.h"

static void	horizontal_checking_norm(t_rcutil *util, double *a_tan,
		double angle)
{
	util->block_power = MINIMAP_BLOCK_SIZE_POWER;
	util->block_size = pow(2, MINIMAP_BLOCK_SIZE_POWER);
	*a_tan = -1 / tan(angle);
	if (angle > M_PI)
	{
		util->ry = (((int)util->py >> util->block_power) << util->block_power)
			- 0.0001;
		util->rx = (util->py - util->ry) * (*a_tan) + util->px;
		util->oy = -util->block_size;
		util->ox = -util->oy * (*a_tan);
	}
	if (angle < M_PI)
	{
		util->ry = (((int)util->py >> util->block_power) << util->block_power)
			+ util->block_size;
		util->rx = (util->py - util->ry) * (*a_tan) + util->px;
		util->oy = util->block_size;
		util->ox = -util->oy * (*a_tan);
	}
}

static void	special_for_norm(t_rcutil *util)
{
	util->rx += util->ox;
	util->ry += util->oy;
}

static void	horizontal_checking_blocks_norm(t_rcutil *util, t_gamedata *data,
		t_rcdata *ray_data, int blocks)
{
	while (++blocks < data->minimap.block_max)
	{
		util->mx = (int)(util->rx) >> util->block_power;
		util->my = (int)(util->ry) >> util->block_power;
		if (util->mx < 0 || util->my < 0)
			break ;
		if (util->mx < data->minimap.block_count.x
			&& util->my < data->minimap.block_count.y)
		{
			if (data->minimap.map[util->my][util->mx] == '1')
				break ;
			if (data->minimap.map[util->my][util->mx] == ' ')
				break ;
			if (data->minimap.map[util->my][util->mx] == 'D')
			{
				if (door_is_closed(data->minimap.doors,
						data->minimap.door_count, util->my, util->mx) == B_TRUE)
				{
					ray_data->h_closed_door = B_TRUE;
					break ;
				}
			}
			special_for_norm(util);
		}
	}
}

void	horizontal_checking(t_gamedata *data, t_rcdata *ray_data, double angle)
{
	t_rcutil	util;
	double		a_tan;
	int			blocks;

	util.px = data->player.pos.x;
	util.py = data->player.pos.y;
	horizontal_checking_norm(&util, &a_tan, angle);
	if (angle == 0 || angle == M_PI)
	{
		util.rx = util.px;
		util.ry = util.py;
	}
	else
	{
		blocks = -1;
		horizontal_checking_blocks_norm(&util, data, ray_data, blocks);
	}
	ray_data->hor.x = util.rx;
	ray_data->hor.y = util.ry;
	ray_data->dis_h = distance(util.px, util.py, util.rx, util.ry);
}
