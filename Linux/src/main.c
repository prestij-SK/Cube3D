#include "../header/the_game.h"

// void    alt_mlx_pixel_put(t_Image *img, int x, int y, int color)
// {
//     char	*dst;

// 	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
// 	*(unsigned int*)dst = color;
// }

void	render_image(t_GameData *fdf_data, t_Image *img, t_Point2D pos)
{
	if (!fdf_data || !img)
		return ;
	mlx_put_image_to_window(fdf_data->mlx, fdf_data->mlx_window,
							img->img, pos.x, pos.y);
}

int	main()
{
	t_GameData	data;
	int size_y = 10;
	int	size_x = 9;
	int	i = 0;
	int	j = 0;

	char	map[10][9] =
	{
		{'1', '1', '1', '1', '1', '1', '1', '1', '1'},
		{'1', '0', '1', '1', '0', '0', '1', '1', '1'},
		{'1', '0', '1', '1', '0', '0', '1', '0', '1'},
		{'1', '0', '1', '1', '0', '0', '0', '0', '1'},
		{'1', '0', '0', '1', '0', '0', '0', '0', '1'},
		{'1', '0', '0', '0', '0', '0', '0', '0', '1'},
		{'1', '0', '0', '0', '0', '1', '0', '0', '1'},
		{'1', '0', '0', 'P', '0', '1', '0', '1', '1'},
		{'1', '1', '0', '0', '0', '0', '0', '1', '1'},
		{'1', '1', '1', '1', '1', '1', '1', '1', '1'}
	};
	game_data_init(&data);

	i = 0;
	while (i < size_y)
	{
		j = 0;
		while (j < size_x)
		{
			printf("%c", map[i][j]);
			++j;
		}
		printf("\n");
		++i;
	}
	
	// draw_rectangle_filled(&data.minimap.image, data.minimap.pos, data.minimap.size, data.minimap.wall_color);
	// render_image(&data, &data.minimap.image, data.minimap.pos);
	// draw_rectangle_filled(&data.minimap.image, data.player.pos, data.player.size, data.player.color);
	
	i = 0;
	while (i < size_y)
	{
		j = 0;
		while (j < size_x)
		{
			t_Point2D	pos;
			t_Point2D	size;
			pos.x = j * MINIMAP_SQUARE_SIZE_X;
			pos.y = i * MINIMAP_SQUARE_SIZE_Y;
			size.x = MINIMAP_SQUARE_SIZE_X;
			size.y = MINIMAP_SQUARE_SIZE_Y;
			if (map[i][j] == '1')
				draw_rectangle_filled(&data.minimap.image, pos, size, data.minimap.wall_color);
			else if (map[i][j] == '0')
				draw_rectangle_filled(&data.minimap.image, pos, size, data.minimap.floor_color);
			else if (map[i][j] == 'P')
			{
				draw_rectangle_filled(&data.minimap.image, pos, size, data.minimap.wall_color);
				pos.x = (pos.x + (pos.x + MINIMAP_SQUARE_SIZE_X)) / 2 - MINIMAP_SQUARE_SIZE_X / 8;
				pos.y = (pos.y + (pos.y + MINIMAP_SQUARE_SIZE_Y)) / 2 - MINIMAP_SQUARE_SIZE_Y / 8;
				size.x = MINIMAP_SQUARE_SIZE_X / 4;
				size.y = MINIMAP_SQUARE_SIZE_Y / 4;
				draw_rectangle_filled(&data.minimap.image, pos, size, data.player.color);
			}
			++j;
		}
		++i;
	}
	render_image(&data, &data.minimap.image, data.minimap.pos);
	mlx_loop(data.mlx);
}