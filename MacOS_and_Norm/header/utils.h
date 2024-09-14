/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <yuhayrap@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 14:53:27 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/09/14 14:55:26 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>

# define B_TRUE 1
# define B_FALSE 0
# define WINDOW_WIDTH 1440
# define WINDOW_HEIGHT 900
# define MINIMAP_SIZE_DIVISER 4

typedef struct point2d_int
{
	int			x;
	int			y;
}				t_point2d;

typedef struct Point2D_double
{
	double		x;
	double		y;
}				t_point2d_d;

typedef struct line2d_int
{
	t_point2d	start;
	t_point2d	end;
	int			color_start;
	int			color_end;
}				t_line2d;

typedef struct line2d_double
{
	t_point2d	start;
	t_point2d	end;
	int			color_start;
	int			color_end;
}				t_line2d_d;

typedef struct raycastutils // This is for norminette
{
	double		px; // Player
	double		py;
	double		rx; // Ray
	double		ry;
	double		ox; // Offset
	double		oy;
	int			mx; // map index
	int			my;
	int			block_power;
	int			block_size;
	double		tx; // Texture
	double		ty;
	double		ty_step;
	double		ty_offset;
	double		line_offset;
	double		line_h;
	int			pixel_index;
	int			color;
	int			x; // counter for x
	int			y; // counter for y
}				t_rcutil;

typedef struct raycastfinaldata // This is for norminette
{
	t_point2d_d	ray_f;
	t_point2d_d	hor;
	t_point2d_d	ver;
	double		dis_f;
	double		dis_h;
	double		dis_v;
	short		f_closed_door; // Final information about closed door
	short		h_closed_door; // Information if horizontal Door is closed
	short		v_closed_door; // Information if vertical Door is closed
}				t_rcdata;

typedef struct gameupdateutil // This is for norminette
{
	t_point2d	offset;
	t_point2d	current;
	t_point2d	next;
}				t_updateutil;

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
}				t_statuscode;

void			error_exit(t_statuscode status, char *str);
void			success_exit(t_statuscode status, char *str);
size_t			get_time(void);
void			swap_int(int *a, int *b);

#endif