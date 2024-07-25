#include "../header/minimap.h"

t_StatusCode	minimap_init(t_Image *image, void *mlx,  int size_x, int size_y)
{
	t_StatusCode	status;

	if (!image)
		return (NULL_POINTER_ERROR);
	status = image_init(image, mlx, size_x, size_y);
	if (status != SUCCESS_EXIT)
		return (status);
	image->name = MINIMAP_NAME;
	image->color = COLOR_BLUE;
	image->size.x = size_x;
	image->size.y = size_y;
	// calculate position by using size here if needed
	image->pos.x = MINIMAP_POSITION_X;
	image->pos.y = MINIMAP_POSITION_Y;
	return (SUCCESS_EXIT);
}