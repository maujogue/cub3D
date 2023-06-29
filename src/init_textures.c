/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maujogue <maujogue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 11:31:36 by maujogue          #+#    #+#             */
/*   Updated: 2023/06/29 11:33:23 by maujogue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub.h"

void	init_textures_east_west(t_all *all)
{
	all->ray.texture[2].img = mlx_xpm_file_to_image(all->mlx, \
		"./assets/xpm/wall2.xpm", &(all->ray.texture[2].pix_height), \
		&(all->ray.texture[2].pix_height));
	all->ray.texture[2].addr2 = \
		(int *)mlx_get_data_addr(all->ray.texture[2].img, \
		&all->ray.texture[2].bits_per_pixel, &all->ray.texture[2].line_length, \
		&all->ray.texture[2].endian);
	all->ray.texture[3].img = mlx_xpm_file_to_image(all->mlx, \
		"./assets/xpm/wall.xpm", &(all->ray.texture[3].pix_height), \
		&(all->ray.texture[3].pix_height));
	all->ray.texture[3].addr2 = \
		(int *)mlx_get_data_addr(all->ray.texture[3].img, \
		&all->ray.texture[3].bits_per_pixel, &all->ray.texture[3].line_length, \
		&all->ray.texture[3].endian);
}

void	init_textures(t_all *all)
{
	all->ray.texture[0].img = mlx_xpm_file_to_image(all->mlx, \
	"./assets/xpm/wall1.xpm", &(all->ray.texture[0].pix_height), \
	&(all->ray.texture[0].pix_height));
	all->ray.texture[0].addr2 = \
		(int *)mlx_get_data_addr(all->ray.texture[0].img, \
		&all->ray.texture[0].bits_per_pixel, &all->ray.texture[0].line_length, \
		&all->ray.texture[0].endian);
	all->ray.texture[1].img = mlx_xpm_file_to_image(all->mlx, \
		"./assets/xpm/floor2.xpm", &(all->ray.texture[1].pix_height), \
		&(all->ray.texture[1].pix_height));
	all->ray.texture[1].addr2 = \
		(int *)mlx_get_data_addr(all->ray.texture[1].img, \
		&all->ray.texture[1].bits_per_pixel, &all->ray.texture[1].line_length, \
		&all->ray.texture[1].endian);
	init_textures_east_west(all);
}
