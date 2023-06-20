/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaganay <avaganay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 13:59:40 by avaganay          #+#    #+#             */
/*   Updated: 2023/06/19 14:00:39 by avaganay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub.h"

void	ft_draw_line(t_all *all)
{
	int x = (int)all->ray->pos.x * SIZE_MINIMAP;
	// printf("XXXXXXXXXXX: %d\n", x);
	int y = (int)all->ray->pos.y * SIZE_MINIMAP;
	// printf("YYYYYYYYYYYYYYY: %d\n", y);
	int x2 = all->ray->mapX * SIZE_MINIMAP;
	int y2 = all->ray->mapY * SIZE_MINIMAP;
	int dx = abs(x2 - x);
	int dy = abs(y2 - y);
	int sx = (x < x2) ? 1 : -1;
	int sy = (y < y2) ? 1 : -1;
	int err = dx - dy;

	while (1)
	{
		// printf("x: %d, y: %d\n", x , y);
		// printf("x2: %d, y2: %d\n", x , y);
		my_mlx_pixel_put(all->data, x, y, 0x00FF0000);
		if (x == x2 && y == y2)
			break;
		int e2 = 2 * err;
		if (e2 > -dy)
		{
			err -= dy;
			x += sx;
		}
		if (e2 < dx)
		{
			err += dx;
			y += sy;
		}
	}
}
