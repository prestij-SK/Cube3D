#ifndef IMAGE_H
# define IMAGE_H

# include "../mlx_linux/mlx.h"
# include "utils.h"

typedef struct ImageData
{
	void		*img;
	char		*addr;
	char		*name;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	t_Point2D	pos;
	t_Point2D	size;
	int			color;
}	t_Image;

t_StatusCode	image_init(t_Image *image, void *mlx, int size_x, int size_y);

#endif