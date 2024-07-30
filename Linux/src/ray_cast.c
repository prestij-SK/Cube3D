#include "../header/the_game.h"

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
	int			m_x; // no idea
	int			m_y; // no idea

	ray_angle = data->player.angle;
	r = 0;
	while (r < RAYS_COUNT)
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
					printf("here_map\n");
					printf("m_y: %d     m_x: %d", m_y, m_x);
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
		t_Line2D	line;
		line.color_end = COLOR_RED;
		line.color_start = COLOR_RED;
		line.start.x = data->player.initial_pos.x;
		line.start.y = data->player.initial_pos.y;
		line.end.x = ray_x;
		line.end.y = ray_y;
		printf("here_line\n");
		if (line.end.x > 0 && line.end.y > 0)
			draw_line_Bresenham(&data->minimap.image, &line);
		++r;
	}
}