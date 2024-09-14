/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_math.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skedikia <skedikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 14:08:27 by skedikia          #+#    #+#             */
/*   Updated: 2024/09/14 14:08:35 by skedikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/for_math.h"

double	get_radians(int angle)
{
	return (angle * M_PI / 180.0);
}

double	distance(double x1, double y1, double x2, double y2)
{
	return (sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2)));
}

double	angle_wrapping(double angle)
{
	double	new_angle;

	new_angle = angle;
	if (angle < 0)
		new_angle += P4;
	if (angle > P4)
		new_angle -= P4;
	return (new_angle);
}

int	intersection_point(t_line2d_d *l1, t_line2d_d *l2, double *x, double *y)
{
	t_mathutil	util;

	util.a1 = l1->end.y - l1->start.y;
	util.b1 = l1->start.x - l1->end.x;
	util.c1 = (util.a1 * l1->start.x) + (util.b1 * l1->start.y);
	util.a2 = l2->end.y - l2->start.y;
	util.b2 = l2->start.x - l2->end.x;
	util.c2 = (util.a2 * l2->start.x) + (util.b2 * l2->start.y);
	util.deter = (util.a1 * util.b2) - (util.a2 * util.b1);
	if (util.deter != 0)
	{
		*x = ((util.b2 * util.c1) - (util.b1 * util.c2)) / util.deter;
		*y = ((util.a1 * util.c2) - (util.a2 * util.c1)) / util.deter;
		return (1);
	}
	return (0);
}
