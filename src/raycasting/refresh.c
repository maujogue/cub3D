/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maujogue <maujogue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 12:00:30 by avaganay          #+#    #+#             */
/*   Updated: 2023/09/06 13:24:07 by maujogue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub.h"

int	refresh(t_all *all)
{
	mlx_destroy_image(all->mlx, all->data.img);
	move_player(all);
	all->data.img = mlx_new_image(all->mlx, 1920, 1080);
	if (!all->data.img)
		free_exit(all, 1, "Malloc Error\n");
	all->data.addr = mlx_get_data_addr(all->data.img, \
		&all->data.bits_per_pixel, &all->data.line_length, &all->data.endian);
	if (!all->data.addr)
		free_exit(all, 1, "Malloc Error\n");
	raycasting(all);
	draw_minimap(all);
	draw_player(all, all->ray.angle, SIZE_MINIMAP * RADIUS, 15);
	mlx_put_image_to_window(all->mlx,
		all->mlx_win, all->data.img, 0, 0);
	return (0);
}
