#include "../header/the_game.h"

#include <stdio.h>

// char *path = "/home/steve/Desktop/cube3D/Linux/texture/flag.xpm";

// typedef struct  s_img
// {
//     void        *img_ptr;
//     char        *addr; // Changed from int *data to char *addr
//     int         width;
//     int         height;
//     int         size_line;
//     int         bpp;    // Bits per pixel
//     int         endian;
// }               t_img;

// typedef struct  s_draw_state
// {
//     int         last_x;
//     int         last_y;
//     int         repeat_width;
// }               t_draw_state;

// void draw_textured_rectangle(void *mlx, void *win, t_img *texture, t_draw_state *state, int x, int y, int width, int height)
// {
//     int tx;
//     int ty;
//     int color;
//     int bpp = texture->bpp / 8; // Assuming bpp is in bits

//     for (int i = 0; i < height; i++)
//     {
//         for (int j = 0; j < width; j++)
//         {
//             // Calculate the texture coordinates for horizontal repetition
//             tx = (j + state->last_x) % state->repeat_width;
//             tx = tx * texture->width / state->repeat_width;

//             // Scale the texture vertically to fit the rectangle height
//             ty = (i * texture->height) / height;

//             // Calculate the offset in the texture data
//             int offset = (ty * texture->width + tx) * bpp;

//             // Fetch the color from the texture
//             color = *((int *)(texture->addr + offset));
            
//             // Draw the pixel on the window
//             mlx_pixel_put(mlx, win, x + j, y + i, color);
//         }
//     }

//     // Update state with the new end position
//     state->last_x = (x + width) % state->repeat_width;
//     state->last_y = (y + height) % texture->height;
// }

// int main(void)
// {
//     void    *mlx;
//     void    *win;
//     t_img   texture;
//     t_draw_state state = {0, 0, 200}; // Initialize state with repeat width

//     mlx = mlx_init();
//     win = mlx_new_window(mlx, 800, 600, "Textured Rectangle");

//     // Load your texture image
//     texture.img_ptr = mlx_xpm_file_to_image(mlx, path, &texture.width, &texture.height);
//     if (!texture.img_ptr)
//     {
//         fprintf(stderr, "Error: Failed to load texture from '../texture/flag.xpm'\n");
//         mlx_destroy_window(mlx, win);
//         return (EXIT_FAILURE);
//     }
//     texture.addr = mlx_get_data_addr(texture.img_ptr, &texture.bpp, &texture.size_line, &texture.endian);

//     // Draw the first textured rectangle
//     draw_textured_rectangle(mlx, win, &texture, &state, 0, 0, 50, 250);

//     // Draw another textured rectangle, continuing from the last position
//     draw_textured_rectangle(mlx, win, &texture, &state, 400, 0, 300, 250); // Example with width less than repeat_width

//     mlx_loop(mlx);
//     return 0;
// }















int	main()
{
	int size_y = 10;
	int	size_x = 9;
	int	i = 0;
	int	j = 0;

	char **map = (char **)malloc(sizeof(char *) * size_y);
	i = 0;
	while (i < size_y)
	{
		map[i] = (char *)malloc(sizeof(char) * size_x);
		++i;
	}
	
	char	other_map[10][9] =
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

	i = 0;
	while (i < size_y)
	{
		j = 0;
		while (j < size_x)
		{
			map[i][j] = other_map[i][j];
			++j;
		}
		++i;
	}
	
	// i = 0;
	// while (i < size_y)
	// {
	// 	j = 0;
	// 	while (j < size_x)
	// 	{
	// 		printf("%c", map[i][j]);
	// 		++j;
	// 	}
	// 	printf("\n");
	// 	++i;
	// }

	t_GameData	data;
	t_Point2D	block_size;
	block_size.x = size_x;
	block_size.y = size_y;
	game_data_init(&data, map, block_size);

	data.key_pressed = 0;
	
	// i = 0;
	// while (i < size_y)
	// {
	// 	j = 0;
	// 	while (j < size_x)
	// 	{
	// 		t_Point2D	pos;
	// 		t_Point2D	size;
	// 		pos.x = j * data.minimap.block_size;
	// 		pos.y = i * data.minimap.block_size;
	// 		size.x = data.minimap.block_size;
	// 		size.y = data.minimap.block_size;
	// 		if (map[i][j] == '1')
	// 			draw_rectangle_filled(&data.minimap.image, pos, size, data.minimap.wall_color);
	// 		else if (map[i][j] == '0')
	// 			draw_rectangle_filled(&data.minimap.image, pos, size, data.minimap.floor_color);
	// 		++j;
	// 	}
	// 	++i;
	// }
	// draw_rectangle_filled(&data.minimap.image, data.player.pos, data.player.size, data.player.color);
	
	input_update_render(&data);
}