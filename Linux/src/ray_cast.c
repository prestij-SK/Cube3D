#include "../header/the_game.h"

// A lot of stuff is going on here, which is read and written from internet sources.
// Will update to more readable after I see the results.
void	ray_casting(t_GameData *data)
{
	t_RCdata	ray_data;
	int			r; // rays
	double		ray_angle; // in radians

	ray_angle = data->player.angle + D_RADIAN * (FPV_VIEW_SECTOR);
	if (ray_angle < 0)
		ray_angle += P4;
	if (ray_angle > P4)
		ray_angle -= P4;
	r = 0;
	while (r < 1)
	{
		// horizontal_checking(data, &ray_data, ray_angle);
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
		line.color_end = COLOR_RED;
		line.color_start = COLOR_RED;
		line.start.x = data->player.initial_pos.x;
		line.start.y = data->player.initial_pos.y;
		line.end.x = ray_data.ver.x;
		line.end.y = ray_data.ver.y;
		printf("distance: %d\n", ray_data.dis_v);
		draw_line_Bresenham(&data->minimap.image, &line);

		ray_angle += D_RADIAN;
		if (ray_angle < 0)
			ray_angle += P4;
		if (ray_angle > P4)
			ray_angle -= P4;
		++r;
	}
}