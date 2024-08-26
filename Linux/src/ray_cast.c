#include "../header/the_game.h"

#include "../header/tex.h" // DELETE

static void	ray_cast_3d_walls(t_GameData *data, t_RCdata *ray_data, int ray, double ray_angle)
{
	t_Point2D	pos;
	t_Point2D	size;
	double		ca;
	double		line_h;
	double		line_offset;

	ca = data->player.angle - ray_angle;
	ca = angle_wrapping(ca); // cos(ca) will help to fix fish eye
	line_h = (data->minimap.block_size * FPV_HEIGHT) / (ray_data->dis_f * cos(ca));
	double	ty_step = 32.0 / line_h;
	double	ty_offset = 0;
	if (line_h > FPV_HEIGHT)
	{
		ty_offset = abs((FPV_HEIGHT - line_h) / 2.0);
		line_h = FPV_HEIGHT;
	}
	line_offset = FPV_HEIGHT / 2 - line_h / 2;
	size.x = FPV_WIDTH / 240;
	size.y = line_h;
	pos.x = ray * (FPV_WIDTH / 240);
	pos.y = line_offset;

	int x = 0;
	int y = 0;
	double	ty = ty_offset * ty_step;
	double	tx;//(int) (ray_data->ray_f.y / 2.0) % 32;
	int		shade = 1;
	// if (ray_angle > P1 && ray_angle < P3)
	// 	tx = 31 - tx;

	if (ray_data->dis_v < ray_data->dis_h)
	{
		tx = (int) (ray_data->ray_f.y / 2.0) % 32;
		if (ray_angle > P1 && ray_angle < P3)
			tx = 31 - tx;
		shade = 0;
	}
	else
	{
		tx = (int) (ray_data->ray_f.x / 2.0) % 32;
		if (ray_angle > 0 && ray_angle < M_PI)
			tx = 31 - tx;
	}
	// printf("radian: %f\n", ray_angle);
	// printf("angle: %f\n", ray_angle * 180 / M_PI);

	// if (ray_data->dis_v < ray_data->dis_h)
	// 	printf("ray: %d    dis_v: %f     dis_h: %f\n", ray, ray_data->dis_v, ray_data->dis_h);
	
	while (y < size.y)
	{
		int	color = All_Textures[(int)ty * 32 + (int) tx];
		if (color == 1)
			color = COLOR_RED - (0x222222 * shade);
		else if (color == 0)
			color = COLOR_GRAY - (0x222222 * shade);

		x = 0;
		while (x < size.x)
		{
			alt_mlx_pixel_put(&data->view.image, pos.x + x, pos.y + y, color);
			++x;
		}
		ty += ty_step;
		++y;
	}
	// printf("x: %d     y: %d\n", ray_data->ray_f.x, ray_data->ray_f.y);
}

static void	set_shortest_ray_dis(t_RCdata *ray_data)
{
	if (ray_data->dis_v < ray_data->dis_h)
	{
		ray_data->dis_f = ray_data->dis_v;
		ray_data->ray_f.x = ray_data->ver.x;
		ray_data->ray_f.y = ray_data->ver.y;
	}
	else
	{
		ray_data->dis_f = ray_data->dis_h;
		ray_data->ray_f.x = ray_data->hor.x;
		ray_data->ray_f.y = ray_data->hor.y;
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
		ray_cast_3d_walls(data, &ray_data, r, ray_angle); // Draw the walls
		ray_angle += RADIAN_STEP;
		ray_angle = angle_wrapping(ray_angle);
		++r;
	}
}