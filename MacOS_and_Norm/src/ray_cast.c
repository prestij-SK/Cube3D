/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <yuhayrap@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 14:20:20 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/09/14 14:28:12 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/the_game.h"

static void	set_wall_texture(t_gamedata *data, t_rcdata *ray_data,
		double ray_angle)
{
	if (ray_data->dis_v < ray_data->dis_h)
	{
		if (ray_angle > P1 && ray_angle < P3)
			data->tex_p = &data->west_wall;
		else
			data->tex_p = &data->east_wall;
	}
	else
	{
		if (ray_angle > 0 && ray_angle < M_PI)
			data->tex_p = &data->south_wall;
		else
			data->tex_p = &data->north_wall;
	}
	if (ray_data->f_closed_door == B_TRUE)
	{
		data->tex_p = &data->door_tex;
	}
}

static void	texture_mapping(t_gamedata *data, t_rcdata *ray_data,
		t_rcutil *util, double ray_angle)
{
	util->ty_step = data->tex_p->size.y / util->line_h;
	util->ty_offset = 0;
	if (util->line_h > FPV_HEIGHT)
	{
		util->ty_offset = fabs((FPV_HEIGHT - util->line_h) / 2.0);
		util->line_h = FPV_HEIGHT;
	}
	if (ray_data->dis_v < ray_data->dis_h)
	{
		util->tx = (int)(ray_data->ray_f.y) % data->tex_p->size.x;
		if (ray_angle > P1 && ray_angle < P3)
		{
			util->tx = data->tex_p->size.x - 1 - util->tx;
		}
	}
	else
	{
		util->tx = (int)(ray_data->ray_f.x) % data->tex_p->size.x;
		if (ray_angle > 0 && ray_angle < M_PI)
		{
			util->tx = data->tex_p->size.x - 1 - util->tx;
		}
	}
	util->ty = util->ty_offset * util->ty_step;
}

static void	ray_texture_mapping_draw(t_gamedata *data, t_rcutil *util,
		t_point2d size, t_point2d pos)
{
	util->y = 0;
	while (util->y < size.y)
	{
		util->pixel_index = (int)util->ty * data->tex_p->line_length
			+ (int)util->tx * (data->tex_p->bits_per_pixel / 8);
		if (util->pixel_index < 0)
		{
			data->easter_found = B_TRUE;
			return ;
		}
		util->color = *(int *)(data->tex_p->addr + util->pixel_index);
		util->x = 0;
		while (util->x < size.x)
		{
			alt_mlx_pixel_put(&data->view.image, pos.x + util->x, pos.y
				+ util->y, util->color);
			++util->x;
		}
		util->ty += util->ty_step;
		++util->y;
	}
}

static void	ray_cast_walls(t_gamedata *data, t_rcdata *ray_data, int ray,
		double ray_angle)
{
	t_rcutil	util;
	t_point2d	pos;
	t_point2d	size;
	double		ca;

	ca = data->player.angle - ray_angle;
	ca = angle_wrapping(ca);
	util.line_h = (data->minimap.block_size * FPV_HEIGHT) / (ray_data->dis_f
			* cos(ca));
	if (data->easter_found == B_TRUE)
		data->tex_p = &data->easter_tex;
	else
		set_wall_texture(data, ray_data, ray_angle);
	texture_mapping(data, ray_data, &util, ray_angle);
	util.line_offset = FPV_HEIGHT / 2 - util.line_h / 2;
	size.x = FPV_WIDTH / RAY_COUNT;
	size.y = util.line_h;
	pos.x = ray * (FPV_WIDTH / RAY_COUNT);
	pos.y = util.line_offset;
	ray_texture_mapping_draw(data, &util, size, pos);
}

void	ray_casting(t_gamedata *data)
{
	t_rcdata	ray_data;
	int			r;
	double		ray_angle;

	ray_angle = data->player.angle + ONE_DEGREE_RADIAN * (SECTOR_ANGLE);
	ray_angle = angle_wrapping(ray_angle);
	r = 0;
	while (r < RAY_COUNT)
	{
		ray_data.f_closed_door = B_FALSE;
		ray_data.h_closed_door = B_FALSE;
		ray_data.v_closed_door = B_FALSE;
		horizontal_checking(data, &ray_data, ray_angle);
		vertical_checking(data, &ray_data, ray_angle);
		set_shortest_ray_dis(&ray_data);
		draw_ray_line(data, &ray_data);
		ray_cast_walls(data, &ray_data, r, ray_angle);
		ray_angle += RADIAN_STEP;
		ray_angle = angle_wrapping(ray_angle);
		++r;
	}
}
