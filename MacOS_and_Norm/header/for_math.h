#ifndef FOR_MATH_H
# define FOR_MATH_H

# include "utils.h"

# include <math.h>

# ifndef M_PI
#  define M_PI 3.14159265358979323846
# endif
# define P1 M_PI / 2
# define P3 3 * M_PI / 2
# define P4 2 * M_PI
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
int		intersection_point(t_line2d_d *l1, t_line2d_d *l2, double *x, double *y);
double	angle_wrapping(double angle);

# endif