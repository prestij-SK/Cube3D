#include "../header/first_person_view.h"

t_StatusCode	fp_view_init(t_FPV *view, void *mlx)
{
	t_StatusCode	status;
	t_Point2D 		pos;
	t_Point2D		size;

	if (!view || !mlx)
		return (NULL_POINTER_ERROR);
	pos.x = FPV_POSITION_X;
	pos.y = FPV_POSITION_Y;
	size.x = FPV_WIDTH;
	size.y = FPV_HEIGHT;
	status = image_init(&view->image, mlx, pos, size);
	if (status != SUCCESS_EXIT)
		return (status);
	view->name = FPV_NAME;
	view->color = COLOR_BLUE;
	return (SUCCESS_EXIT);
}

void	fp_view_draw(t_FPV *view)
{
	if (!view)
		return ;
	draw_rectangle_filled(&view->image, view->image.pos, view->image.size, view->color);
}