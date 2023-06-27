/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maujogue <maujogue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 17:24:14 by maujogue          #+#    #+#             */
/*   Updated: 2023/06/27 15:11:14 by maujogue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub.h"

void	init_raycasting(int i, t_all *all)
{
	all->ray.cameraX = 2 * i / (double)1920 - 1;
	all->ray.raydir.x = all->ray.delta_pos.y
		+ all->ray.plane.x * all->ray.cameraX;
	all->ray.raydir.y = all->ray.delta_pos.x
		+ all->ray.plane.y * all->ray.cameraX;
	all->ray.mapX = (int)all->ray.pos.x;
	all->ray.mapY = (int)all->ray.pos.y;
	all->ray.deltadist.x = sqrt(1
			+ (all->ray.raydir.y * all->ray.raydir.y)
			/ (all->ray.raydir.x * all->ray.raydir.x));
	all->ray.deltadist.y = sqrt(1
			+ (all->ray.raydir.x * all->ray.raydir.x)
			/ (all->ray.raydir.y * all->ray.raydir.y));
	all->ray.inWall = 0;
}

void	raydir_raycasting(t_all *all)
{
	if (all->ray.raydir.x < 0)
	{
		all->ray.stepX = -1;
		all->ray.sidedist.x = (all->ray.pos.x
				- all->ray.mapX) * all->ray.deltadist.x;
	}
	else
	{
		all->ray.stepX = 1;
		all->ray.sidedist.x = (all->ray.mapX
				+ 1.0 - all->ray.pos.x) * all->ray.deltadist.x;
	}
	if (all->ray.raydir.y < 0)
	{
		all->ray.stepY = -1;
		all->ray.sidedist.y = (all->ray.pos.y
				- all->ray.mapY) * all->ray.deltadist.y;
	}
	else
	{
		all->ray.stepY = 1;
		all->ray.sidedist.y = (all->ray.mapY
				+ 1.0 - all->ray.pos.y) * all->ray.deltadist.y;
	}
}

void	check_hit_wall(t_all *all)
{
	while (all->ray.inWall == 0)
	{
		if (all->ray.sidedist.x < all->ray.sidedist.y)
		{
			all->ray.sidedist.x += all->ray.deltadist.x;
			all->ray.mapX += all->ray.stepX;
			all->ray.sideWall = 0;
		}
		else
		{
			all->ray.sidedist.y += all->ray.deltadist.y;
			all->ray.mapY += all->ray.stepY;
			all->ray.sideWall = 1;
		}
		if (all->pars.map[all->ray.mapX][all->ray.mapY] == '1')
			all->ray.inWall = 1;
	}
}

void	draw_wall(t_all *all, int i)
{
	int	d;
	int	color;

	all->ray.drawStart = -all->ray.lineHeight / 2 + 1080 / 2;
	if (all->ray.drawStart < 0)
		all->ray.drawStart = 0;
	all->ray.drawEnd = all->ray.lineHeight / 2 + 1080 / 2;
	if (all->ray.drawEnd >= 1080)
		all->ray.drawEnd = 1080;
	d = 0;
	while (all->ray.drawStart > d)
		my_mlx_pixel_put(&(all->data), i, d++, all->pars.ceiling_color);
	color = 0x80808080;
	if (all->ray.sideWall == 1)
		color = 0x00A9A9A9;
	while (all->ray.drawStart < all->ray.drawEnd)
		my_mlx_pixel_put(&(all->data), i, all->ray.drawStart++, color);
	d = all->ray.drawEnd;
	while (d > 0 && d < 1080)
		my_mlx_pixel_put(&(all->data), i, d++, all->pars.floor_color);
}

int	raycasting(t_all *all)
{
	int	i;

	i = 0;
	(void)all;
	while (i < 1920)
	{
		init_raycasting(i, all);
		raydir_raycasting(all);
		check_hit_wall(all);
		if (all->ray.sideWall == 0)
			all->ray.perpWallDist = fabs((all->ray.mapX - all->ray.pos.x
						+ (1 - all->ray.stepX) / 2) / all->ray.raydir.x);
		else
			all->ray.perpWallDist = fabs((all->ray.mapY - all->ray.pos.y
						+ (1 - all->ray.stepY) / 2) / all->ray.raydir.y);
		all->ray.lineHeight = (int)(1080 / all->ray.perpWallDist);
		draw_wall(all, i);
		i++;
	}
	mlx_put_image_to_window(all->mlx, all->mlx_win, all->data.img, 0, 0);
	return (0);
}
