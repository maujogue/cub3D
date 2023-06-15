/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaganay <avaganay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 14:56:12 by avaganay          #+#    #+#             */
/*   Updated: 2023/06/15 16:23:17 by avaganay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub.h"

int	raycasting(t_all *all)
{
	(void)all;
  int i;

  i = 0;
  while (i < 5)
  {
	// for(int x = 0; x < w; x++)
  //   {
      // all->ray->cameraX = 2 * i / (double)5 - 1;
      // all->ray->raydir->x = all->ray->dir->x + all->ray->plane->x * all->ray->cameraX;
      // all->ray->raydir->y = all->ray->dir->y + all->ray->plane->y * all->ray->cameraX;
      // int mapX = (int)all->ray->pos->x;
      // int mapY = (int)all->ray->pos->y;

      //length of ray from one x or y-side to next x or y-side
      //these are derived as:
      //deltaDistX = sqrt(1 + (rayDirY * rayDirY) / (rayDirX * rayDirX))
      //deltaDistY = sqrt(1 + (rayDirX * rayDirX) / (rayDirY * rayDirY))
      //which can be simplified to abs(|rayDir| / rayDirX) and abs(|rayDir| / rayDirY)
      //where |rayDir| is the length of the vector (rayDirX, rayDirY). Its length,
      //unlike (dirX, dirY) is not 1, however this does not matter, only the
      //ratio between deltaDistX and deltaDistY matters, due to the way the DDA
      //stepping further below works. So the values can be computed as below.
      // Division through zero is prevented, even though technically that's not
      // needed in C++ with IEEE 754 floating point values.

      // double deltaDistX = (all->ray->raydir->x == 0) ? 1e30 : std::abs(1 / rayDirX);
      // double deltaDistY = (all->ray->raydir->y == 0) ? 1e30 : std::abs(1 / rayDirY);
    i++;
  }
	return (0);
}
