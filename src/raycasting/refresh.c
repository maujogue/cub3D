/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaganay <avaganay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 12:00:30 by avaganay          #+#    #+#             */
/*   Updated: 2023/06/17 13:40:34 by avaganay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub.h"

void	refresh(t_all *all)
{
	mlx_destroy_image(all->mlx, all->data->img);
    all->data->img = mlx_new_image(all->mlx, 1920, 1080);
    all->data->addr = mlx_get_data_addr(all->data->img, \
    &all->data->bits_per_pixel, &all->data->line_length, &all->data->endian);
    mlx_clear_window(all->mlx,all->mlx_win);
	mlx_put_image_to_window(all->mlx, all->mlx_win, all->data->img, 0, 0);
	draw_map(all);
	draw_playeur(all,all->ray->pos.x, all->ray->pos.y);
	raycasting(all);
}