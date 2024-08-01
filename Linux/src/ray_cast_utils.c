#include "../header/the_game.h"

static void	adjust_ray_range(t_GameData *data, t_RCutil *util)
{
	t_Line2D_d	l1;
	t_Line2D_d	l2;

	l1.start.x = util->px;
	l1.start.y = util->py;
	l1.end.x = util->rx;
	l1.end.y = util->ry;
	// if (util->rx < 0)
	// {
	// 	util->ry = intersection_point(start, end, util->block_size);
	// 	util->rx = util->block_size;
	// }
	if (util->ry < 0)
	{
		printf("p_x: %f    p_y: %f\n", util->px, util->py);
		printf("r_x: %f    r_y: %f\n", util->rx, util->ry);
		l2.start.x = 0;
		l2.start.y = 0;
		l2.end.x = data->minimap.image.size.x;
		l2.end.y = 0;
		util->rx = intersection_point(&l1, &l2, &util->rx, &util->ry);
		printf("r_x: %f    r_y: %f\n", util->rx, util->ry);
	}
	// else if (util->rx > data->minimap.image.size.x)
	// {
	// 	util->ry = intersection_point(start, end, data->minimap.image.size.x - util->block_size);
	// 	util->rx = data->minimap.image.size.x - util->block_size;
	// }
	// else if (util->ry > data->minimap.image.size.y)
	// {
	// 	util->rx = intersection_point(start, end, data->minimap.image.size.x - util->block_size);
	// 	util->ry = data->minimap.image.size.y - util->block_size;
	// }
}

void	horizontal_checking(t_GameData *data, t_RCdata *ray_data, double angle)
{
	t_RCutil	util;
	int			blocks; // maximum blocks count for horizontal or vertical lines
	double		a_tan; // negative cotangent of that angle

	util.px = data->player.initial_pos.x;
	util.py = data->player.initial_pos.y;
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
				else
				{
					util.rx += util.ox;
					util.ry += util.oy;
				}
			}
			++blocks;
		}
	}
	adjust_ray_range(data, &util);
	ray_data->hor.x = util.rx;
	ray_data->hor.y = util.ry;
	ray_data->dis_h = (int) round(distance(util.px, util.py, util.rx, util.ry));
}

void	vertical_checking(t_GameData *data, t_RCdata *ray_data, double angle)
{
	t_RCutil	util;
	int			blocks; // maximum blocks count for horizontal or vertical lines
	double		a_tan; // negative cotangent of that angle

	util.px = data->player.initial_pos.x;
	util.py = data->player.initial_pos.y;
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
				else
				{
					util.rx += util.ox;
					util.ry += util.oy;
				}
			}
			++blocks;
		}
	}
	adjust_ray_range(data, &util);
	ray_data->ver.x = (int) round(util.rx);
	ray_data->ver.y = (int) round(util.ry);
	ray_data->dis_v = (int) round(distance(util.px, util.py, util.rx, util.ry));
}