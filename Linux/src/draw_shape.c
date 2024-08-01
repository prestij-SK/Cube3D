#include "../header/draw_shape.h"

void    alt_mlx_pixel_put(t_Image *img, int x, int y, int color)
{
    char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void    draw_rectangle_filled(t_Image *img, t_Point2D pos, t_Point2D size, int color)
{
    int	i;
    int	j;

	if (!img)
		return ;
    i = 0;
    while (i < size.x)
	{
        j = 0;
        while (j < size.y)
		{
            alt_mlx_pixel_put(img, pos.x + i, pos.y + j, color);
            j++;
        }
        i++;
    }
}

int	is_steep(t_Point2D start, t_Point2D end)
{
	return (abs(end.y - start.y) > abs(end.x - start.x));
}

int	in_range(int x, int y, int width, int height)
{
	if (x > width || y > height || x < 0 || y < 0)
		return (0);
	return (1);
}

void    draw_line_Bresenham(t_Image *image, t_Line2D *line)
{
    t_BresenhamUtils    util;
    int                 pixel_color;

    if (!image || !line)
        return ;
    util.steep = is_steep(line->start, line->end); // Check if the line is steep
    // Swap coordinates if the line is steep to simplify calculations
    if (util.steep)
    {
        swap_int(&line->start.x, &line->start.y);
        swap_int(&line->end.x, &line->end.y);
    }
    // Ensure that we always iterate from left to right
    if (line->start.x > line->end.x)
    {
        swap_int(&line->start.x, &line->end.x);
        swap_int(&line->start.y, &line->end.y);
        swap_int(&line->color_start, &line->color_end);
    }

    util.delta.x = line->end.x - line->start.x; // we don't need to use abs() here as we ensured to start from bigger
    util.delta.y = abs(line->end.y - line->start.y); // change in y
    util.plot = 2 * util.delta.y - util.delta.x ; // Initial decision parameter
    util.step.x = line->start.x < line->end.x ? 1 : -1; // Determine the direction in x
    util.step.y = line->start.y < line->end.y ? 1 : -1; // Determine the direction in y
    util.temp.x = line->start.x; // Initialize current x coordinate
    util.temp.y = line->start.y; // Initialize current y coordinate

    int i = 0; // n-th pixel counter along the line
    while (util.temp.x != line->end.x)
    {
        pixel_color = line->color_start;
        // Plot the point, taking into account whether the line is steep or not
        if (util.steep && in_range(util.temp.y, util.temp.x, image->size.x, image->size.y))
            alt_mlx_pixel_put(image, util.temp.y, util.temp.x, pixel_color);
        else if (!util.steep && in_range(util.temp.x, util.temp.y, image->size.x, image->size.y))
            alt_mlx_pixel_put(image, util.temp.x, util.temp.y, pixel_color);
        else
            return ; // Quit the function if the coordinates are not in image's range
        util.temp.x += util.step.x; // Move to the next x coordinate
        // Update decision parameter and y coordinate if necessary
        if (util.plot >= 0)
        {
            util.temp.y += util.step.y;
            util.plot -= 2 * util.delta.x;
        }
        util.plot += 2 * util.delta.y; // Update decision parameter for the next point
        ++i;
    }
}