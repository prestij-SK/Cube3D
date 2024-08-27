#ifndef INPUT_H
# define INPUT_H

# include "utils.h"

// HOOK EVENTS
# define EVENT_KEYDOWN 2 // pressed
# define EVENT_KEYUP 3 // released
# define EVENT_DESTROY 17 // Window cross icon
# define EVENT_MOUSEMOVE 6 // Mouse move

// KEY CODES
# define KEY_ESC 65307
# define KEY_A 97
# define KEY_W 119
# define KEY_D 100
# define KEY_S 115
# define KEY_M 109
# define KEY_E 101
# define KEY_ARROR_LEFT 65361
# define KEY_ARROR_RIGHT 65363

// MOUSE CODES
# define LEFT_CLICK 1
// # define SCROLL_UP 4
// # define SCROLL_DOWN 5

typedef struct InputData
{
	short		w;
	short		s;
	short		a;
	short		d;
	short		m;
	short		e;
	short		e_checked; // E is action button, to avoid spams we will need this
	short		esc;
	short		arrow_left;
	short		arrow_right;
	short		mouse_move;
	t_Point2D	mouse_prev_pos;
	t_Point2D	mouse_curr_pos;
	short		mouse_left;
} t_Input;

void	input_reset_all(t_Input *input);
int		input_key_press(int key, t_Input *input);
int		input_key_release(int key, t_Input *input);
int		input_mouse_move(int x, int y, t_Input *input);
int		input_mouse_button(int button, int x, int y, t_Input *input);

#endif