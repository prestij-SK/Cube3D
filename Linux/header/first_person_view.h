#ifndef FIRST_PERSON_POV_H
# define FIRST_PERSON_POV_H

# include "image.h"
# include "utils.h"
# include "color.h"
# include "draw_shape.h"

# define FPV_NAME "FP POV"
# define FPV_POSITION_X 0
# define FPV_POSITION_Y 0
# define FPV_WIDTH 1440 // Whatever WIDTH parameter is chosen, it must be divisible by RAYS_COUNT without a remainder.
# define FPV_HEIGHT 900
# define FPV_RAYS_COUNT 60
# define FPV_VIEW_SECTOR -30
# define FPV_PIXEL_WIDTH 8

typedef struct FirstPersonView
{
	t_Image	image;
	char	*name;
	int		floor_color; // this might change
	int		ceiling_color;
}	t_FPV;

t_StatusCode	fp_view_init(t_FPV *view, void *mlx);
void			fp_view_draw(t_FPV *view);

#endif