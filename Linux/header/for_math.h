#ifndef FOR_MATH_H
# define FOR_MATH_H

# include "utils.h"

# include <math.h>

// CONSTANTS
# ifndef M_PI
#  define M_PI 3.14159265358979323846
# endif
// # define P0 0 // 0 degree
# define P1 M_PI / 2 // 90 degree
// # define P2 M_PI // 180 degree
# define P3 3 * M_PI / 2 // 270 degree
# define P4 2 * M_PI		// 360 degree
# define ONE_DEGREE_RADIAN 0.0174532925 // one degree in radians

// a: This is the coefficient of the x-term in the line equation. It represents the change in y with respect to x.
// b: This is the coefficient of the y-term in the line equation. It represents the change in x with respect to y.
// c: This is the constant term in the line equation. It represents the value that balances the equation given specific x and y values.
// deter:  It is used to determine whether the lines are parallel, coincident, or intersecting at a single point.
typedef struct t_MathDataUtil
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
}	t_MathUtil;

double	get_radians(int angle);
double	distance(double x1, double y1, double x2, double y2);
int		intersection_point(t_Line2D_d *l1, t_Line2D_d *l2, double *x, double *y);
double	angle_wrapping(double angle);

# endif