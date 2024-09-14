/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <yuhayrap@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 14:21:19 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/09/14 14:38:50 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/the_game.h"

static void	update_e_norm(t_gamedata *data, t_player *player,
		t_updateutil *util)
{
	if (is_in_minimap_range(player->minimap, util->next.y, util->current.x))
	{
		if (player->minimap->map[util->next.y][util->current.x] == 'D')
		{
			if (door_is_closed(player->minimap->doors,
					player->minimap->door_count, util->next.y,
					util->current.x) == B_TRUE)
				door_open(player->minimap->doors, player->minimap->door_count,
					util->next.y, util->current.x);
			else
				door_close(player->minimap->doors, player->minimap->door_count,
					util->next.y, util->current.x);
			return ;
		}
	}
}

// Do action
void	update_e(t_gamedata *data, t_player *player)
{
	t_updateutil	util;

	if (data->input.e_checked == B_TRUE)
		return ;
	set_xy_offset(&util, player->delta.x, player->delta.y, DOOR_ACTIVATION_GAP);
	util.current.x = player->pos.x / player->minimap->block_size;
	util.current.y = player->pos.y / player->minimap->block_size;
	util.next.x = (player->pos.x + util.offset.x) / player->minimap->block_size;
	util.next.y = (player->pos.y + util.offset.y) / player->minimap->block_size;
	if (is_in_minimap_range(player->minimap, util.current.y, util.next.x))
	{
		if (player->minimap->map[util.current.y][util.next.x] == 'D')
		{
			if (door_is_closed(player->minimap->doors,
					player->minimap->door_count, util.current.y,
					util.next.x) == B_TRUE)
				door_open(player->minimap->doors, player->minimap->door_count,
					util.current.y, util.next.x);
			else
				door_close(player->minimap->doors, player->minimap->door_count,
					util.current.y, util.next.x);
			return ;
		}
	}
	update_e_norm(data, player, &util);
}

void	update_mouse_left_click(t_gamedata *data)
{
	if (!data)
		return ;
	if (data->anim_start == B_TRUE)
		return ;
	data->anim_start = B_TRUE;
	data->anim_start_time = get_time();
}

static void	update_check_norm(t_gamedata *data)
{
	if (data->input.mouse_move == B_TRUE)
		update_mouse_move(data, data->player.mouse_sens);
	if (data->input.arrow_left == B_TRUE)
		update_arrow_left(&data->player, data->player.rotate_speed);
	if (data->input.arrow_right == B_TRUE)
		update_arrow_right(&data->player, data->player.rotate_speed);
	if (data->input.mouse_left == B_TRUE)
		update_mouse_left_click(data);
}

void	update_check(t_gamedata *data)
{
	if (!data)
		return ;
	if (data->input.w == B_TRUE)
		update_w(&data->player);
	if (data->input.s == B_TRUE)
		update_s(&data->player);
	if (data->input.a == B_TRUE)
		update_a(&data->player);
	if (data->input.d == B_TRUE)
		update_d(&data->player);
	if (data->input.m == B_TRUE)
		update_m(&data->minimap, B_TRUE);
	else
		update_m(&data->minimap, B_FALSE);
	if (data->input.e == B_TRUE)
	{
		update_e(data, &data->player);
		data->input.e_checked = B_TRUE;
	}
	update_check_norm(data);
}
