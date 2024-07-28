#include "../header/the_game.h"

int	input_close_window(t_GameData *data)
{
	if (!data)
		return (0);
	game_data_delete(data);
	return (1);
}

int	input_key_press(int key, t_GameData *data)
{
	// printf("%d: \n", key);
	if (!data)
		return (0);
	if (key == KEY_ESC)
		game_data_delete(data);
	else if (key == KEY_A)
		update_A_key(&data->player);
	else if (key == KEY_D)
		update_D_key(&data->player);
	else if (key == KEY_W)
		update_W_key(&data->player);
	else if (key == KEY_S)
		update_S_key(&data->player);
	else if (key == KEY_LEFT)
		update_Left_key(&data->player);
	else if (key == KEY_RIGHT)
		update_Right_key(&data->player);
	return (1);
}