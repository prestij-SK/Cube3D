#include "../header/the_game.h"

// strafing left
void	update_A(t_Player *player)
{
	t_UpdateUtil	util;

	if (!player)
		return ;
    double strafe_angle = player->angle - M_PI / 2;
    double strafe_x = cos(strafe_angle) * player->move_speed;
    double strafe_y = sin(strafe_angle) * player->move_speed;

    set_xy_offset(&util, strafe_x, strafe_y, COLLISION_GAP);
	util.current.x = player->pos.x / player->minimap->block_size;
	util.current.y = player->pos.y / player->minimap->block_size;
	util.next.x = (player->pos.x + util.offset.x) / player->minimap->block_size;
	util.next.y = (player->pos.y + util.offset.y) / player->minimap->block_size;
	if (is_in_minimap_range(player->minimap, util.current.y, util.next.x))
		if (player->minimap->map[util.current.y][util.next.x] != '1')
			if (player->minimap->map[util.current.y][util.next.x] != ' ')
				if (door_is_closed(player->minimap->doors, player->minimap->door_count, util.current.y, util.next.x) == B_FALSE)
					player->pos.x += (int)round(strafe_x);
	if (is_in_minimap_range(player->minimap, util.next.y, util.current.x ))
		if (player->minimap->map[util.next.y][util.current.x] != '1')
			if (player->minimap->map[util.next.y][util.current.x] != ' ')
				if (door_is_closed(player->minimap->doors, player->minimap->door_count, util.next.y, util.current.x) == B_FALSE)
					player->pos.y += (int)round(strafe_y);
}

// strafing right
void	update_D(t_Player *player)
{
	t_UpdateUtil	util;

	if (!player)
		return ;
    double strafe_angle = player->angle + M_PI / 2;
    double strafe_x = cos(strafe_angle) * player->move_speed;
    double strafe_y = sin(strafe_angle) * player->move_speed;
	set_xy_offset(&util, strafe_x, strafe_y, COLLISION_GAP);
	util.current.x = player->pos.x / player->minimap->block_size;
	util.current.y = player->pos.y / player->minimap->block_size;
	util.next.x = (player->pos.x + util.offset.x) / player->minimap->block_size;
	util.next.y = (player->pos.y + util.offset.y) / player->minimap->block_size;
	if (is_in_minimap_range(player->minimap, util.current.y, util.next.x))
		if (player->minimap->map[util.current.y][util.next.x] != '1')
			if (player->minimap->map[util.current.y][util.next.x] != ' ')
				if (door_is_closed(player->minimap->doors, player->minimap->door_count,
								   util.current.y, util.next.x) == B_FALSE)
					player->pos.x += (int)round(strafe_x);
	if (is_in_minimap_range(player->minimap, util.next.y, util.current.x ))
		if (player->minimap->map[util.next.y][util.current.x] != '1')
			if (player->minimap->map[util.next.y][util.current.x] != ' ')
				if (door_is_closed(player->minimap->doors, player->minimap->door_count,
								   util.next.y, util.current.x) == B_FALSE)
					player->pos.y += (int)round(strafe_y);
}

// going forward
void	update_W(t_Player *player)
{
	t_UpdateUtil	util;

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
				if (door_is_closed(player->minimap->doors, player->minimap->door_count,
								   util.current.y, util.next.x) == B_FALSE)
					player->pos.x += (int)round(player->delta.x);
	if (is_in_minimap_range(player->minimap, util.next.y, util.current.x ))
		if (player->minimap->map[util.next.y][util.current.x] != '1')
			if (player->minimap->map[util.next.y][util.current.x] != ' ')
				if (door_is_closed(player->minimap->doors, player->minimap->door_count,
								   util.next.y, util.current.x) == B_FALSE)
					player->pos.y += (int)round(player->delta.y);
}

// going back
void	update_S(t_Player *player)
{
	t_UpdateUtil	util;

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
				if (door_is_closed(player->minimap->doors, player->minimap->door_count,
								   util.current.y, util.next.x) == B_FALSE)
					player->pos.x -= (int)round(player->delta.x);
	if (is_in_minimap_range(player->minimap, util.next.y, util.current.x ))
		if (player->minimap->map[util.next.y][util.current.x] != '1')
			if (player->minimap->map[util.next.y][util.current.x] != ' ')
				if (door_is_closed(player->minimap->doors, player->minimap->door_count,
								   util.next.y, util.current.x) == B_FALSE)
					player->pos.y -= (int)round(player->delta.y);
}

// show big map
void	update_M(t_Minimap *minimap, short val)
{
	if (!minimap)
		return ;
	minimap->map_draw_flag = val;
}