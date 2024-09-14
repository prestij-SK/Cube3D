/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_person_view.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skedikia <skedikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 14:07:58 by skedikia          #+#    #+#             */
/*   Updated: 2024/09/14 14:08:06 by skedikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/first_person_view.h"

t_statuscode	fp_view_init(t_fpv *view, void *mlx)
{
	t_statuscode	status;
	t_point2d		pos;
	t_point2d		size;

	if (!view || !mlx)
		return (NULL_POINTER_ERROR);
	pos.x = FPV_POSITION_X;
	pos.y = FPV_POSITION_Y;
	size.x = FPV_WIDTH;
	size.y = FPV_HEIGHT;
	status = image_init(&view->image, mlx, pos, size);
	if (status != SUCCESS_EXIT)
		return (status);
	view->name = FPV_NAME;
	return (SUCCESS_EXIT);
}

void	fp_view_draw(t_fpv *view)
{
	t_point2d	pos;
	t_point2d	size;

	if (!view)
		return ;
	pos.x = view->image.pos.x;
	pos.y = view->image.pos.y;
	size.x = view->image.size.x;
	size.y = view->image.size.y / 2;
	draw_rectangle_filled(&view->image, pos, size, view->ceiling_color);
	pos.y = view->image.size.y / 2;
	draw_rectangle_filled(&view->image, pos, size, view->floor_color);
}
