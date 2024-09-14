/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_math.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <yuhayrap@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 14:50:31 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/09/14 15:06:07 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FOR_MATH_H
# define FOR_MATH_H

# include "utils.h"

# include <math.h>

# ifndef M_PI
#  define M_PI 3.14159265358979323846
# endif
// # define P1 M_PI / 2
// # define P3 3 * M_PI / 2
// # define P4 2 * M_PI
# define P1 1.57079632679
# define P3 4.71238898038
# define P4 6.28318530718
# define ONE_DEGREE_RADIAN 0.0174532925

typedef struct t_Mmathdatautil
{
	double	a1; // a
	double	a2;
	double	b1; // b
	double	b2;
	double	c1; // c
	double	c2;
	double	deter; // determinant
	double	x;
	double	y;
}	t_mathutil;

double	get_radians(int angle);
double	distance(double x1, double y1, double x2, double y2);
int		intersection_point(t_line2d_d *l1, t_line2d_d *l2, \
	double *x, double *y);
double	angle_wrapping(double angle);

#endif
