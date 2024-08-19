#include "../header/the_game.h"

#include "../header/tex.h" // DELETE

#define EPSILON 1e-6

void	ray_cast_3d_walls(t_GameData *data, t_RCdata *ray_data, int ray, double ray_angle)
{
	t_Point2D	pos;
	t_Point2D	size;
	double		ca;
	double		line_h;
	double		line_offset;

	ca = data->player.angle - ray_angle;
	if (ca < 0)
		ca += P4;
	if (ca > P4)
		ca -= P4;
	line_h = (data->minimap.block_size * FPV_HEIGHT) / (ray_data->dis_f * cos(ca));
	double	ty_step = 32.0 / line_h;
	double	ty_offset = 0;
	if (line_h > FPV_HEIGHT)
	{
		ty_offset = abs((FPV_HEIGHT - line_h) / 2.0);
		line_h = FPV_HEIGHT;
	}
	line_offset = FPV_HEIGHT / 2 - line_h / 2;
	size.x = FPV_WIDTH / 60;
	size.y = line_h;
	pos.x = ray * (FPV_WIDTH / 60);
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


// A lot of stuff is going on here, which is read and written from internet sources.
// Will update to more readable after I see the results.
void	ray_casting(t_GameData *data)
{
	t_RCdata	ray_data;
	int			r; // rays
	double		ray_angle; // in radians

	ray_angle = data->player.angle + D_RADIAN * (-30);
	if (ray_angle < 0)
		ray_angle += P4;
	if (ray_angle > P4)
		ray_angle -= P4;
	r = 0;
	while (r < 60)
	{
		horizontal_checking(data, &ray_data, ray_angle);
		vertical_checking(data, &ray_data, ray_angle);
		t_Line2D	line;
		// Horizontal Line
		// line.color_end = COLOR_RED;
		// line.color_start = COLOR_RED;
		// line.start.x = data->player.initial_pos.x;
		// line.start.y = data->player.initial_pos.y;
		// line.end.x = ray_data.hor.x;
		// line.end.y = ray_data.hor.y;
		// printf("distance: %d\n", ray_data.dis_h);
		// draw_line_Bresenham(&data->minimap.image, &line);

		// Vertical Line
		// line.color_end = COLOR_RED;
		// line.color_start = COLOR_RED;
		// line.start.x = data->player.initial_pos.x;
		// line.start.y = data->player.initial_pos.y;
		// line.end.x = ray_data.ver.x;
		// line.end.y = ray_data.ver.y;
		// printf("distance: %d\n", ray_data.dis_v);
		// draw_line_Bresenham(&data->minimap.image, &line);

		// Final Line
		line.color_end = COLOR_RED;
		line.color_start = COLOR_RED;
		line.start.x = data->player.initial_pos.x;
		line.start.y = data->player.initial_pos.y;
		if (ray_data.dis_h < ray_data.dis_v)
		{
			line.end.x = ray_data.hor.x;
			line.end.y = ray_data.hor.y;
			ray_data.dis_f = ray_data.dis_h;
			ray_data.ray_f.x = ray_data.hor.x;
			ray_data.ray_f.y = ray_data.hor.y;
		}
		else
		{
			line.end.x = ray_data.ver.x;
			line.end.y = ray_data.ver.y;
			ray_data.dis_f = ray_data.dis_v;
			ray_data.ray_f.x = ray_data.ver.x;
			ray_data.ray_f.y = ray_data.ver.y;
		}
		// if (ray_data.dis_v < ray_data.dis_h)
			draw_line_Bresenham(&data->minimap.image, &line);

		ray_cast_3d_walls(data, &ray_data, r, ray_angle);
		ray_angle += D_RADIAN;
		if (ray_angle < 0)
			ray_angle += P4;
		if (ray_angle > P4)
			ray_angle -= P4;
		++r;
	}
}