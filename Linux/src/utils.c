#include "../header/utils.h"

double	get_radians(int angle)
{
	return (angle * M_PI / 180.0);
}

void	swap_int(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}