/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maujogue <maujogue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 14:15:26 by maujogue          #+#    #+#             */
/*   Updated: 2023/06/26 17:17:25 by maujogue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub.h"

void	init_cub(t_all *all, char *map)
{
	all->mlx = NULL;
	all->mlx_win = NULL;
	parsing(all, map);
	check_map(all);
	all->data.img = NULL;
	all->data.addr = NULL;
	all->mlx = mlx_init();
	if (!all->mlx)
		free_exit(all, 1, "Malloc Error\n");
	all->mlx_win = mlx_new_window(all->mlx, 1920,
			1080, "cub3D");
	if (!all->mlx_win)
		free_exit(all, 1, "Malloc Error\n");
	all->data.img = mlx_new_image(all->mlx, 1920, 1080);
	if (!all->data.img)
		free_exit(all, 1, "Malloc Error\n");
	all->data.addr = mlx_get_data_addr(all->data.img,
			&all->data.bits_per_pixel, &all->data.line_length, &all->data.endian);
	if (!all->data.addr)
		free_exit(all, 1, "Malloc Error\n");

}

void	init_angle(t_all *all)
{
	int	x;
	int	y;

	x = all->ray.p_pos.x;
	y = all->ray.p_pos.y;
	if (all->pars.map[y][x] == 'N')
		all->ray.angle = -PI / 2;
	if (all->pars.map[y][x] == 'S')
		all->ray.angle = PI / 2;
	if (all->pars.map[y][x] == 'E')
		all->ray.angle = 0;
	if (all->pars.map[y][x] == 'W')
		all->ray.angle = 1;
	all->ray.delta_pos.x = cos(all->ray.angle);
	all->ray.delta_pos.y = sin(all->ray.angle);
}

void	init_ray(t_all *all)
{
	set_player_position(all);
	all->keys[0] = 1;
	all->keys[1] = 1;
	all->keys[2] = 1;
	all->keys[3] = 1;
	all->keys[4] = 1;
	all->keys[5] = 1;
	init_angle(all);

	all->ray.plane.x = sin(all->ray.angle + PI / 2);
	all->ray.plane.y = cos(all->ray.angle + PI / 2);
	all->ray.time = 0;
	all->ray.oldtime = 0;
	all->ray.cameraX = 0;
	all->ray.raydir.x = 0;
	all->ray.raydir.y = 0;
	all->ray.mapX = 0;
	all->ray.inWall = 0;
	all->ray.rotSpeed = 0.05;
	all->ray.moveSpeed = 0.1;
}

