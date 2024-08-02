#include "../header/the_game.h"

void	ray_cast_3d_walls(t_GameData *data, t_RCdata *ray_data, int ray, double ray_angle)
{
	t_Point2D	pos;
	t_Point2D	size;
	int			line_h;
	int			offset;
	double		ca;

	ca = data->player.angle - ray_angle;
	if (ca < 0)
		ca += P4;
	if (ca > P4)
		ca -= P4;
	ray_data->dis_f = ray_data->dis_f * cos(ca); // fish eye fix
	line_h = (data->view.image.size.y * data->minimap.block_size) / ray_data->dis_f;
	if (line_h > data->view.image.size.y)
		line_h = data->view.image.size.y;
	offset = data->view.image.size.y - (line_h / 2);
	pos.x = ray * (data->view.image.size.x / 88);
	pos.y = offset - data->view.image.size.y / 2;
	size.x = data->view.image.size.x / 88;
	size.y = line_h;
	printf("height: %d\n", line_h);
	draw_rectangle_filled(&data->view.image, pos, size, COLOR_RED);
}

// A lot of stuff is going on here, which is read and written from internet sources.
// Will update to more readable after I see the results.
void	ray_casting(t_GameData *data)
{
	t_RCdata	ray_data;
	int			r; // rays
	double		ray_angle; // in radians

	ray_angle = data->player.angle + D_RADIAN * (-45);
	if (ray_angle < 0)
		ray_angle += P4;
	if (ray_angle > P4)
		ray_angle -= P4;
	r = 0;
	while (r < 90)
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
		}
		else
		{
			line.end.x = ray_data.ver.x;
			line.end.y = ray_data.ver.y;
			ray_data.dis_f = ray_data.dis_v;
		}
		// printf("distance: %d\n", ray_data.dis_f);
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