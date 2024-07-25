#include "../header/the_game.h"

void    alt_mlx_pixel_put(t_Image *img, int x, int y, int color)
{
    char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void    draw_rectangle_filled(t_Image *img)
{
    int	i;
    int	j;

	if (!img)
		return ;
    i = 0;
    while (i < img->size.x)
	{
        j = 0;
        while (j < img->size.y)
		{
            *(unsigned int *)(img->addr + (i) * (img->bits_per_pixel / 8) +
							 			  (j) * img->line_length) = img->color;
            j++;
        }
        i++;
    }
}

void	render_image(t_GameData *fdf_data, t_Image *img)
{
	if (!fdf_data || !img)
		return ;
	mlx_put_image_to_window(fdf_data->mlx, fdf_data->mlx_window,
							img->img, img->pos.x, img->pos.y);
}

int	main()
{
	t_GameData	data;
	int size_y = 10;
	int	size_x = 9;

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

	int i = 0;
	while (i < size_y)
	{
		int j = 0;
		while (j < size_x)
		{
			printf("%c", map[i][j]);
			++j;
		}
		printf("\n");
		++i;
	}
	
	draw_rectangle_filled(&data.minimap);
	render_image(&data, &data.minimap);
	
	mlx_loop(data.mlx);
}