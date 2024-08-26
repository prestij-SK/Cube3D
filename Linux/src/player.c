#include "../header/player.h"

t_StatusCode	player_init(t_Player *player, t_Minimap *minimap, t_Point2D block_pos, int block_size)
{
	t_Point2D		pos;

	if (!player || !minimap)
		return (NULL_POINTER_ERROR);
	if (block_pos.x < 0 || block_pos.y < 0)
		return (PLAYER_LOCATION_ERROR);
	player->name = PLAYER_NAME;
	pos.x = block_pos.x * block_size;
	pos.y = block_pos.y * block_size;
	player->pos.x = (pos.x + (pos.x + block_size)) / 2;
	player->pos.y = (pos.y + (pos.y + block_size)) / 2;
	player->size.x = block_size / 2;
	player->size.y = block_size / 2;
	player->color = COLOR_YELLOW;
	player->angle = get_radians(PLAYER_ANGLE_DEFAULT);
	player->delta.x = cos(player->angle) * PLAYER_MOVE_SPEED;
	player->delta.y = sin(player->angle) * PLAYER_MOVE_SPEED;
	player->minimap = minimap;
	return (SUCCESS_EXIT);
}

void	player_on_minimap_draw_origin(t_Image *image, t_Player *player)
{
	t_Point2D	temp_pos;

	if (!image || !player)
		return ;
	temp_pos.x = player->pos.x - player->size.x / 2;
	temp_pos.y = player->pos.y - player->size.y / 2;
	draw_rectangle_filled(image, temp_pos, player->size, player->color);
}

void	player_on_minimap_draw_small(t_Image *image, t_Player *player)
{
	t_Point2D	temp_pos;
	t_Point2D	temp_size;

	if (!image || !player)
		return ;
	temp_pos.x = (player->pos.x - player->size.x / 2) / MINIMAP_SIZE_DIVISER;
	temp_pos.y = (player->pos.y - player->size.y / 2) / MINIMAP_SIZE_DIVISER;
	temp_size.x = player->size.x / MINIMAP_SIZE_DIVISER;
	temp_size.y = player->size.y / MINIMAP_SIZE_DIVISER;
	draw_rectangle_filled(image, temp_pos, temp_size, player->color);
}