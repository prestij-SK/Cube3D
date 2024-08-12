#include "../header/the_game.h"

#include "../header/temp_texture.h" // DELETE

typedef struct  s_draw_state
{
    int         last_x;
    int         last_y;
    int         repeat_width;
}               t_draw_state;

void	ray_cast_3d_walls(t_GameData *data, t_RCdata *ray_data, int ray, double ray_angle, t_draw_state *state)
{
	t_Point2D	pos;
	t_Point2D	size;
	int			line_h;
	int			offset;
	double		ca;

	ca = data->player.angle - ray_angle;
	if (ca < 0)
		ca += P4;
	if (ca > P4)
		ca -= P4;
	ray_data->dis_f = ray_data->dis_f * cos(ca); // fish eye fix
	line_h = (data->view.image.size.y * 32) / ray_data->dis_f;
	if (line_h > data->view.image.size.y)
		line_h = data->view.image.size.y;
	offset = data->view.image.size.y - (line_h / 2);
	pos.x = ray * (data->view.image.size.x / 60);
	pos.y = offset - data->view.image.size.y / 2;
	size.x = data->view.image.size.x / 59;
	size.y = line_h;

	// int x = 0;
	// int y = 0;
	// while (y < size.y)
	// {
	// 	x = 0;
	// 	while (x < size.x)
	// 	{
	// 		alt_mlx_pixel_put(&data->view.image, pos.x + x, pos.y + y, COLOR_RED);
	// 		++x;
	// 	}
	// 	++y;
	// }
	//
	t_Image tex;

	tex.img = mlx_xpm_file_to_image(data->mlx, "/home/steve/Desktop/cube3D/Linux/texture/flag.xpm", &tex.size.x, &tex.size.y);
	if (!tex.img)
    {
        fprintf(stderr, "Error: Failed to load texture from '../texture/flag.xpm'\n");
        exit(1);
    }
	tex.addr = mlx_get_data_addr(tex.img, &tex.bits_per_pixel, &tex.line_length, &tex.endian);

	int tx;
	int ty;
	int color;
	int	bpp = tex.bits_per_pixel / 8;

    for (int i = 0; i < size.y; i++)
    {
        for (int j = 0; j < size.x; j++)
        {
            // Calculate the texture coordinates for horizontal repetition
            tx = (j + state->last_x) % state->repeat_width;
            tx = tx * tex.size.x / state->repeat_width;

            // Scale the texture vertically to fit the rectangle height
            ty = (i * tex.size.y) / size.y;

            // Calculate the offset in the texture data
            int offset = (ty * tex.size.x + tx) * bpp;

            // Fetch the color from the texture
            color = *((int *)(tex.addr + offset));
            
            // Draw the pixel on the window
			alt_mlx_pixel_put(&data->view.image, pos.x + j, pos.y + i, color);
        }
    }
	// Update state with the new end position
    state->last_x = (pos.x + size.x) % state->repeat_width;
    state->last_y = (pos.y + size.y) % tex.size.y;
	//







	// draw_rectangle_filled(&data->view.image, pos, size, COLOR_RED);
}

// A lot of stuff is going on here, which is read and written from internet sources.
// Will update to more readable after I see the results.
void	ray_casting(t_GameData *data)
{
	t_RCdata	ray_data;
	int			r; // rays
	double		ray_angle; // in radians


t_draw_state state;

state.last_x = 0;
state.last_y = 0;
state.repeat_width = 200;

	ray_angle = data->player.angle + D_RADIAN * (-30);
	if (ray_angle < 0)
		ray_angle += P4;
	if (ray_angle > P4)
		ray_angle -= P4;
	r = 0;
	while (r < 60)
	{
		horizontal_checking(data, &ray_data, ray_angle);
		vertical_checking(data, &ray_data, ray_angle);
		t_Line2D	line;
		// Horizontal Line
		// line.color_end = COLOR_RED;
		// line.color_start = COLOR_RED;
		// line.start.x = data->player.initial_pos.x;
		// line.start.y = data->player.initial_pos.y;
		// line.end.x = ray_data.hor.x;
		// line.end.y = ray_data.hor.y;
		// printf("distance: %d\n", ray_data.dis_h);
		// draw_line_Bresenham(&data->minimap.image, &line);

		// Vertical Line
		// line.color_end = COLOR_RED;
		// line.color_start = COLOR_RED;
		// line.start.x = data->player.initial_pos.x;
		// line.start.y = data->player.initial_pos.y;
		// line.end.x = ray_data.ver.x;
		// line.end.y = ray_data.ver.y;
		// printf("distance: %d\n", ray_data.dis_v);
		// draw_line_Bresenham(&data->minimap.image, &line);

		// Final Line
		line.color_end = COLOR_RED;
		line.color_start = COLOR_RED;
		line.start.x = data->player.initial_pos.x;
		line.start.y = data->player.initial_pos.y;
		if (ray_data.dis_h < ray_data.dis_v)
		{
			line.end.x = ray_data.hor.x;
			line.end.y = ray_data.hor.y;
			ray_data.dis_f = ray_data.dis_h;
		}
		else
		{
			line.end.x = ray_data.ver.x;
			line.end.y = ray_data.ver.y;
			ray_data.dis_f = ray_data.dis_v;
		}
		// printf("distance: %d\n", ray_data.dis_f);
		draw_line_Bresenham(&data->minimap.image, &line);

		ray_cast_3d_walls(data, &ray_data, r, ray_angle, &state);
		ray_angle += D_RADIAN;
		if (ray_angle < 0)
			ray_angle += P4;
		if (ray_angle > P4)
			ray_angle -= P4;
		++r;
	}
}