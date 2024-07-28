#include "../header/the_game.h"

// When everything is good, we will update this to better version, where everything is faster and smooth
static int	frame(t_GameData *data)
{
	if (!data)
		return (0);
	render_all(data);
	// printf("x_angle: %d   %d\n", fdf_data->land_data->setup.angles.x, fdf_data->land_data->z_val_flip);
	// printf("y_angle: %d   %d\n", fdf_data->land_data->setup.angles.y, fdf_data->land_data->z_val_flip);
	return (1);
}

void	input_update_render(t_GameData *data)
{
	if (!data)
		return ;
	mlx_hook(data->mlx_window, EVENT_KEYDOWN, 1L<<0, input_key_press, data);
	// mlx_hook(data->mlx_window, EVENT_KEYUP, 1L<<1, input_key_release, data);
	mlx_hook(data->mlx_window, EVENT_DESTROY, 0, input_close_window, data);
	mlx_loop_hook(data->mlx, frame, data);
	mlx_loop(data->mlx);
}