#include "../header/the_game.h"

void	vertical_checking(t_GameData *data, t_RCdata *ray_data, double angle)
{
	t_RCutil	util;
	int			blocks; // maximum blocks count for horizontal or vertical lines
	double		a_tan; // negative cotangent of that angle

	util.px = data->player.pos.x;
	util.py = data->player.pos.y;
	util.block_power = MINIMAP_BLOCK_SIZE_POWER;
	util.block_size = pow(2, MINIMAP_BLOCK_SIZE_POWER);
	a_tan = -tan(angle); // negative tangent
	if (angle > P1 && angle < P3) // ray is looking up
	{
		util.rx = (((int) util.px >> util.block_power) << util.block_power) - 0.0001; // 6 here because my block size is 64 ? Also I think I don't need (int)
		util.ry = (util.px - util.rx) * a_tan + util.py;
		util.ox = -util.block_size;
		util.oy = -util.ox * a_tan;
	}
	if (angle < P1 || angle > P3) // ray is looking down
	{
		util.rx = (((int) util.px >> util.block_power) << util.block_power) + util.block_size; // this is some math...
		util.ry = (util.px - util.rx) * a_tan + util.py;
		util.ox = util.block_size;
		util.oy = -util.ox * a_tan;
	}
	if (angle == 0 || angle == M_PI) // looking straigth left or straigth right, ther eis no point to check for Horizontal lines
	{
		util.rx = util.px;
		util.ry = util.py;
	}
	else
	{
		blocks = 0;
		while (blocks < data->minimap.block_count.y)
		{
			util.mx = (int) (util.rx) >> util.block_power;
			util.my = (int) (util.ry) >> util.block_power;
			if (util.mx < 0 || util.my < 0)
				break ;
			if (util.mx < data->minimap.block_count.x && util.my < data->minimap.block_count.y)
			{
				if (data->minimap.map[util.my][util.mx] == '1')
					break ;
				else
				{
					util.rx += util.ox;
					util.ry += util.oy;
				}
			}
			++blocks;
		}
	}
	// adjust_ray_range(data, &util);
	ray_data->ver.x = util.rx;
	ray_data->ver.y = util.ry;
	ray_data->dis_v = distance(util.px, util.py, util.rx, util.ry);
}