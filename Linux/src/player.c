#include "../header/player.h"

t_StatusCode	player_init(t_Player *player, void *mlx, t_Point2D block_pos, int block_size)
{
	t_StatusCode	status;
	t_Point2D		pos;

	if (!player)
		return (NULL_POINTER_ERROR);
	if (pos.x == -1 || pos.y == -1)
		return (PLAYER_LOCATION_ERROR);
	player->name = PLAYER_NAME;
	pos.x = block_pos.x * block_size;
	pos.y = block_pos.y * block_size;
	player->pos.x = (pos.x + (pos.x + block_size)) / 2 - block_size / 8;
	player->pos.y = (pos.y + (pos.y + block_size)) / 2 - block_size / 8;
	player->size.x = block_size / 4;
	player->size.y = block_size / 4;
	player->color = COLOR_YELLOW;
	return (SUCCESS_EXIT);
}

void	player_draw(t_Image *image, t_Player *player)
{
	if (!image || !player)
		return ;
	draw_rectangle_filled(image, player->pos, player->size, player->color);
}