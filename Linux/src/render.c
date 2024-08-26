#include "../header/the_game.h"

void	render_image(t_GameData *data, t_Image *image)
{
	if (!data || !image)
		return ;
	mlx_put_image_to_window(data->mlx, data->mlx_window,
							image->img, image->pos.x, image->pos.y);
}

void	render(t_GameData *data)
{
	if (!data)
		return ;
	fp_view_draw(&data->view);
	if (data->minimap.map_draw_flag == B_TRUE) // Small or Big minimap draw
	{
		minimap_draw_origin(&data->minimap);
		player_on_minimap_draw_origin(&data->minimap.origin_image, &data->player);
	}
	else
	{
		minimap_draw_small(&data->minimap);
		player_on_minimap_draw_small(&data->minimap.small_image, &data->player);
	}
	ray_casting(data);
	render_image(data, &data->view.image);
	if (data->minimap.map_draw_flag == B_TRUE)
		render_image(data, &data->minimap.origin_image);
	else
		render_image(data, &data->minimap.small_image);
}