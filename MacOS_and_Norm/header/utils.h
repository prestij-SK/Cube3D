#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <sys/time.h>

#define B_TRUE 1
#define B_FALSE 0
#define WINDOW_WIDTH 1440 // Whatever WIDTH parameter is chosen, it must be divisible by RAYS_COUNT without a remainder.
#define WINDOW_HEIGHT 900
#define MINIMAP_SIZE_DIVISER 4 // Makes minimap smaller

typedef struct Point2D_int
{
	int x;
	int y;
} t_Point2D;

typedef struct Point2D_double
{
	double x;
	double y;
} t_point2d_d;

typedef struct line2d_int
{
	t_Point2D start;
	t_Point2D end;
	int color_start;
	int color_end;
} t_line2d;

typedef struct line2d_double
{
	t_Point2D start;
	t_Point2D end;
	int color_start;
	int color_end;
} t_line2d_d;

typedef struct raycastutils // This is for norminette
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
	double tx; // Texture
	double ty;
	double ty_step;		// Next texture slice interval
	double ty_offset;	// Texture placement control
	double line_offset; // Wall placement control
	double line_h;		// Height of the wall
	int pixel_index;
	int color;
	int x; // counter for x
	int y; // counter for y
} t_rcutil;

typedef struct raycastfinaldata // This is for norminette
{
	t_point2d_d ray_f;	 // Final ray
	t_point2d_d hor;	 // Horizontal Ray
	t_point2d_d ver;	 // Vertical Ray
	double dis_f;		 // Shortest distance from Horizontal and Vertical
	double dis_h;		 // Horizontal distance
	double dis_v;		 // Vertical distance
	short f_closed_door; // Final information about closed door
	short h_closed_door; // Information if horizontal Door is closed
	short v_closed_door; // Information if vertical Door is closed
} t_rcdata;

typedef struct gameupdateutil // This is for norminette
{
	t_Point2D offset;  // Calculate gap between player and wall
	t_Point2D current; // Where is current player position for map[][]
	t_Point2D next;	   // Where is player position after change for map[][]
} t_updateutil;

typedef enum statuscode
{
	UNDEFINED_ERROR,
	NULL_POINTER_ERROR,
	MEMORY_ALLOCATION_ERROR,
	MLX_ERROR,
	MLX_WINDOW_ERROR,
	IMAGE_ERROR,
	PLAYER_LOCATION_ERROR,
	DOOR_NUMBER_ERROR,
	WALL_TEXTURE_ERROR,
	GUN_TEXTURE_ERROR,
	DOOR_TEXTURE_ERROR,
	SUCCESS_EXIT,
} t_statuscode;

void error_exit(t_statuscode status, char *str);
void success_exit(t_statuscode status, char *str);
size_t get_time(void);
void swap_int(int *a, int *b);

#endif