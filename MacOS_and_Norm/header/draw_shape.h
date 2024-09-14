/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_shape.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <yuhayrap@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 14:50:01 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/09/14 14:56:06 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_SHAPE_H
# define DRAW_SHAPE_H

# include "image.h"
# include "utils.h"

// This is created just for Norminette
typedef struct bresenhamutils
{
	t_point2d	temp;
	t_point2d	delta;
	t_point2d	step;
	int			steep;
	int			plot;
}	t_bresenhamutils;

void	alt_mlx_pixel_put(t_image *img, int x, int y, int color);
void	draw_rectangle_filled(t_image *img, t_point2d pos, \
	t_point2d size, int color);
void	draw_line_bresenham(t_image *img, t_line2d *line);

#endif