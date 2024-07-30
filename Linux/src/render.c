#include "../header/the_game.h"

void	render_image(t_GameData *data, t_Image *image)
{
	if (!data || !image)
		return ;
	mlx_put_image_to_window(data->mlx, data->mlx_window,
							image->img, image->pos.x, image->pos.y);
}

void	render_all(t_GameData *data)
{
	if (!data)
		return ;
	fp_view_draw(&data->view);
	render_image(data, &data->view.image);
	minimap_draw(&data->minimap);
	player_draw(&data->minimap.image, &data->player);
	//
	// t_Line2D	line;
	// line.color_end = COLOR_RED;
	// line.color_start = COLOR_RED;
	// line.start.x = 50;
	// line.start.y = 30;
	// line.end.x = 200;
	// line.end.y = 125;
	// draw_line_Bresenham(&data->minimap.image, &line);
	//
	RayCast_main(data);
	render_image(data, &data->minimap.image);
}