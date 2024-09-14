/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_shape.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skedikia <skedikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 14:07:23 by skedikia          #+#    #+#             */
/*   Updated: 2024/09/14 14:07:45 by skedikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/draw_shape.h"

void	alt_mlx_pixel_put(t_image *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x > img->size.x || y < 0 || y > img->size.y)
	{
		printf("dog\n");
		return ;
	}
	if (x > WINDOW_WIDTH || y > WINDOW_HEIGHT)
		return ;
	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_rectangle_filled(t_image *img, t_point2d pos, t_point2d size,
		int color)
{
	int	i;
	int	j;

	if (!img)
		return ;
	i = 0;
	while (i < size.x)
	{
		if (pos.x + i < 0 || pos.x + i > img->size.x)
			break ;
		if (pos.x + i > WINDOW_WIDTH)
			break ;
		j = 0;
		while (j < size.y)
		{
			if (pos.y + j < 0 || pos.y + j > img->size.y)
				break ;
			if (pos.y + j > WINDOW_HEIGHT)
				break ;
			alt_mlx_pixel_put(img, pos.x + i, pos.y + j, color);
			j++;
		}
		i++;
	}
}
