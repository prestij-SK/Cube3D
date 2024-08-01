#include "../header/the_game.h"

# define P2 M_PI / 2
# define P3 3*M_PI / 2
# define DR 0.0174533

static void	horizontal_line(t_RCUtil *util)
{

}

// A lot of stuff is going on here, which is read and written from internet sources.
// Will update to more readable after I see the results.
void	RayCast_main(t_GameData *data)
{
	t_Point2D_d	h_ray;
	t_Point2D_d	v_ray;
	double		dis_h;
	double		dis_v;

	t_RCUtil	util; // just for norminette
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

	t_Line2D	line;
	double		dis_h = 1000000000;
	double		h_x = data->player.initial_pos.x;
	double		h_y = data->player.initial_pos.y;

	double		dis_v = 1000000000;
	double		v_x = data->player.initial_pos.x;
	double		v_y = data->player.initial_pos.y;

	double		dis_f;
	ray_angle = data->player.angle;
	// ray_angle = data->player.angle - DR * 30;
	// if (ray_angle < 0)
	// 	ray_angle += 2 * M_PI;
	// if (ray_angle > 2 * M_PI)
	// 	ray_angle -= 2 * M_PI;
	r = 0;
	while (r < 1)
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
					if (data->minimap.map[m_y][m_x] == '1')
					{
						h_x = ray_x;
						h_y = ray_y;
						dis_h = distance(data->player.initial_pos.x, data->player.initial_pos.y, h_x, h_y);
						break ;
					}
					else
					{
						ray_x += offset_x;
						ray_y += offset_y;
					}
				}
				++blocks;
			}
		}
		// line.color_end = COLOR_RED;
		// line.color_start = COLOR_RED;
		// line.start.x = data->player.initial_pos.x;
		// line.start.y = data->player.initial_pos.y;
		// line.end.x = ray_x;
		// line.end.y = ray_y;
		// if (line.end.x > 0 && line.end.y > 0)
		// 	draw_line_Bresenham(&data->minimap.image, &line);


		////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		// Vertical lines Checking
		blocks = 0;
		a_tan = -tan(ray_angle);
		if (ray_angle > P2 && ray_angle < P3) // ray is looking left
		{
			ray_x = (((int)data->player.initial_pos.x >> 6) << 6) - 0.0001; // 6 here because my block size is 64 ? Also I think I don't need (int)
			ray_y = (data->player.initial_pos.x - ray_x) * a_tan + data->player.initial_pos.y;
			offset_x = -64;
			offset_y = -offset_x * a_tan;
		}
		if (ray_angle < P2 || ray_angle > P3) // ray is looking right
		{
			ray_x = (((int)data->player.initial_pos.x >> 6) << 6) + 64; // this is some math...
			ray_y = (data->player.initial_pos.x - ray_x) * a_tan + data->player.initial_pos.y;
			offset_x = 64;
			offset_y = -offset_x * a_tan;
		}
		if (ray_angle == 0 || ray_angle == M_PI) // looking straigth up or straigth down, ther eis no point to check for Horizontal lines
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
					if (data->minimap.map[m_y][m_x] == '1')
					{
						v_x = ray_x;
						v_y = ray_y;
						dis_v = distance(data->player.initial_pos.x, data->player.initial_pos.y, v_x, v_y);
						break ;
					}
					else
					{
						ray_x += offset_x;
						ray_y += offset_y;
					}
				}
				++blocks;
			}
		}
		if (dis_v < dis_h)
		{
			dis_f = dis_v;
			ray_x = v_x;
			ray_y = v_y;
		}
		if (dis_h < dis_v)
		{
			dis_f = dis_h;
			ray_x = h_x;
			ray_y = h_y;
		}
		line.color_end = COLOR_YELLOW;
		line.color_start = COLOR_YELLOW;
		line.start.x = data->player.initial_pos.x;
		line.start.y = data->player.initial_pos.y;
		line.end.x = ray_x;
		line.end.y = ray_y;
		if (line.end.x > 0 && line.end.y > 0)
			draw_line_Bresenham(&data->minimap.image, &line);

		// Wall
		double		line_h = (MINIMAP_BLOCK_SIZE * FPV_HEIGHT) / dis_f;
		if (line_h > FPV_HEIGHT)
			line_h = FPV_HEIGHT;
		t_Point2D	pos;
		t_Point2D	size;
		pos.x = r * 8;
		pos.y =  FPV_WIDTH / 4;
		size.x = r * 8;
		size.y = (int) round(line_h);
		// draw_rectangle_filled(&data->view.image, pos, size, COLOR_RED);

		////////////////////////////////
		ray_angle += DR;
		if (ray_angle < 0)
			ray_angle += 2 * M_PI;
		if (ray_angle > 2 * M_PI)
			ray_angle -= 2 * M_PI;
		++r;
	}
}