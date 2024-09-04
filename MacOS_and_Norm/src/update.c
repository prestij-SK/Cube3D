#include "../header/the_game.h"

static int	is_in_minimap_range(t_Minimap *minimap, int y, int x)
{
	if (!minimap)
		return (B_FALSE);
	if ((y >= 0 && y < minimap->block_count.y) &&
		(x >= 0 && x < minimap->block_count.x))
	{
		return (B_TRUE);
	}
	return (B_FALSE);
}

static void	set_xy_offset(t_UpdateUtil *util, double change_x, double change_y, int gap)
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

// strafing left
void	update_A(t_Player *player)
{
	if (!player)
		return ;
	t_UpdateUtil	util;

    // Calculate the strafe vector (perpendicular to the delta vector)
    double strafe_angle = player->angle - M_PI / 2;  // 90 degrees rotation
	// Calculate delta X,Y again
    double strafe_x = cos(strafe_angle) * player->move_speed;
    double strafe_y = sin(strafe_angle) * player->move_speed;

    set_xy_offset(&util, strafe_x, strafe_y, COLLISION_GAP);
	util.current.x = player->pos.x / player->minimap->block_size;
	util.current.y = player->pos.y / player->minimap->block_size;
	util.next.x = (player->pos.x + util.offset.x) / player->minimap->block_size;
	util.next.y = (player->pos.y + util.offset.y) / player->minimap->block_size;
	if (is_in_minimap_range(player->minimap, util.current.y, util.next.x))
		if (player->minimap->map[util.current.y][util.next.x] != '1')
			if (door_is_closed(player->minimap->doors, player->minimap->door_count, util.current.y, util.next.x) == B_FALSE)
				player->pos.x += (int)round(strafe_x);
	if (is_in_minimap_range(player->minimap, util.next.y, util.current.x ))
		if (player->minimap->map[util.next.y][util.current.x] != '1')
			if (door_is_closed(player->minimap->doors, player->minimap->door_count, util.next.y, util.current.x) == B_FALSE)
				player->pos.y += (int)round(strafe_y);
}

// strafing right
void	update_D(t_Player *player)
{
	if (!player)
		return ;
	t_UpdateUtil	util;

    // Same thing, but we add 90 degree
    double strafe_angle = player->angle + M_PI / 2;
	// Calculate delta X,Y again
    double strafe_x = cos(strafe_angle) * player->move_speed;
    double strafe_y = sin(strafe_angle) * player->move_speed;

	set_xy_offset(&util, strafe_x, strafe_y, COLLISION_GAP);
	util.current.x = player->pos.x / player->minimap->block_size;
	util.current.y = player->pos.y / player->minimap->block_size;
	util.next.x = (player->pos.x + util.offset.x) / player->minimap->block_size;
	util.next.y = (player->pos.y + util.offset.y) / player->minimap->block_size;
	if (is_in_minimap_range(player->minimap, util.current.y, util.next.x))
		if (player->minimap->map[util.current.y][util.next.x] != '1')
			if (door_is_closed(player->minimap->doors, player->minimap->door_count, util.current.y, util.next.x) == B_FALSE)
				player->pos.x += (int)round(strafe_x);
	if (is_in_minimap_range(player->minimap, util.next.y, util.current.x ))
		if (player->minimap->map[util.next.y][util.current.x] != '1')
			if (door_is_closed(player->minimap->doors, player->minimap->door_count, util.next.y, util.current.x) == B_FALSE)
				player->pos.y += (int)round(strafe_y);
}

// going forward
void	update_W(t_Player *player)
{
	if (!player)
		return ;
	t_UpdateUtil	util;

	set_xy_offset(&util, player->delta.x, player->delta.y, COLLISION_GAP);
	util.current.x = player->pos.x / player->minimap->block_size;
	util.current.y = player->pos.y / player->minimap->block_size;
	util.next.x = (player->pos.x + util.offset.x) / player->minimap->block_size;
	util.next.y = (player->pos.y + util.offset.y) / player->minimap->block_size;
	if (is_in_minimap_range(player->minimap, util.current.y, util.next.x))
		if (player->minimap->map[util.current.y][util.next.x] != '1')
			if (door_is_closed(player->minimap->doors, player->minimap->door_count, util.current.y, util.next.x) == B_FALSE)
				player->pos.x += (int)round(player->delta.x);
	if (is_in_minimap_range(player->minimap, util.next.y, util.current.x ))
		if (player->minimap->map[util.next.y][util.current.x] != '1')
			if (door_is_closed(player->minimap->doors, player->minimap->door_count, util.next.y, util.current.x) == B_FALSE)
				player->pos.y += (int)round(player->delta.y);
}

// going back
void	update_S(t_Player *player)
{
	if (!player)
		return ;
	t_UpdateUtil	util;

	set_xy_offset(&util, player->delta.x, player->delta.y, COLLISION_GAP);
	util.current.x = player->pos.x / player->minimap->block_size;
	util.current.y = player->pos.y / player->minimap->block_size;
	util.next.x = (player->pos.x - util.offset.x) / player->minimap->block_size;
	util.next.y = (player->pos.y - util.offset.y) / player->minimap->block_size;
	if (is_in_minimap_range(player->minimap, util.current.y, util.next.x))
		if (player->minimap->map[util.current.y][util.next.x] != '1')
			if (door_is_closed(player->minimap->doors, player->minimap->door_count, util.current.y, util.next.x) == B_FALSE)
				player->pos.x -= (int)round(player->delta.x);
	if (is_in_minimap_range(player->minimap, util.next.y, util.current.x ))
		if (player->minimap->map[util.next.y][util.current.x] != '1')
			if (door_is_closed(player->minimap->doors, player->minimap->door_count, util.next.y, util.current.x) == B_FALSE)
				player->pos.y -= (int)round(player->delta.y);
}

// show big map
void	update_M(t_Minimap *minimap, short val)
{
	if (!minimap)
		return ;
	minimap->map_draw_flag = val;
}

// Do action
void	update_E(t_GameData *data, t_Player *player)
{
	if (!player)
		return ;
	t_UpdateUtil	util;

	if (data->input.e_checked == B_TRUE)
		return ;
	// printf("here\n");
	set_xy_offset(&util, player->delta.x, player->delta.y, DOOR_ACTIVATION_GAP);
	util.current.x = player->pos.x / player->minimap->block_size;
	util.current.y = player->pos.y / player->minimap->block_size;
	util.next.x = (player->pos.x + util.offset.x) / player->minimap->block_size;
	util.next.y = (player->pos.y + util.offset.y) / player->minimap->block_size;
	if (is_in_minimap_range(player->minimap, util.current.y, util.next.x))
		if (player->minimap->map[util.current.y][util.next.x] == 'D')
		{
			if (door_is_closed(player->minimap->doors, player->minimap->door_count, util.current.y, util.next.x) == B_TRUE)
				door_open(player->minimap->doors, player->minimap->door_count, util.current.y, util.next.x);
			else
				door_close(player->minimap->doors, player->minimap->door_count, util.current.y, util.next.x);
			return ;
		}
	if (is_in_minimap_range(player->minimap, util.next.y, util.current.x ))
	{
		if (player->minimap->map[util.next.y][util.current.x] == 'D')
		{
			if (door_is_closed(player->minimap->doors, player->minimap->door_count, util.next.y, util.current.x) == B_TRUE)
			{
				if (door_is_closed(player->minimap->doors, player->minimap->door_count, util.current.y, util.next.x) == B_TRUE)
					door_open(player->minimap->doors, player->minimap->door_count, util.current.y, util.next.x);
			}
			else
			{
				door_close(player->minimap->doors, player->minimap->door_count, util.current.y, util.next.x);
			}
		}
	}
}

// rotating left
void	update_Arrow_Left(t_Player *player, double rotate_speed)
{
	if (!player)
		return ;
	player->angle -= rotate_speed;
	if (player->angle < 0) // full rotation is done, must bring it back to start (which is already at the start kinda)
		player->angle += 2 * M_PI; // I can't just set angle to '0', it won't be smooth and maybe not correct
	// Here we calculate the direction, so we know on which direction player is watching.
	// Delta X and Y will be updated and will added to initial position of player.
	// It will change depending on what angle we are currently in.
	player->delta.x = cos(player->angle) * player->move_speed;
	player->delta.y = sin(player->angle) * player->move_speed;
}

// rotating right
void	update_Arrow_Right(t_Player *player, double rotate_speed)
{
	if (!player)
		return ;
	// same logic here but we add angle here
	player->angle += rotate_speed;
	if (player->angle > 2 * M_PI)
		player->angle -= 2 * M_PI;
	player->delta.x = cos(player->angle) * player->move_speed;
	player->delta.y = sin(player->angle) * player->move_speed;
}

// rotating with mouse
void	update_mouse_move(t_GameData *data, double rotate_speed)
{
	int		pos_diff; // difference between previous and current mouse positon
	double	new_speed;

	// In this function, 'y' is ignored as our game rotates only left or right, but we might add something for 'y' in future
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
		update_Arrow_Right(&data->player, new_speed);
	else if (data->input.mouse_prev_pos.x > data->input.mouse_curr_pos.x)
		update_Arrow_Left(&data->player, new_speed);
	data->input.mouse_prev_pos.x = data->input.mouse_curr_pos.x;
	data->input.mouse_move = B_FALSE;
}

void	update_mouse_left_click(t_GameData *data)
{
	if (!data)
		return ;
	if (data->anim_start == B_TRUE)
		return ;
	data->anim_start = B_TRUE;
	data->anim_start_time = get_time();
}

void	update_check(t_GameData *data)
{
	if (!data)
		return ;
	if (data->input.w == B_TRUE)
		update_W(&data->player);
	if (data->input.s == B_TRUE)
		update_S(&data->player);
	if (data->input.a == B_TRUE)
		update_A(&data->player);
	if (data->input.d == B_TRUE)
		update_D(&data->player);
	if (data->input.m == B_TRUE)
		update_M(&data->minimap, B_TRUE);
	else
		update_M(&data->minimap, B_FALSE);
	if (data->input.e == B_TRUE)
	{
		update_E(data, &data->player);
		data->input.e_checked = B_TRUE;
	}
	if (data->input.mouse_move == B_TRUE)
		update_mouse_move(data, data->player.mouse_sens);
	if (data->input.arrow_left == B_TRUE)
		update_Arrow_Left(&data->player, data->player.rotate_speed);
	if (data->input.arrow_right == B_TRUE)
		update_Arrow_Right(&data->player, data->player.rotate_speed);
	if (data->input.mouse_left == B_TRUE)
		update_mouse_left_click(data);
}