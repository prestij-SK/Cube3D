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
            // printf("i: %d    j: %d\n", i, j);
            alt_mlx_pixel_put(img, pos.x + i, pos.y + j, color);
            j++;
        }
        i++;
    }
}