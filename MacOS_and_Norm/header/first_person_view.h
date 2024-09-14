/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_person_view.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <yuhayrap@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 14:50:08 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/09/14 14:56:41 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIRST_PERSON_VIEW_H
# define FIRST_PERSON_VIEW_H

# include "image.h"
# include "utils.h"
# include "color.h"
# include "draw_shape.h"

# define FPV_NAME "FP POV"
# define FPV_POSITION_X 0
# define FPV_POSITION_Y 0
# define FPV_WIDTH 1440
# define FPV_HEIGHT 900
# define FPV_RAYS_COUNT 60
# define FPV_VIEW_SECTOR -30
# define FPV_PIXEL_WIDTH 8

typedef struct firstpersonview
{
	t_image	image;
	char	*name;
	int		floor_color;
	int		ceiling_color;
}	t_fpv;

t_statuscode	fp_view_init(t_fpv *view, void *mlx);
void			fp_view_draw(t_fpv *view);

#endif