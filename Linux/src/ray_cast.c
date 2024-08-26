#include "../header/the_game.h"

#include "../header/tex.h" // DELETE

static void	set_wall_texture(t_GameData *data, t_RCdata *ray_data, double ray_angle)
{
	if (ray_data->dis_v < ray_data->dis_h)
	{
		if (ray_angle > P1 && ray_angle < P3) // West
			data->tex_p = &data->west_wall;
		else // East
			data->tex_p = &data->east_wall;
	}
	else
	{
		if (ray_angle > 0 && ray_angle < M_PI) // South
			data->tex_p = &data->south_wall;
		else // North
			data->tex_p = &data->north_wall;
	}
}

static void	texture_mapping(t_GameData *data, t_RCdata *ray_data, t_RCutil *util, double ray_angle)
{
	util->ty_step = data->tex_p->size.y / util->line_h;
	util->ty_offset = 0;
	if (util->line_h > FPV_HEIGHT)
	{
		util->ty_offset = abs((FPV_HEIGHT - util->line_h) / 2.0);
		util->line_h = FPV_HEIGHT;
	}
	if (ray_data->dis_v < ray_data->dis_h)
	{
		util->tx = (int)(ray_data->ray_f.y) % data->tex_p->size.x;
		if (ray_angle > P1 && ray_angle < P3)
		{
			util->tx = data->tex_p->size.x - 1 - util->tx;
		}
	}
	else
	{
		util->tx = (int)(ray_data->ray_f.x) % data->tex_p->size.x;
		if (ray_angle > 0 && ray_angle < M_PI)
		{
			util->tx = data->tex_p->size.x - 1 - util->tx;
		}
	}
	util->ty = util->ty_offset * util->ty_step;
}

static void	ray_cast_walls(t_GameData *data, t_RCdata *ray_data, int ray, double ray_angle)
{
	t_RCutil	util;
	t_Point2D	pos;
	t_Point2D	size;
	double		ca; // cos angle

	ca = data->player.angle - ray_angle;
	ca = angle_wrapping(ca); // cos(ca) will help to fix fish eye
	util.line_h = (data->minimap.block_size * FPV_HEIGHT) / (ray_data->dis_f * cos(ca));
	set_wall_texture(data, ray_data, ray_angle);
	texture_mapping(data, ray_data, &util, ray_angle);
	util.line_offset = FPV_HEIGHT / 2 - util.line_h / 2;
	size.x = FPV_WIDTH / RAY_COUNT;
	size.y = util.line_h;
	pos.x = ray * (FPV_WIDTH / RAY_COUNT);
	pos.y = util.line_offset;

	util.y = 0;
	while (util.y < size.y)
	{
		util.pixel_index = (int)util.ty * data->tex_p->line_length + (int)util.tx * (data->tex_p->bits_per_pixel / 8);
		util.color = *(int *)(data->tex_p->addr + util.pixel_index);

		util.x = 0;
		while (util.x < size.x)
		{
			alt_mlx_pixel_put(&data->view.image, pos.x + util.x, pos.y + util.y, util.color);
			++util.x;
		}
		util.ty += util.ty_step;
		++util.y;
	}
}

static void	draw_ray_line(t_GameData *data, t_RCdata *ray_data)
{
	t_Line2D	ray_line;

	ray_line.color_end = COLOR_RED;
	ray_line.color_start = COLOR_RED;
	ray_line.start.x = data->player.pos.x;
	ray_line.start.y = data->player.pos.y;
	ray_line.end.x = ray_data->ray_f.x;
	ray_line.end.y = ray_data->ray_f.y;
	draw_line_Bresenham(&data->minimap.origin_image, &ray_line);
}

// A lot of stuff is going on here, which is read and written from internet sources.
// Will update to more readable after I see the results.
void	ray_casting(t_GameData *data)
{
	t_RCdata	ray_data;
	int			r; // rays
	double		ray_angle; // in radians

	ray_angle = data->player.angle + ONE_DEGREE_RADIAN * (SECTOR_ANGLE);
	ray_angle = angle_wrapping(ray_angle);
	r = 0;
	while (r < RAY_COUNT)
	{
		horizontal_checking(data, &ray_data, ray_angle);
		vertical_checking(data, &ray_data, ray_angle);
		set_shortest_ray_dis(&ray_data); // Final Line
		draw_ray_line(data, &ray_data); // Draw the ray
		ray_cast_walls(data, &ray_data, r, ray_angle); // Draw the walls
		ray_angle += RADIAN_STEP;
		ray_angle = angle_wrapping(ray_angle);
		++r;
	}
}