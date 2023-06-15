/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaganay <avaganay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 15:33:07 by avaganay          #+#    #+#             */
/*   Updated: 2023/06/15 13:30:17 by avaganay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub.h"

void    ft_mlx(t_all *all)
{
    draw_map(all);
    mlx_put_image_to_window(all->mlx, all->mlx_win, all->data->img, 0, 0);
    mlx_hook(all->mlx_win, 17, 1L << 17, close_win, all);
    mlx_hook(all->mlx_win, 2, (1L << 0), ft_key, &all);
    mlx_loop_hook(all->mlx, raycasting, &all);
    mlx_loop(all->mlx);
}