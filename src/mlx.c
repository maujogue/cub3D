/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maujogue <maujogue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 15:33:07 by avaganay          #+#    #+#             */
/*   Updated: 2023/06/21 10:54:42 by maujogue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub.h"

void    ft_mlx(t_all *all)
{
    /////////////////////////fais 1 fois au debut
    mlx_put_image_to_window(all->mlx, all->mlx_win, all->data->img, 0, 0);
    mlx_hook(all->mlx_win, 17, 1L << 17, close_win, all);
    mlx_hook(all->mlx_win, 2, (1L << 0), ft_key, all);
    mlx_hook(all->mlx_win, 6, (1L << 6), ft_mouse, all);
    mlx_loop_hook(all->mlx, refresh, all);
    mlx_loop(all->mlx);
}