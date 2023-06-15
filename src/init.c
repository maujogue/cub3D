/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maujogue <maujogue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 14:15:26 by maujogue          #+#    #+#             */
/*   Updated: 2023/06/15 13:55:14 by maujogue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub.h"

void    init_cub(t_all *all, char *map)
{
    all->mlx = mlx_init();
    if (!all->mlx)
        free_exit(all, 1, "Malloc Error\n");
    all->mlx_win = mlx_new_window(all->mlx, 1920,
			1080, "cub3D");
    if (!all->mlx_win)
        free_exit(all, 1, "Malloc Error\n");
    parsing(all, map);
    check_map(all);
}