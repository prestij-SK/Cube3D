#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// HOOK EVENTS
# define EVENT_KEYDOWN 2	 // pressed
# define EVENT_KEYUP 3	 // released
# define EVENT_DESTROY 17 // Window cross icon

// KEY CODES
# define KEY_ESC 65307
# define KEY_A 97
# define KEY_W 119
# define KEY_D 100
# define KEY_S 115
# define KEY_LEFT 65361
# define KEY_RIGHT 65363

typedef struct Point2D_int
{
	int x;
	int y;
} t_Point2D;

typedef struct Point2D_double
{
	double x;
	double y;
} t_Point2D_d;

typedef struct Line2D_int
{
	t_Point2D start;
	t_Point2D end;
	int color_start;
	int color_end;
} t_Line2D;

typedef struct Line2D_double
{
	t_Point2D start;
	t_Point2D end;
	int color_start;
	int color_end;
} t_Line2D_d;

typedef struct RayCastUtils // This is for norminette
{
	double px; // Player
	double py;
	double rx; // Ray
	double ry;
	double ox; // Offset
	double oy;
	int mx; // map index
	int my;
	int block_power;
	int block_size;
} t_RCutil;

typedef struct RayCastFinalData // This is for norminette
{
	double		dis_f;	 // Shortest distance from Horizontal and Vertical
	t_Point2D_d	ray_f; // Final ray
	double 		dis_h; // Horizontal distance
	t_Point2D_d	hor; // Horizontal Ray
	double 		dis_v; // Vertical distance
	t_Point2D_d	ver; // Vertical Ray
} t_RCdata;

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
} t_StatusCode;

void	swap_int(int *a, int *b);
void	error_exit(t_StatusCode status, char *str);
void	success_exit(t_StatusCode status, char *str);

#endif