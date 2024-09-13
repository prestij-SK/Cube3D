#include "../header/the_game.h"

int	close_game(t_gamedata *data)
{
	if (!data)
		return (B_FALSE);
	game_data_delete(data);
	success_exit(SUCCESS_EXIT, "Game Closed.");
	return (B_TRUE);
}

static int	update(t_gamedata *data)
{
	size_t		current_update_time;
	long long	elapsed_time;

	if (!data)
		return (B_FALSE);
	current_update_time = get_time();
	elapsed_time = current_update_time - data->last_update_time;
	if (elapsed_time >= UPDATE_60FPS_INTERVAL)
	{
		if (data->input.esc == B_TRUE)
			close_game(data);
		update_check(data);
		data->last_update_time = current_update_time;
	}
	render(data);
	return (B_TRUE);
}

void	input_update_render(t_gamedata *data)
{
	if (!data)
		return ;
	mlx_hook(data->mlx_window, EVENT_KEYDOWN, 1L<<0, input_key_press, &data->input);
	mlx_hook(data->mlx_window, EVENT_KEYUP, 1L<<1, input_key_release, &data->input);
	mlx_hook(data->mlx_window, EVENT_MOUSEMOVE, 1L<<6, input_mouse_move, &data->input);
	mlx_hook(data->mlx_window, EVENT_DESTROY, 0, close_game, data);
	mlx_mouse_hook(data->mlx_window, input_mouse_button, &data->input);
	mlx_loop_hook(data->mlx, update, data);
	mlx_loop(data->mlx);
}