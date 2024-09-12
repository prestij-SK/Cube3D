#include "../header/the_game.h"

static void vertical_checking_norm(t_RCutil *util, double *a_tan, double angle)
{
	util->block_power = MINIMAP_BLOCK_SIZE_POWER;
	util->block_size = pow(2, MINIMAP_BLOCK_SIZE_POWER);
	*a_tan = -tan(angle);
	if (angle > P1 && angle < P3)
	{
		util->rx = (((int)util->px >> util->block_power) << util->block_power) - 0.0001;
		util->ry = (util->px - util->rx) * (*a_tan) + util->py;
		util->ox = -util->block_size;
		util->oy = -util->ox * (*a_tan);
	}
	if (angle < P1 || angle > P3)
	{
		util->rx = (((int)util->px >> util->block_power) << util->block_power) + util->block_size;
		util->ry = (util->px - util->rx) * (*a_tan) + util->py;
		util->ox = util->block_size;
		util->oy = -util->ox * (*a_tan);
	}
}

static void	vertical_checking_blocks_norm(t_RCutil *util, t_GameData *data, t_RCdata *ray_data, int blocks)
{
	while (++blocks < data->minimap.block_count.x)
	{
		util->mx = (int)(util->rx) >> util->block_power;
		util->my = (int)(util->ry) >> util->block_power;
		if (util->mx < 0 || util->my < 0)
			break;
		if (util->mx < data->minimap.block_count.x && util->my < data->minimap.block_count.y)
		{
			if (data->minimap.map[util->my][util->mx] == '1')
				break;
			if (data->minimap.map[util->my][util->mx] == ' ')
				break;
			if (data->minimap.map[util->my][util->mx] == 'D')
			{
				if (door_is_closed(data->minimap.doors, data->minimap.door_count, util->my, util->mx) == B_TRUE)
				{
					ray_data->v_closed_door = B_TRUE;
					break;
				}
			}
			util->rx += util->ox;
			util->ry += util->oy;
		}
	}
}

void vertical_checking(t_GameData *data, t_RCdata *ray_data, double angle)
{
	t_RCutil	util;
	double		a_tan;
	int			blocks;

	util.px = data->player.pos.x;
	util.py = data->player.pos.y;
	vertical_checking_norm(&util, &a_tan, angle);
	if (angle == 0 || angle == M_PI)
	{
		util.rx = util.px;
		util.ry = util.py;
	}
	else
	{
		blocks = -1;
		vertical_checking_blocks_norm(&util, data, ray_data, blocks);
		
	}
	ray_data->ver.x = util.rx;
	ray_data->ver.y = util.ry;
	ray_data->dis_v = distance(util.px, util.py, util.rx, util.ry);
}