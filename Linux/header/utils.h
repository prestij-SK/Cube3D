#ifndef UTILS_H
# define UTILS_H

#include <stdio.h> // DELETE

// HOOK EVENTS
# define EVENT_KEYDOWN 2 // pressed

// KEY CODES
# define KEY_A 97
# define KEY_W 119
# define KEY_D 100
# define KEY_S 115

typedef struct Point2D_int
{
	int	x;
	int	y;
}	t_Point2D;

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

#endif