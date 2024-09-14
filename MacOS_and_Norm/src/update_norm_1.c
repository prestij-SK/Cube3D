/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_norm_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <yuhayrap@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 14:20:56 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/09/14 14:46:56 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/the_game.h"

static void	update_a_norm(t_player *player, t_updateutil *util)
{
	util->current.x = player->pos.x / player->minimap->block_size;
	util->current.y = player->pos.y / player->minimap->block_size;
	util->next.x = (player->pos.x + util->offset.x)
		/ player->minimap->block_size;
	util->next.y = (player->pos.y + util->offset.y)
		/ player->minimap->block_size;
}

// strafing left
void	update_a(t_player *player)
{
	t_updateutil	util;
	double			strafe_angle;
	double			strafe_x;
	double			strafe_y;

	strafe_angle = player->angle - M_PI / 2;
	strafe_x = cos(strafe_angle) * player->move_speed;
	strafe_y = sin(strafe_angle) * player->move_speed;
	set_xy_offset(&util, strafe_x, strafe_y, COLLISION_GAP);
	update_a_norm(player, &util);
	if (is_in_minimap_range(player->minimap, util.current.y, util.next.x))
		if (player->minimap->map[util.current.y][util.next.x] != '1')
			if (player->minimap->map[util.current.y][util.next.x] != ' ')
				if (door_is_closed(player->minimap->doors,
						player->minimap->door_count, util.current.y,
						util.next.x) == B_FALSE)
					player->pos.x += (int)round(strafe_x);
	if (is_in_minimap_range(player->minimap, util.next.y, util.current.x))
		if (player->minimap->map[util.next.y][util.current.x] != '1')
			if (player->minimap->map[util.next.y][util.current.x] != ' ')
				if (door_is_closed(player->minimap->doors,
						player->minimap->door_count, util.next.y,
						util.current.x) == B_FALSE)
					player->pos.y += (int)round(strafe_y);
}

void	update_d_norm(t_player *player, t_updateutil *util)
{
	util->current.x = player->pos.x / player->minimap->block_size;
	util->current.y = player->pos.y / player->minimap->block_size;
	util->next.x = (player->pos.x + util->offset.x)
		/ player->minimap->block_size;
	util->next.y = (player->pos.y + util->offset.y)
		/ player->minimap->block_size;
}

// strafing right
void	update_d(t_player *player)
{
	t_updateutil	util;
	double			strafe_angle;
	double			strafe_x;
	double			strafe_y;

	strafe_angle = player->angle + M_PI / 2;
	strafe_x = cos(strafe_angle) * player->move_speed;
	strafe_y = sin(strafe_angle) * player->move_speed;
	set_xy_offset(&util, strafe_x, strafe_y, COLLISION_GAP);
	update_d_norm(player, &util);
	if (is_in_minimap_range(player->minimap, util.current.y, util.next.x))
		if (player->minimap->map[util.current.y][util.next.x] != '1')
			if (player->minimap->map[util.current.y][util.next.x] != ' ')
				if (door_is_closed(player->minimap->doors,
						player->minimap->door_count, util.current.y,
						util.next.x) == B_FALSE)
					player->pos.x += (int)round(strafe_x);
	if (is_in_minimap_range(player->minimap, util.next.y, util.current.x))
		if (player->minimap->map[util.next.y][util.current.x] != '1')
			if (player->minimap->map[util.next.y][util.current.x] != ' ')
				if (door_is_closed(player->minimap->doors,
						player->minimap->door_count, util.next.y,
						util.current.x) == B_FALSE)
					player->pos.y += (int)round(strafe_y);
}

// show big map
void	update_m(t_minimap *minimap, short val)
{
	if (!minimap)
		return ;
	minimap->map_draw_flag = val;
}
