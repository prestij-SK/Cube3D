#include "../header/player.h"

t_StatusCode	player_init(t_Player *player, void *mlx, t_Point2D block_pos, int block_size)
{
	t_Point2D		pos;

	if (!player)
		return (NULL_POINTER_ERROR);
	if (block_pos.x == -1 || block_pos.y == -1)
		return (PLAYER_LOCATION_ERROR);
	player->name = PLAYER_NAME;
	pos.x = block_pos.x * block_size;
	pos.y = block_pos.y * block_size;
	player->initial_pos.x = (pos.x + (pos.x + block_size)) / 2;
	player->initial_pos.y = (pos.y + (pos.y + block_size)) / 2;
	player->size.x = block_size / 4;
	player->size.y = block_size / 4;
	player->color = COLOR_YELLOW;
	player->angle = get_radians(PLAYER_ANGLE_DEFAULT);
	player->delta.x = cos(player->angle) * PLAYER_MOVE_SPEED_MULTIPLIER;
	player->delta.y = sin(player->angle) * PLAYER_MOVE_SPEED_MULTIPLIER;
	return (SUCCESS_EXIT);
}

void	player_on_minimap_draw(t_Image *image, t_Player *player)
{
	t_Point2D	temp_pos;

	if (!image || !player)
		return ;
	temp_pos.x = player->initial_pos.x - player->size.x / 2;
	temp_pos.y = player->initial_pos.y - player->size.y / 2;
	draw_rectangle_filled(image, temp_pos, player->size, player->color);
}