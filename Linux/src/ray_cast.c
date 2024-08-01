#include "../header/the_game.h"

static double	new_ray(double x1, double y1, double x2, double y2)
{
	double	m;
	double 	b;
	double	change;

	m = (y2 - y1) / (x2 - x1);
	b = y1 - (m * x1);
	change = m * 64 + b;
	return (change);
}

// A lot of stuff is going on here, which is read and written from internet sources.
// Will update to more readable after I see the results.
void	RayCast_main(t_GameData *data)
{
	// t_RCUtil	util; // just for norminette
	int			r; // rays
	int			blocks; // maximum blocks count for horizontal or vertical lines
	double		ray_angle; // in radians
	double		ray_y;
	double		ray_x;
	double		a_tan; // arc tanges
	double		offset_y;
	double		offset_x;
	int			m_x = 0; // no idea
	int			m_y = 0; // no idea

	ray_angle = data->player.angle + D_RADIAN * 60;
	if (ray_angle < 0)
		ray_angle += P4;
	if (ray_angle > P4)
		ray_angle -= P4;
	r = 0;
	while (r < 360)
	{
		// Horizontal lines Checking
		blocks = 0;
		a_tan = -1 / tan(ray_angle);
		if (ray_angle > M_PI) // ray is looking up
		{
			ray_y = (((int)data->player.initial_pos.y >> 6) << 6) - 0.0001; // 6 here because my block size is 64 ? Also I think I don't need (int)
			ray_x = (data->player.initial_pos.y - ray_y) * a_tan + data->player.initial_pos.x;
			offset_y = -64;
			offset_x = -offset_y * a_tan;
		}
		if (ray_angle < M_PI) // ray is looking down
		{
			ray_y = (((int)data->player.initial_pos.y >> 6) << 6) + 64; // this is some math...
			ray_x = (data->player.initial_pos.y - ray_y) * a_tan + data->player.initial_pos.x;
			offset_y = 64;
			offset_x = -offset_y * a_tan;
		}
		if (ray_angle == 0 || ray_angle == M_PI) // looking straigth left or straigth right, ther eis no point to check for Horizontal lines
		{
			ray_x = data->player.initial_pos.x;
			ray_y = data->player.initial_pos.y;
		}
		else
		{
			while (blocks < data->minimap.block_count.x)
			{
				m_x = (int) (ray_x) >> 6;
				m_y = (int) (ray_y) >> 6;
				if (m_x < 0 || m_y < 0)
					break ;
				if (m_x < data->minimap.block_count.x && m_y < data->minimap.block_count.y)
				{
					// printf("m_y: %d     m_x: %d\n", m_y, m_x);
					if (data->minimap.map[m_y][m_x] == '1')
						break ;
					else
					{
						ray_x += offset_x;
						ray_y += offset_y;
					}
				}
				++blocks;
			}
		}
		// printf("ray_x: %f     ray_y: %f\n", ray_x, ray_y);
		// printf("p_x: %d     p_y: %d\n", data->player.initial_pos.x, data->player.initial_pos.y);
		t_Line2D	line;
		line.color_end = COLOR_RED;
		line.color_start = COLOR_RED;
		line.start.x = data->player.initial_pos.x;
		line.start.y = data->player.initial_pos.y;
		if (ray_x < 0)
		{
			ray_y = new_ray(data->player.initial_pos.x, data->player.initial_pos.y, ray_x, ray_y);
			ray_x = 64;
		}
		else if (ray_y < 0)
		{
			ray_x = new_ray(data->player.initial_pos.x, data->player.initial_pos.y, ray_x, ray_y);
			ray_y = 64;
		}
		printf("ray_x: %f     ray_y: %f\n", ray_x, ray_y);
		line.end.x = ray_x;
		line.end.y = ray_y;
		// printf("here_line\n");
			draw_line_Bresenham(&data->minimap.image, &line);
		ray_angle += D_RADIAN;
		if (ray_angle < 0)
			ray_angle += P4;
		if (ray_angle > P4)
			ray_angle -= P4;
		++r;
	}
}