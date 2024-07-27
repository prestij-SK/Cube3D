#include "../header/player.h"

t_StatusCode	player_init(t_Player *player, void *mlx, int pos_x, int pos_y)
{
	t_StatusCode	status;

	if (!player)
		return (NULL_POINTER_ERROR);
	player->name = PLAYER_NAME;
	player->size.x = PLAYER_MINIMAP_SIZE_X;
	player->size.y = PLAYER_MINIMAP_SIZE_Y;
	player->pos.x = pos_x;
	player->pos.y = pos_y;
	player->color = COLOR_YELLOW;
	return (SUCCESS_EXIT);
}