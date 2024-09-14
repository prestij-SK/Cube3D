/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <yuhayrap@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 14:20:02 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/09/14 14:27:55 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/player.h"

static void	set_player_angle(t_player *player, t_minimap *minimap,
		t_point2d pos)
{
	if (minimap->map[pos.y][pos.x] == 'W')
		player->angle = get_radians(PLAYER_ANGLE_DEFAULT * 2);
	else if (minimap->map[pos.y][pos.x] == 'N')
		player->angle = get_radians(PLAYER_ANGLE_DEFAULT * 3);
	else if (minimap->map[pos.y][pos.x] == 'E')
		player->angle = get_radians(PLAYER_ANGLE_DEFAULT * 4);
	else
		player->angle = get_radians(PLAYER_ANGLE_DEFAULT);
}

t_statuscode	player_init(t_player *player, t_minimap *minimap,
		t_point2d block_pos, int block_size)
{
	t_point2d	pos;

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
	set_player_angle(player, minimap, block_pos);
	player->delta.x = cos(player->angle) * PLAYER_MOVE_SPEED;
	player->delta.y = sin(player->angle) * PLAYER_MOVE_SPEED;
	player->minimap = minimap;
	player->move_speed = PLAYER_MOVE_SPEED;
	player->rotate_speed = PLAYER_ROTATE_SPEED;
	player->mouse_sens = PLAYER_MOUSE_SENSITIVITY;
	return (SUCCESS_EXIT);
}

void	player_on_minimap_draw_origin(t_image *image, t_player *player)
{
	t_point2d	temp_pos;

	if (!image || !player)
		return ;
	temp_pos.x = player->pos.x - player->size.x / 2;
	temp_pos.y = player->pos.y - player->size.y / 2;
	draw_rectangle_filled(image, temp_pos, player->size, player->color);
}

void	player_on_minimap_draw_small(t_image *image, t_player *player)
{
	t_point2d	temp_pos;
	t_point2d	temp_size;

	if (!image || !player)
		return ;
	temp_pos.x = (player->pos.x - player->size.x / 2) / MINIMAP_SIZE_DIVISER;
	temp_pos.y = (player->pos.y - player->size.y / 2) / MINIMAP_SIZE_DIVISER;
	temp_size.x = player->size.x / MINIMAP_SIZE_DIVISER;
	temp_size.y = player->size.y / MINIMAP_SIZE_DIVISER;
	draw_rectangle_filled(image, temp_pos, temp_size, player->color);
}
