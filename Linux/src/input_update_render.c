#include "../header/the_game.h"

void	input_update_render(t_GameData *data)
{
	if (!data)
		return ;
	mlx_hook(data->mlx_window, EVENT_KEYDOWN, 1L<<0, input_key_press, data);
}