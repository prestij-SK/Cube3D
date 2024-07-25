#include "../header/image.h"

t_StatusCode	image_init(t_Image *image, void *mlx, int size_x, int size_y)
{
	if (!image)
		return (NULL_POINTER_ERROR);
	image->img = mlx_new_image(mlx, size_x, size_y);
	if (!image->img)
		return (IMAGE_ERROR);
	image->addr = mlx_get_data_addr(image->img, &image->bits_per_pixel,
									&image->line_length, &image->endian);
	if (!image->addr)
		return (IMAGE_ERROR);
	return (SUCCESS_EXIT);
}