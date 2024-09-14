/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <yuhayrap@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 14:51:27 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/09/14 14:57:42 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_H
# define INPUT_H

# include "utils.h"

// HOOK EVENTS
# define EVENT_KEYDOWN 2 // pressed
# define EVENT_KEYUP 3 // released
# define EVENT_DESTROY 17 // Window cross icon
# define EVENT_MOUSEMOVE 6 // Mouse move

// KEY CODES
# ifdef __linux__
#  define UNAME		"Linux"
#  define KEY_ESC 65307
#  define KEY_A 97
#  define KEY_W 119
#  define KEY_D 100
#  define KEY_S 115
#  define KEY_M 109
#  define KEY_E 101
#  define KEY_ARROR_LEFT 65361
#  define KEY_ARROR_RIGHT 65363

# elif defined(__APPLE__)
#  define UNAME		"Darwin"
#  define KEY_ESC 53
#  define KEY_A 0
#  define KEY_W 13
#  define KEY_D 2
#  define KEY_S 1
#  define KEY_M 46
#  define KEY_E 14
#  define KEY_ARROR_LEFT 123
#  define KEY_ARROR_RIGHT 124

# else
#  define KEY_ESC 65307
#  define KEY_A 97
#  define KEY_W 119
#  define KEY_D 100
#  define KEY_S 115
#  define KEY_M 109
#  define KEY_E 101
#  define KEY_ARROR_LEFT 65361
#  define KEY_ARROR_RIGHT 65363
# endif

// MOUSE CODES
# define LEFT_CLICK 1

typedef struct inputdata
{
	short		w;
	short		s;
	short		a;
	short		d;
	short		m;
	short		e;
	short		e_checked;
	short		esc;
	short		arrow_left;
	short		arrow_right;
	short		mouse_move;
	t_point2d	mouse_prev_pos;
	t_point2d	mouse_curr_pos;
	short		mouse_left;
}	t_input;

void	input_reset_all(t_input *input);
int		input_key_press(int key, t_input *input);
int		input_key_release(int key, t_input *input);
int		input_mouse_move(int x, int y, t_input *input);
int		input_mouse_button(int button, int x, int y, t_input *input);

#endif