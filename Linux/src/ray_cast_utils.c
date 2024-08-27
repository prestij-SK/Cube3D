#include "../header/the_game.h"

void	adjust_ray_range(t_GameData *data, t_RCutil *util)
{
	t_Line2D_d	l1;
	t_Line2D_d	l2;

	l1.start.x = util->px;
	l1.start.y = util->py;
	l1.end.x = util->rx;
	l1.end.y = util->ry;
	if (util->rx < 0)
	{
		l2.start.x = data->minimap.block_size;
		l2.start.y = 0;
		l2.end.x = data->minimap.block_size;
		l2.end.y = data->minimap.origin_image.size.y;
		intersection_point(&l1, &l2, &util->rx, &util->ry);
	}
	if (util->ry < 0)
	{
		l2.start.x = 0;
		l2.start.y = data->minimap.block_size;
		l2.end.x = data->minimap.origin_image.size.x;
		l2.end.y = data->minimap.block_size;
		intersection_point(&l1, &l2, &util->rx, &util->ry);
	}
	if (util->rx > data->minimap.origin_image.size.x)
	{
		l2.start.x = data->minimap.origin_image.size.x - data->minimap.block_size;
		l2.start.y = 0;
		l2.end.x = data->minimap.origin_image.size.x - data->minimap.block_size;
		l2.end.y = data->minimap.origin_image.size.y;
		intersection_point(&l1, &l2, &util->rx, &util->ry);
	}
	if (util->ry > data->minimap.origin_image.size.y)
	{
		l2.start.x = 0;
		l2.start.y = data->minimap.origin_image.size.y - data->minimap.block_size;
		l2.end.x = data->minimap.origin_image.size.x;
		l2.end.y = data->minimap.origin_image.size.y - data->minimap.block_size;
		intersection_point(&l1, &l2, &util->rx, &util->ry);
	}
}

void	set_shortest_ray_dis(t_RCdata *ray_data)
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