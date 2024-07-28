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
	minimap_draw(&data->minimap);
	player_draw(&data->minimap.image, &data->player);
	render_image(data, &data->minimap.image);
}