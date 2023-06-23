/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maujogue <maujogue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 12:00:30 by avaganay          #+#    #+#             */
/*   Updated: 2023/06/23 16:10:35 by maujogue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub.h"

int	refresh(t_all *all)
{
    move_player(all);
	mlx_destroy_image(all->mlx, all->data.img);
    all->data.img = mlx_new_image(all->mlx, 1920, 1080);
    all->data.addr = mlx_get_data_addr(all->data.img, \
    &all->data.bits_per_pixel, &all->data.line_length, &all->data.endian);
    // mlx_clear_window(all->mlx,all->mlx_win);
	draw_minimap(all);
	mlx_put_image_to_window(all->mlx, all->mlx_win, all->data.img, 0, 0);
	return (0);
}