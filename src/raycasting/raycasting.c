/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaganay <avaganay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 14:56:12 by avaganay          #+#    #+#             */
/*   Updated: 2023/06/16 10:32:24 by avaganay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub.h"

double	ft_sqrt(double x)
{
	double	guess;
	double	epsilon;

	guess = 1.0;
	epsilon = 0.00001;
	while (guess * guess - x > epsilon || x - guess * guess > epsilon)
		guess = (guess + x / guess) / 2.0;
	return (guess);
}

int	raycasting(t_all *all)
{
	int	i;

	i = 0;
	// printf("%d\n", all->data->endian);
	// printf("%d\n", all->ray->mapX);
	printf("%f\n", all->ray->cameraX);
	while (i < 1920)
	{
      all->ray->cameraX = 2 * i / (double)1920 - 1;
      all->ray->raydir.x = all->ray->dir.x + all->ray->plane.x * all->ray->cameraX;
      all->ray->raydir.y = all->ray->dir.y + all->ray->plane.y * all->ray->cameraX;
      all->ray->mapX = (int)all->ray->pos.x;
      all->ray->mapY = (int)all->ray->pos.y;
      all->ray->deltadist.x = ft_sqrt(1 + (all->ray->raydir.y * all->ray->raydir.y) / (all->ray->raydir.y * all->ray->raydir.y));
      all->ray->deltadist.y = ft_sqrt(1 + (all->ray->raydir.x * all->ray->raydir.x) / (all->ray->raydir.y * all->ray->raydir.y));
		i++;
	}
	return (0);
}
