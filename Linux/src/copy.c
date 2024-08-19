#include "../header/the_game.h"

void	ray_cast_3d_walls_old(t_GameData *data, t_RCdata *ray_data, int ray, double ray_angle)
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
	line_h = (data->view.image.size.y * 32) / ray_data->dis_f;
	if (line_h > data->view.image.size.y)
		line_h = data->view.image.size.y;
	offset = data->view.image.size.y - (line_h / 2);
	pos.x = ray * (data->view.image.size.x / 60);
	pos.y = offset - data->view.image.size.y / 2;
	size.x = data->view.image.size.x / 59;
	size.y = line_h;

	// int x = 0;
	// int y = 0;
	// while (y < size.y)
	// {
	// 	x = 0;
	// 	while (x < size.x)
	// 	{
	// 		alt_mlx_pixel_put(&data->view.image, pos.x + x, pos.y + y, COLOR_RED);
	// 		++x;
	// 	}
	// 	++y;
	// }
	//

	draw_rectangle_filled(&data->view.image, pos, size, COLOR_RED);
}