#ifndef DRAW_SHAPE_H
# define DRAW_SHAPE_H

# include "image.h"
# include "utils.h"

// This is created just for Norminette
typedef struct bresenhamutils
{
	t_Point2D	temp;
	t_Point2D	delta;
	t_Point2D	step;
	int			steep;
	int			plot;
}	t_bresenhamutils;

void    alt_mlx_pixel_put(t_image *img, int x, int y, int color);
void    draw_rectangle_filled(t_image *img, t_Point2D pos, t_Point2D size, int color);
void	draw_line_Bresenham(t_image *img, t_line2d *line);

#endif