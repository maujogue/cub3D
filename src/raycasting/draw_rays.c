/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maujogue <maujogue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 15:51:13 by maujogue          #+#    #+#             */
/*   Updated: 2023/06/26 14:59:06 by maujogue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub.h"

int	has_touched_wall(t_all *all, t_vector v1)
{
	int	x;
	int	y;

	x = floor(v1.x / SIZE_MINIMAP);
	y = floor(v1.y / SIZE_MINIMAP);
	if (all->pars.map[y][x] == '1' || x == 0 || y == 0 || x == WIDTH - 2 || y == HEIGHT - 2)
		return (0);
	return (1);
}

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
	while (i < 50)//has_touched_wall(all, v1) == 1)
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

void	draw_line(t_all *all, t_vector direction)
{
	t_vector	start;
	t_vector	sign_diff;

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
	t_vector	direction;

	temp = all->ray.angle - PI / 16;
	i = 0;
	while (i < 1920)
	{
		temp += (PI / 1920 * i) / (4 * 1920);
		direction.x = (all->ray.p_pos.x + cos(temp)) * SIZE_MINIMAP;
		direction.y = (all->ray.p_pos.y + sin(temp)) * SIZE_MINIMAP;
		start.x = cos(temp);
		start.y = sin(temp);
		draw_line(all, direction);
		i++;
	}
}