/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maujogue <maujogue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 15:51:13 by maujogue          #+#    #+#             */
/*   Updated: 2023/06/23 18:36:01 by maujogue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub.h"

void	draw_angle(t_all *all, t_vector v1, t_vector v2, t_vector sign_diff)
{
	int	dx;
	int	dy;
	int	err;
	int	i;

	i = 0;
	dx = abs((int)v2.x - (int)v1.x);
	dy = abs((int)v2.y - (int)v1.y);
	err = (dx - dy);
	while (i < 50)
	{
		my_mlx_pixel_put(&(all->data), v1.x, v1.y, 0x000000FF);
		if (2 * err > -dy)
		{
			err -= dy;
			v1.x += sign_diff.x;
		}
		if (2 * err < dx)
		{
			err += dx;
			v1.y += sign_diff.y;
		}
		i++;
	}
}

void	draw_line(t_all *all)
{
	t_vector	start;
	t_vector	direction;
	t_vector	sign_diff;

	direction.x = (all->ray.p_pos.x + all->ray.delta_pos.x) * SIZE_MINIMAP;
	direction.y = (all->ray.p_pos.y + all->ray.delta_pos.y) * SIZE_MINIMAP;
	start.x = all->ray.p_pos.x * SIZE_MINIMAP;
	start.y = all->ray.p_pos.y * SIZE_MINIMAP;
	if (start.x < direction.x)
		sign_diff.x = 1;
	else
		sign_diff.x = -1;
	if (start.y < direction.y)
		sign_diff.y = 1;
	else
		sign_diff.y = -1;
	draw_angle(all, start, direction, sign_diff);
}

void	cast_rays(t_all *all)
{
	int			i;
	double		temp;
	t_vector	start;

	temp = all->ray.angle;
	start.x = cos(all->ray.angle);
	start.y = sin(all->ray.angle);
	i = 0;
	while (i < 100)
	{
		temp += (PI / (4 * 90)) * i;
		start.x = cos(temp);
		start.y = sin(temp);
		draw_line(all);
		i++;
	}
}