/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_norm_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <yuhayrap@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 14:21:13 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/09/14 14:35:44 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/the_game.h"

int	is_in_minimap_range(t_minimap *minimap, int y, int x)
{
	if (!minimap)
		return (B_FALSE);
	if ((y >= 0 && y < minimap->block_count.y) && (x >= 0
			&& x < minimap->block_count.x))
	{
		return (B_TRUE);
	}
	return (B_FALSE);
}

void	set_xy_offset(t_updateutil *util, double change_x, double change_y,
		int gap)
{
	if (!util)
		return ;
	if (change_x < 0)
		util->offset.x = -gap;
	else
		util->offset.x = gap;
	if (change_y < 0)
		util->offset.y = -gap;
	else
		util->offset.y = gap;
}

// rotating left
void	update_arrow_left(t_player *player, double rotate_speed)
{
	if (!player)
		return ;
	player->angle -= rotate_speed;
	if (player->angle < 0)
		player->angle += 2 * M_PI;
	player->delta.x = cos(player->angle) * player->move_speed;
	player->delta.y = sin(player->angle) * player->move_speed;
}

// rotating right
void	update_arrow_right(t_player *player, double rotate_speed)
{
	if (!player)
		return ;
	player->angle += rotate_speed;
	if (player->angle > 2 * M_PI)
		player->angle -= 2 * M_PI;
	player->delta.x = cos(player->angle) * player->move_speed;
	player->delta.y = sin(player->angle) * player->move_speed;
}

// rotating with mouse
void	update_mouse_move(t_gamedata *data, double rotate_speed)
{
	int		pos_diff;
	double	new_speed;

	if (!data)
		return ;
	if (data->input.mouse_prev_pos.x == -1)
	{
		data->input.mouse_prev_pos.x = data->input.mouse_curr_pos.x;
		data->input.mouse_move = B_FALSE;
		return ;
	}
	pos_diff = abs(data->input.mouse_prev_pos.x - data->input.mouse_curr_pos.x);
	new_speed = pos_diff * rotate_speed;
	if (data->input.mouse_prev_pos.x < data->input.mouse_curr_pos.x)
		update_arrow_right(&data->player, new_speed);
	else if (data->input.mouse_prev_pos.x > data->input.mouse_curr_pos.x)
		update_arrow_left(&data->player, new_speed);
	data->input.mouse_prev_pos.x = data->input.mouse_curr_pos.x;
	data->input.mouse_move = B_FALSE;
}
