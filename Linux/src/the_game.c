#include "../header/the_game.h"

t_StatusCode	game_data_init(t_GameData *data)
{
	t_StatusCode	status;

	if (!data)
		return (NULL_POINTER_ERROR);
	data->mlx = mlx_init();
	if (!data->mlx)
		return (MLX_ERROR);
	data->mlx_window = mlx_new_window(data->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, GAME_NAME);
	if (!data->mlx_window)
		return (MLX_WINDOW_ERROR);
	// map init here
	status = minimap_init(&data->minimap, data->mlx, 500, 500); // instead of magic, here must be the size of 'map'
	if (status != SUCCESS_EXIT)
		return (status);
	// calculate player pos
	status = player_init(&data->player, data->mlx, 50, 50); // instead of magic, here must be calculated Player's position in the 'map'
	if (status != SUCCESS_EXIT)
		return (status);
	return (SUCCESS_EXIT);
}