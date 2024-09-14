/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init_norm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skedikia <skedikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 14:10:50 by skedikia          #+#    #+#             */
/*   Updated: 2024/09/14 14:11:24 by skedikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/the_game.h"

static void	game_nullify_pointers_norm(t_gamedata *data)
{
	data->gun[0].img = NULL;
	data->gun[0].addr = NULL;
	data->gun[1].img = NULL;
	data->gun[1].addr = NULL;
	data->gun[2].img = NULL;
	data->gun[2].addr = NULL;
	data->gun[3].img = NULL;
	data->gun[3].addr = NULL;
	data->gun[4].img = NULL;
	data->gun[4].addr = NULL;
}

void	game_nullify_pointers(t_gamedata *data)
{
	if (!data)
		return ;
	data->mlx = NULL;
	data->mlx_window = NULL;
	data->tex_p = NULL;
	data->minimap.map = NULL;
	data->minimap.small_image.img = NULL;
	data->minimap.small_image.addr = NULL;
	data->minimap.origin_image.img = NULL;
	data->minimap.origin_image.addr = NULL;
	data->view.image.img = NULL;
	data->view.image.addr = NULL;
	data->north_wall.img = NULL;
	data->north_wall.addr = NULL;
	data->south_wall.img = NULL;
	data->south_wall.addr = NULL;
	data->west_wall.img = NULL;
	data->west_wall.addr = NULL;
	data->east_wall.img = NULL;
	data->east_wall.addr = NULL;
	data->door_tex.img = NULL;
	data->door_tex.addr = NULL;
	game_nullify_pointers_norm(data);
}
