#ifndef DRAW_SHAPE_H
# define DRAW_SHAPE_H

# include "image.h"
# include "utils.h"

// This is created just for Norminette
typedef struct BresenhamUtils
{
	t_Point2D	temp;
	t_Point2D	delta;
	t_Point2D	step;
	int			steep;
	int			plot;
}	t_BresenhamUtils;

void    alt_mlx_pixel_put(t_Image *img, int x, int y, int color);
void    draw_rectangle_filled(t_Image *img, t_Point2D pos, t_Point2D size, int color);
void	draw_line_Bresenham(t_Image *img, t_Line2D *line); // Remember, this function works correctly with positive coordinates

#endif