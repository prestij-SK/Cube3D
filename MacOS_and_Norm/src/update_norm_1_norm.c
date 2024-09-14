/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_norm_1_norm.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <yuhayrap@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 14:47:10 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/09/14 14:47:13 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/the_game.h"

// going forward
void	update_w(t_player *player)
{
	t_updateutil	util;

	if (!player)
		return ;
	set_xy_offset(&util, player->delta.x, player->delta.y, COLLISION_GAP);
	util.current.x = player->pos.x / player->minimap->block_size;
	util.current.y = player->pos.y / player->minimap->block_size;
	util.next.x = (player->pos.x + util.offset.x) / player->minimap->block_size;
	util.next.y = (player->pos.y + util.offset.y) / player->minimap->block_size;
	if (is_in_minimap_range(player->minimap, util.current.y, util.next.x))
		if (player->minimap->map[util.current.y][util.next.x] != '1')
			if (player->minimap->map[util.current.y][util.next.x] != ' ')
				if (door_is_closed(player->minimap->doors,
						player->minimap->door_count, util.current.y,
						util.next.x) == B_FALSE)
					player->pos.x += (int)round(player->delta.x);
	if (is_in_minimap_range(player->minimap, util.next.y, util.current.x))
		if (player->minimap->map[util.next.y][util.current.x] != '1')
			if (player->minimap->map[util.next.y][util.current.x] != ' ')
				if (door_is_closed(player->minimap->doors,
						player->minimap->door_count, util.next.y,
						util.current.x) == B_FALSE)
					player->pos.y += (int)round(player->delta.y);
}

// going back
void	update_s(t_player *player)
{
	t_updateutil	util;

	if (!player)
		return ;
	set_xy_offset(&util, player->delta.x, player->delta.y, COLLISION_GAP);
	util.current.x = player->pos.x / player->minimap->block_size;
	util.current.y = player->pos.y / player->minimap->block_size;
	util.next.x = (player->pos.x - util.offset.x) / player->minimap->block_size;
	util.next.y = (player->pos.y - util.offset.y) / player->minimap->block_size;
	if (is_in_minimap_range(player->minimap, util.current.y, util.next.x))
		if (player->minimap->map[util.current.y][util.next.x] != '1')
			if (player->minimap->map[util.current.y][util.next.x] != ' ')
				if (door_is_closed(player->minimap->doors,
						player->minimap->door_count, util.current.y,
						util.next.x) == B_FALSE)
					player->pos.x -= (int)round(player->delta.x);
	if (is_in_minimap_range(player->minimap, util.next.y, util.current.x))
		if (player->minimap->map[util.next.y][util.current.x] != '1')
			if (player->minimap->map[util.next.y][util.current.x] != ' ')
				if (door_is_closed(player->minimap->doors,
						player->minimap->door_count, util.next.y,
						util.current.x) == B_FALSE)
					player->pos.y -= (int)round(player->delta.y);
}
