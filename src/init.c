/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maujogue <maujogue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 14:15:26 by maujogue          #+#    #+#             */
/*   Updated: 2023/06/14 14:21:37 by maujogue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub.h"

void    init_cub(t_all *all)
{
    all->mlx = mlx_init();
    if (!all->mlx)
        free_exit(all);
    all->mlx_win = 	all->mlx_win = mlx_new_window(all->mlx, 1920,
			1080, "cub3D");
    if (!all->mlx_win)
        free_exit(all);
}