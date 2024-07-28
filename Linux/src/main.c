#include "../header/the_game.h"

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