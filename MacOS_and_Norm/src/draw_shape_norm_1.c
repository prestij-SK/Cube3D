#include "../header/draw_shape.h"

static int  is_steep(t_Point2D start, t_Point2D end)
{
	return (abs(end.y - start.y) > abs(end.x - start.x));
}

static int  in_range(int x, int y, int width, int height)
{
	if (x > width || y > height || x < 0 || y < 0)
		return (0);
    if (x > WINDOW_WIDTH || y > WINDOW_HEIGHT)
        return (0);
	return (1);
}

static void	line_preperation_norm(t_bresenhamutils *util, t_line2d *line)
{
	util->steep = is_steep(line->start, line->end);
	if (util->steep)
	{
		swap_int(&line->start.x, &line->start.y);
		swap_int(&line->end.x, &line->end.y);
	}
	if (line->start.x > line->end.x)
	{
		swap_int(&line->start.x, &line->end.x);
		swap_int(&line->start.y, &line->end.y);
		swap_int(&line->color_start, &line->color_end);
	}
	util->delta.x = line->end.x - line->start.x;
	util->delta.y = abs(line->end.y - line->start.y);
	util->plot = 2 * util->delta.y - util->delta.x;
	if (line->start.x < line->end.x)
		util->step.x = 1;
	else
		util->step.x = -1;
	if (line->start.y < line->end.y)
		util->step.y = 1;
	else
		util->step.y = -1;
	util->temp.x = line->start.x;
	util->temp.y = line->start.y;
}

static void	plot_check_norm(t_bresenhamutils *util)
{
	if (!util)
		return ;
	if (util->plot >= 0)
	{
		util->temp.y += util->step.y;
		util->plot -= 2 * util->delta.x;
	}
}

void	draw_line_Bresenham(t_image *img, t_line2d *line)
{
	t_bresenhamutils	util;
	int					pixel_color;
	int					i;

	if (!img || !line)
		return ;
	line_preperation_norm(&util, line);
	i = 0;
	while (util.temp.x != line->end.x)
	{
		pixel_color = line->color_start;
		if (util.steep && in_range(util.temp.y, util.temp.x,
				img->size.x, img->size.y))
			alt_mlx_pixel_put(img, util.temp.y, util.temp.x, pixel_color);
		else if (!util.steep && in_range(util.temp.x, util.temp.y,
				img->size.x, img->size.y))
			alt_mlx_pixel_put(img, util.temp.x, util.temp.y, pixel_color);
		else
			return ;
		util.temp.x += util.step.x;
		plot_check_norm(&util);
		util.plot += 2 * util.delta.y;
		++i;
	}
	return ;
}

// void    draw_line_Bresenham(t_Image *image, t_Line2D *line)
// {
//     t_BresenhamUtils    util;
//     int                 pixel_color;

//     if (!image || !line)
//         return ;
//     util.steep = is_steep(line->start, line->end); // Check if the line is steep
//     // Swap coordinates if the line is steep to simplify calculations
//     if (util.steep)
//     {
//         swap_int(&line->start.x, &line->start.y);
//         swap_int(&line->end.x, &line->end.y);
//     }
//     // Ensure that we always iterate from left to right
//     if (line->start.x > line->end.x)
//     {
//         swap_int(&line->start.x, &line->end.x);
//         swap_int(&line->start.y, &line->end.y);
//         swap_int(&line->color_start, &line->color_end);
//     }

//     util.delta.x = line->end.x - line->start.x; // we don't need to use abs() here as we ensured to start from bigger
//     util.delta.y = abs(line->end.y - line->start.y); // change in y
//     util.plot = 2 * util.delta.y - util.delta.x ; // Initial decision parameter
//     util.step.x = line->start.x < line->end.x ? 1 : -1; // Determine the direction in x
//     util.step.y = line->start.y < line->end.y ? 1 : -1; // Determine the direction in y
//     util.temp.x = line->start.x; // Initialize current x coordinate
//     util.temp.y = line->start.y; // Initialize current y coordinate

//     int i = 0; // n-th pixel counter along the line
//     while (util.temp.x != line->end.x)
//     {
//         pixel_color = line->color_start;
//         // Plot the point, taking into account whether the line is steep or not
//         if (util.steep && in_range(util.temp.y, util.temp.x, image->size.x, image->size.y))
//             alt_mlx_pixel_put(image, util.temp.y, util.temp.x, pixel_color);
//         else if (!util.steep && in_range(util.temp.x, util.temp.y, image->size.x, image->size.y))
//             alt_mlx_pixel_put(image, util.temp.x, util.temp.y, pixel_color);
//         else
//             return ; // Quit the function if the coordinates are not in image's range
//         util.temp.x += util.step.x; // Move to the next x coordinate
//         // Update decision parameter and y coordinate if necessary
//         if (util.plot >= 0)
//         {
//             util.temp.y += util.step.y;
//             util.plot -= 2 * util.delta.x;
//         }
//         util.plot += 2 * util.delta.y; // Update decision parameter for the next point
//         ++i;
//     }
// }