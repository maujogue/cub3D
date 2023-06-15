/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaganay <avaganay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 15:33:07 by avaganay          #+#    #+#             */
/*   Updated: 2023/06/15 12:36:34 by avaganay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub.h"



void    ft_mlx(t_all *all)
{
    check_keypress(all);
    draw_map(all);
    mlx_put_image_to_window(all->mlx, all->mlx_win, all->data->img, 0, 0);
    mlx_loop(all->mlx);
}