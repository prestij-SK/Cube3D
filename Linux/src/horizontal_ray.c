#include "../header/the_game.h"

void	horizontal_checking(t_GameData *data, t_RCdata *ray_data, double angle)
{
	t_RCutil	util;
	int			blocks; // maximum blocks count for horizontal or vertical lines
	double		a_tan;

	util.px = data->player.pos.x;
	util.py = data->player.pos.y;
	util.block_power = MINIMAP_BLOCK_SIZE_POWER;
	util.block_size = pow(2, MINIMAP_BLOCK_SIZE_POWER);
	a_tan = -1 / tan(angle); // negative cotangent of that angle
	if (angle > M_PI) // ray is looking up
	{
		util.ry = (((int) util.py >> util.block_power) << util.block_power) - 0.0001; // 6 here because my block size is 64 ? Also I think I don't need (int)
		util.rx = (util.py - util.ry) * a_tan + util.px;
		util.oy = -util.block_size;
		util.ox = -util.oy * a_tan;
	}
	if (angle < M_PI) // ray is looking down
	{
		util.ry = (((int) util.py >> util.block_power) << util.block_power) + util.block_size; // this is some math...
		util.rx = (util.py - util.ry) * a_tan + util.px;
		util.oy = util.block_size;
		util.ox = -util.oy * a_tan;
	}
	if (angle == 0 || angle == M_PI) // looking straigth left or straigth right, ther eis no point to check for Horizontal lines
	{
		util.rx = util.px;
		util.ry = util.py;
	}
	else
	{
		blocks = 0;
		while (blocks < data->minimap.block_count.x)
		{
			util.mx = (int) (util.rx) >> util.block_power;
			util.my = (int) (util.ry) >> util.block_power;
			if (util.mx < 0 || util.my < 0)
				break ;
			if (util.mx < data->minimap.block_count.x && util.my < data->minimap.block_count.y)
			{
				if (data->minimap.map[util.my][util.mx] == '1')
					break ;
				if (data->minimap.map[util.my][util.mx] == 'D')
				{
					if (door_is_closed(data->minimap.doors, data->minimap.door_count, util.my, util.mx) == B_TRUE)
					{
						ray_data->h_closed_door = B_TRUE;
						break ;
					}
				}
				util.rx += util.ox;
				util.ry += util.oy;
			}
			++blocks;
		}
	}
	// adjust_ray_range(data, &util); // turn this on if you want to see only horizontal ray
	ray_data->hor.x = util.rx;
	ray_data->hor.y = util.ry;
	ray_data->dis_h = distance(util.px, util.py, util.rx, util.ry);
}