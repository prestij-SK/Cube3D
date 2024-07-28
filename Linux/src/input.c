#include "../header/the_game.h"

static void	render_image(t_GameData *data, t_Image *image)
{
	if (!data || !image)
		return ;
	mlx_put_image_to_window(data->mlx, data->mlx_window,
							image->img, image->pos.x, image->pos.y);
}

int	input_key_press(int key, t_GameData *data)
{
	printf("%d: \n", key);
	if (!data)
		return (0);
	if (key == KEY_A)
		data->player.pos.x -= 5;
	else if (key == KEY_D)
		data->player.pos.x += 5;
	else if (key == KEY_W)
		data->player.pos.y -= 5;
	else if (key == KEY_S)
		data->player.pos.y += 5;
	minimap_draw(&data->minimap);
	player_draw(&data->minimap.image, &data->player);
	render_image(data, &data->minimap.image);
	// if (key == KEY_ESC)
	// 	update_end_program(fdf_data);
	// else if (key == KEY_LEFT_ARROW)
	// 	update_left_arrow_key(fdf_data);
	// else if (key == KEY_RIGHT_ARROW)
	// 	update_right_arrow_key(fdf_data);
	// else if (key == KEY_UP_ARROW)
	// 	update_up_arrow_key(fdf_data);
	// else if (key == KEY_DOWN_ARROW)
	// 	update_down_arrow_key(fdf_data);
	// else if (key == KEY_X)
	// 	update_X_key(fdf_data);
	// else if (key == KEY_C)
	// 	update_C_key(fdf_data);
	// else if (key == KEY_Z)
	// 	update_Z_key(fdf_data);
	// else if (key == KEY_A)
	// 	update_A_key(fdf_data);
	// else if (key == KEY_S)
	// 	update_S_key(fdf_data);
	// else if (key == KEY_D)
	// 	update_D_key(fdf_data);
	return (1);
}