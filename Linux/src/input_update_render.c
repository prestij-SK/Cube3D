#include "../header/the_game.h"

// When everything is good, we will update this to better version, where everything is faster and smooth
static int	frame(t_GameData *data)
{
	if (!data)
		return (0);
	render_all(data);
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