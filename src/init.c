/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaganay <avaganay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 14:15:26 by maujogue          #+#    #+#             */
/*   Updated: 2023/06/15 11:48:18 by avaganay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub.h"

void    init_cub(t_all *all)
{
    all->data = malloc(sizeof(t_data));
    all->mlx = mlx_init();
    if (!all->mlx)
        free_exit(all);
    all->mlx_win = mlx_new_window(all->mlx, 1920,
			1080, "cub3D");
    all->data->img = mlx_new_image(all->mlx, 1920, 1080);
    all->data->addr = mlx_get_data_addr(all->data->img, &all->data->bits_per_pixel, &all->data->line_length,
								&all->data->endian);
    // my_mlx_pixel_put(all->data, 5, 5, 0x00FF0000);
    // ft_mlx(all);
    check_keypress(all);
    draw_map(all);
    mlx_put_image_to_window(all->mlx, all->mlx_win, all->data->img, 0, 0);
    mlx_loop(all->mlx);
    // if (!all->mlx_win)
    //     free_exit(all);
}