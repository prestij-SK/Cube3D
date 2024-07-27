#ifndef UTILS_H
# define UTILS_H

#include <stdio.h> // DELETE

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
	SUCCESS_EXIT,
}	t_StatusCode;

#endif