/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <yuhayrap@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 14:19:20 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/09/14 14:24:59 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/input.h"

void	input_reset_all(t_input *input)
{
	if (!input)
		return ;
	input->w = B_FALSE;
	input->s = B_FALSE;
	input->a = B_FALSE;
	input->d = B_FALSE;
	input->m = B_FALSE;
	input->e = B_FALSE;
	input->e_checked = B_FALSE;
	input->esc = B_FALSE;
	input->arrow_left = B_FALSE;
	input->arrow_right = B_FALSE;
	input->mouse_prev_pos.x = -1;
	input->mouse_prev_pos.y = -1;
	input->mouse_move = B_FALSE;
	input->mouse_curr_pos.x = WINDOW_WIDTH / 2;
	input->mouse_curr_pos.y = WINDOW_HEIGHT / 2;
	input->mouse_left = B_FALSE;
}

int	input_key_press(int key, t_input *input)
{
	if (!input)
		return (B_FALSE);
	if (key == KEY_W)
		input->w = B_TRUE;
	else if (key == KEY_S)
		input->s = B_TRUE;
	else if (key == KEY_A)
		input->a = B_TRUE;
	else if (key == KEY_D)
		input->d = B_TRUE;
	else if (key == KEY_M)
		input->m = B_TRUE;
	else if (key == KEY_E)
		input->e = B_TRUE;
	else if (key == KEY_ESC)
		input->esc = B_TRUE;
	else if (key == KEY_ARROR_LEFT)
		input->arrow_left = B_TRUE;
	else if (key == KEY_ARROR_RIGHT)
		input->arrow_right = B_TRUE;
	return (B_TRUE);
}

int	input_key_release(int key, t_input *input)
{
	if (!input)
		return (B_FALSE);
	if (key == KEY_W)
		input->w = B_FALSE;
	else if (key == KEY_S)
		input->s = B_FALSE;
	else if (key == KEY_A)
		input->a = B_FALSE;
	else if (key == KEY_D)
		input->d = B_FALSE;
	else if (key == KEY_M)
		input->m = B_FALSE;
	else if (key == KEY_E)
	{
		input->e = B_FALSE;
		input->e_checked = B_FALSE;
	}
	else if (key == KEY_ESC)
		input->esc = B_FALSE;
	else if (key == KEY_ARROR_LEFT)
		input->arrow_left = B_FALSE;
	else if (key == KEY_ARROR_RIGHT)
		input->arrow_right = B_FALSE;
	return (B_TRUE);
}

int	input_mouse_move(int x, int y, t_input *input)
{
	if (!input)
		return (B_FALSE);
	input->mouse_curr_pos.x = x;
	input->mouse_curr_pos.y = y;
	input->mouse_move = B_TRUE;
	return (B_TRUE);
}

int	input_mouse_button(int button, int x, int y, t_input *input)
{
	(void)x;
	(void)y;
	if (!input)
		return (B_FALSE);
	if (button == LEFT_CLICK)
		input->mouse_left = B_TRUE;
	return (B_TRUE);
}
