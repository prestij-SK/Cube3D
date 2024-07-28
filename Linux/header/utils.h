#ifndef UTILS_H
# define UTILS_H

#include <stdio.h> // DELETE

#include <math.h>

// HOOK EVENTS
# define EVENT_KEYDOWN 2 // pressed
# define EVENT_KEYUP 3 // released
# define EVENT_DESTROY 17 // Window cross icon

// KEY CODES
# define KEY_ESC 65307
# define KEY_A 97
# define KEY_W 119
# define KEY_D 100
# define KEY_S 115
# define KEY_LEFT 65361
# define KEY_RIGHT 65363

// MATH CONSTANTS
# ifndef M_PI
#  define M_PI 3.14159265358979323846
# endif

typedef struct Point2D_int
{
	int	x;
	int	y;
}	t_Point2D;

typedef struct Point2D_double
{
	double	x;
	double	y;
}	t_Point2D_d;

typedef enum StatusCode
{
	UNDEFINED_ERROR,
	NULL_POINTER_ERROR,
	MEMORY_ALLOCATION_ERROR,
	MLX_ERROR,
	MLX_WINDOW_ERROR,
	IMAGE_ERROR,
	PLAYER_LOCATION_ERROR,
	SUCCESS_EXIT,
}	t_StatusCode;

double	get_radians(int angle);

#endif