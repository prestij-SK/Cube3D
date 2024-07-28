#include "../header/image.h"

t_StatusCode	image_init(t_Image *image, void *mlx, t_Point2D pos, t_Point2D size)
{
	if (!image || !mlx)
		return (NULL_POINTER_ERROR);
	image->img = mlx_new_image(mlx, size.x, size.y);
	if (!image->img)
		return (IMAGE_ERROR);
	image->addr = mlx_get_data_addr(image->img, &image->bits_per_pixel,
									&image->line_length, &image->endian);
	if (!image->addr)
		return (IMAGE_ERROR);
	image->pos.x = pos.x;
	image->pos.y = pos.y;
	image->size.x = size.x;
	image->size.y = size.y;
	return (SUCCESS_EXIT);
}