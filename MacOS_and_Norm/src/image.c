/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <yuhayrap@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 14:18:54 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/09/14 14:19:03 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/image.h"

void	image_delete(t_image *img, void *mlx)
{
	if (!img || !mlx)
		return ;
	if (!img->img)
		return ;
	mlx_destroy_image(mlx, img->img);
}

t_statuscode	image_init(t_image *image, void *mlx, t_point2d pos,
		t_point2d size)
{
	if (!image || !mlx)
		return (NULL_POINTER_ERROR);
	image->img = mlx_new_image(mlx, size.x, size.y);
	if (!image->img)
		return (IMAGE_ERROR);
	image->addr = mlx_get_data_addr(image->img, &image->bits_per_pixel,
			&image->line_length, &image->endian);
	if (!image->addr)
		return (IMAGE_ERROR);
	image->pos.x = pos.x;
	image->pos.y = pos.y;
	image->size.x = size.x;
	image->size.y = size.y;
	return (SUCCESS_EXIT);
}
