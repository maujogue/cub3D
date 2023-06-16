/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaganay <avaganay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 14:15:26 by maujogue          #+#    #+#             */
/*   Updated: 2023/06/16 12:54:19 by avaganay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub.h"

void    init_cub(t_all *all, char *map)
{
    all->data = malloc(sizeof(t_data));
    all->mlx = mlx_init();
    if (!all->mlx)
        free_exit(all, 1, "Malloc Error\n");
    all->mlx_win = mlx_new_window(all->mlx, 1920,
			1080, "cub3D");
    if (!all->mlx_win)
        free_exit(all, 1, "Malloc Error\n");
    all->data->img = mlx_new_image(all->mlx, 1920, 1080);
    all->data->addr = mlx_get_data_addr(all->data->img, &all->data->bits_per_pixel, &all->data->line_length,
								&all->data->endian);
    parsing(all, map);
    check_map(all);
}

void	init_ray(t_all *all)
{
	all->ray = malloc(sizeof(t_ray));
	// all->ray->pos = malloc(sizeof(t_vector));
	// all->ray->dir = malloc(sizeof(t_vector));
	// all->ray->plane = malloc(sizeof(t_vector));
	find_pos_playeur(all);
	all->ray->dir.x = -1;
	all->ray->dir.y = 0;
	all->ray->plane.x = 0;
	all->ray->plane.y = 0.66;
	all->ray->time = 0;
	all->ray->oldtime = 0;
	all->ray->cameraX = 0;
	// all->ray->raydir = malloc(sizeof(t_vector));
	all->ray->raydir.x = 0;
	all->ray->raydir.y = 0;
	// all->ray->sidedist = malloc(sizeof(t_vector));
	// all->ray->deltadist = malloc(sizeof(t_vector));
	all->ray->mapX = 0;
	all->ray->inWall = 0;
}
