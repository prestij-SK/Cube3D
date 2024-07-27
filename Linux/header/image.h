#ifndef IMAGE_H
# define IMAGE_H

# include "../mlx_linux/mlx.h"
# include "utils.h"

typedef struct ImageData
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}	t_Image;

t_StatusCode	image_init(t_Image *image, void *mlx, int size_x, int size_y);

#endif