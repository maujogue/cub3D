/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaganay <avaganay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 14:56:12 by avaganay          #+#    #+#             */
/*   Updated: 2023/06/19 14:22:50 by avaganay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub.h"

// double	ft_sqrt(double x)
// {
// 	double	guess;
// 	double	epsilon;

// 	guess = 1.0;
// 	epsilon = 0.00001;
// 	while (guess * guess - x > epsilon || x - guess * guess > epsilon)
// 		guess = (guess + x / guess) / 2.0;
// 	return (guess);
// }

void	ft_verLine(int x, t_all *all, int drawEnd, int color)
{
	// printf("%d\n", x);
	printf("Verline start: %d, end :%d\n", all->ray->drawStart, drawEnd);
	while (all->ray->drawStart < drawEnd)
	{
		// while (x < 1920)
		my_mlx_pixel_put(all->data, x, all->ray->drawStart, color);
		all->ray->drawStart++;
	}
}

int	raycasting(t_all *all)
{
	int	i;

	i = 0;
	(void)all;
	while (i < 1920)
	{
		all->ray->cameraX = 2 * i / (double)1920 - 1;
		all->ray->raydir.x = all->ray->dir.x
			+ all->ray->plane.x * all->ray->cameraX;
		all->ray->raydir.y = all->ray->dir.y
			+ all->ray->plane.y * all->ray->cameraX;
		all->ray->mapX = (int)all->ray->pos.x;
		all->ray->mapY = (int)all->ray->pos.y;
		all->ray->deltadist.x = sqrt(1
				+ (all->ray->raydir.y * all->ray->raydir.y)
				/ (all->ray->raydir.x * all->ray->raydir.x));
		all->ray->deltadist.y = sqrt(1
				+ (all->ray->raydir.x * all->ray->raydir.x)
				/ (all->ray->raydir.y * all->ray->raydir.y));
		all->ray->inWall = 0;
		// printf("Raydir x: %f\n", all->ray->raydir.x);
		// printf("Raydir y: %f\n", all->ray->raydir.y);
		// printf("%d\n", all->ray->mapX);
		// printf("%d\n", all->ray->mapY);
		// printf("A%f\n", all->ray->pos.x);
   		// printf("B%f\n", all->ray->pos.y);
		// my_mlx_pixel_put(all->data, (int)all->ray->pos.x , (int)all->ray->pos.y, 0x000000FF);
		if (all->ray->raydir.x < 0)
		{
			all->ray->stepX = -1;
			all->ray->sidedist.x = (all->ray->pos.x
					- all->ray->mapX) * all->ray->deltadist.x;
		}
		else
		{
			all->ray->stepX = 1;
			all->ray->sidedist.x = (all->ray->mapX
					+ 1.0 - all->ray->pos.x) * all->ray->deltadist.x;
		}
		if (all->ray->raydir.y < 0)
		{
			all->ray->stepY = -1;
			all->ray->sidedist.y = (all->ray->pos.y
					- all->ray->mapY) * all->ray->deltadist.y;
		}
		else
		{
			all->ray->stepY = 1;
			all->ray->sidedist.y = (all->ray->mapY
					+ 1.0 - all->ray->pos.y) * all->ray->deltadist.y;
		}
		while (all->ray->inWall == 0)
		{
			if (all->ray->sidedist.x < all->ray->sidedist.y)
			{
				all->ray->sidedist.x += all->ray->deltadist.x;
				all->ray->mapX += all->ray->stepX;
				all->ray->sideWall = 0;
			}
			else
			{
				all->ray->sidedist.y += all->ray->deltadist.y;
				all->ray->mapY += all->ray->stepY;
				all->ray->sideWall = 1;
			}
			if (all->pars->map[all->ray->mapX][all->ray->mapY] > 0)
			{
				// printf("TOUCHEEEEEE mapx%d, mapy%d\n",all->ray->mapX, all->ray->mapY);
				all->ray->inWall = 1;
			}
		}
		if(all->ray->sideWall == 0)
			all->ray->perpWallDist = (all->ray->sidedist.x - all->ray->deltadist.x);
		else
			all->ray->perpWallDist = (all->ray->sidedist.y - all->ray->deltadist.y);
		all->ray->lineHeight = (int)(1080 / all->ray->perpWallDist);
		all->ray->drawStart = -all->ray->lineHeight / 2 + 1080 / 2;
		if(all->ray->drawStart < 0)
			all->ray->drawStart = 0;
		all->ray->drawEnd = all->ray->lineHeight / 2 + 1080 / 2;
		if(all->ray->drawEnd >= 1080)
			all->ray->drawEnd = 1080;
		// ft_verLine(i, all, all->ray->drawEnd, 0x00FF0000);
		// printf("x  = %d start %d end %d \n", i, all->ray->drawStart, all->ray->drawEnd);
		int	d;
		d = 0;
		while (all->ray->drawStart > d)
			my_mlx_pixel_put(all->data, i, d++, 0x000000FF);
		while (all->ray->drawStart < all->ray->drawEnd)
			my_mlx_pixel_put(all->data, i, all->ray->drawStart++, 0x80808080);
		d = all->ray->drawEnd;
		while (d > 0 && d < 1080)
			my_mlx_pixel_put(all->data, i, d++, 0x000000FF);
		ft_draw_line(all);
		// printf("%f %f\n", all->ray->pos.x, all->ray->pos.y);
		i++;
	}
	// mlx_destroy_image(all->mlx, all->data->img);
	// all->data->img = mlx_new_image(all->mlx, 1920, 1080);
	mlx_put_image_to_window(all->mlx, all->mlx_win, all->data->img, 0, 0);
	draw_map(all);
	draw_playeur(all,all->ray->pos.x, all->ray->pos.y);
	// refresh(all);
	return (0);
}

