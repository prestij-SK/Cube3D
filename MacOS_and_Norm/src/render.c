/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <yuhayrap@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 14:20:32 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/09/14 14:28:30 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/the_game.h"

void	render_image(t_gamedata *data, t_image *image)
{
	if (!data || !image)
		return ;
	mlx_put_image_to_window(data->mlx, data->mlx_window, image->img,
		image->pos.x, image->pos.y);
}

void	render_image_pos(t_gamedata *data, t_image *image, int x, int y)
{
	if (!data || !image)
		return ;
	mlx_put_image_to_window(data->mlx, data->mlx_window, image->img, x, y);
}

static void	gun_animation(t_gamedata *data)
{
	size_t		current_time;
	long long	elapsed_time;
	int			frame;

	if (!data)
		return ;
	current_time = get_time();
	elapsed_time = current_time - data->anim_start_time;
	if (data->anim_start == B_TRUE)
	{
		frame = (elapsed_time / GUN_SWITCH_FRAME_TIME) % GUN_TEXTURES_COUNT;
		render_image_pos(data, &data->gun[frame], (WINDOW_WIDTH / 2)
			- (data->gun[frame].size.x / 2), WINDOW_HEIGHT
			- data->gun[frame].size.y);
		if (frame + 1 == GUN_TEXTURES_COUNT)
		{
			data->anim_start = B_FALSE;
			data->input.mouse_left = B_FALSE;
		}
	}
}

void	render(t_gamedata *data)
{
	if (!data)
		return ;
	fp_view_draw(&data->view);
	if (data->minimap.map_draw_flag == B_TRUE)
	{
		minimap_draw_origin(&data->minimap);
		player_on_minimap_draw_origin(&data->minimap.origin_image,
			&data->player);
	}
	else
	{
		minimap_draw_small(&data->minimap);
		player_on_minimap_draw_small(&data->minimap.small_image, &data->player);
	}
	ray_casting(data);
	render_image(data, &data->view.image);
	if (data->minimap.map_draw_flag == B_TRUE)
		render_image(data, &data->minimap.origin_image);
	else
		render_image(data, &data->minimap.small_image);
	if (data->anim_start == B_TRUE)
		gun_animation(data);
	else
		render_image_pos(data, &data->gun[0], (WINDOW_WIDTH / 2)
			- (data->gun[0].size.x / 2), WINDOW_HEIGHT - data->gun[0].size.y);
}
