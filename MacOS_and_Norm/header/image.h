/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <yuhayrap@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 14:51:20 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/09/14 14:57:15 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGE_H
# define IMAGE_H

# ifdef __linux__
#  define UNAME "Linux"
#  include "../mlx_linux/mlx.h"
# else
#  define UNAME "Darwin"
#  include "../mlx_mac/mlx.h"
# endif

# include "utils.h"

typedef struct imagedata
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	t_point2d	pos;
	t_point2d	size;
}				t_image;

t_statuscode	image_init(t_image *image, void *mlx, t_point2d pos,
					t_point2d size);
void			image_delete(t_image *img, void *mlx);

#endif