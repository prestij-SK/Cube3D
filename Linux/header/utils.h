#ifndef UTILS_H
# define UTILS_H

#include <stdio.h> // DELETE

# include <math.h>
# include <stdlib.h>

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
# define P0 0 // 0 degree
# define P1 M_PI / 2 // 90 degree
// # define P2 M_PI // 180 degree
# define P3 3 * M_PI / 2 // 270 degree
# define P4 2 * M_PI // 0 degree

# define D_RADIAN 0.0174532925 // one degree in radians

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

typedef struct Line2D_int
{
	t_Point2D	start;
	t_Point2D	end;
	int			color_start;
	int			color_end;
}	t_Line2D;

typedef struct RayCastUtils
{

}	t_RCUtil;

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
void	swap_int(int *a, int *b);

#endif