#include "../header/the_game.h"

// strafing left
void	update_A_key(t_Player *player)
{
    // Calculate the strafe vector (perpendicular to the delta vector)
    double strafe_angle = player->angle - M_PI / 2;  // 90 degrees rotation
	// Calculate delta X,Y again
    double strafe_x = cos(strafe_angle) * PLAYER_MOVE_SPEED_MULTIPLIER;
    double strafe_y = sin(strafe_angle) * PLAYER_MOVE_SPEED_MULTIPLIER;

    player->initial_pos.x += (int)round(strafe_x);
    player->initial_pos.y += (int)round(strafe_y);
}

// strafing right
void	update_D_key(t_Player *player)
{
    // Same thing, but we add 90 degree
    double strafe_angle = player->angle + M_PI / 2;
    double strafe_x = cos(strafe_angle) * PLAYER_MOVE_SPEED_MULTIPLIER;
    double strafe_y = sin(strafe_angle) * PLAYER_MOVE_SPEED_MULTIPLIER;

    player->initial_pos.x += (int)round(strafe_x);
    player->initial_pos.y += (int)round(strafe_y);
}

// going forward
void	update_W_key(t_Player *player)
{
	player->initial_pos.x += (int)round(player->delta.x);
	player->initial_pos.y += (int)round(player->delta.y);
}

// going back
void	update_S_key(t_Player *player)
{
	player->initial_pos.x -= (int)round(player->delta.x);
	player->initial_pos.y -= (int)round(player->delta.y);
}

// rotating left
void	update_Left_key(t_Player *player)
{
	player->angle -= PLAYER_ROTATE_SPEED;
	if (player->angle < 0) // full rotation is done, must bring it back to start (which is already at the start kinda)
		player->angle += 2 * M_PI; // I can't just set angle to '0', it won't be smooth and maybe not correct
	// Here we calculate the direction, so we know on which direction player is watching.
	// Delta X and Y will be updated and will added to initial position of player.
	// It will change depending on what angle we are currently in.
	player->delta.x = cos(player->angle) * PLAYER_MOVE_SPEED_MULTIPLIER;
	player->delta.y = sin(player->angle) * PLAYER_MOVE_SPEED_MULTIPLIER;
}

// rotating right
void	update_Right_key(t_Player *player)
{
	// same logic here but we add angle here
	player->angle += PLAYER_ROTATE_SPEED;
	if (player->angle > 2 * M_PI)
		player->angle -= 2 * M_PI;
	player->delta.x = cos(player->angle) * PLAYER_MOVE_SPEED_MULTIPLIER;
	player->delta.y = sin(player->angle) * PLAYER_MOVE_SPEED_MULTIPLIER;
}