/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maujogue <maujogue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 15:42:27 by avaganay          #+#    #+#             */
/*   Updated: 2023/09/05 12:44:53 by maujogue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x > 1920 || y > 1080 || x < 0 || y < 0)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *) dst = color;
}

void	draw_square(t_all *all, t_vector start, int len, int color)
{
	double	i;
	double	j;

	i = 0;
	j = 0;
	while (i < len)
	{
		j = 0;
		while (j < len)
		{
			my_mlx_pixel_put(&(all->data), start.x + i, start.y + j, color);
			j++;
		}
		i++;
	}
}

void	draw_minimap(t_all *all)
{
	t_vector	start;
	int			x;
	int			y;

	y = all->ray.p_pos.y - RADIUS;
	if (y < 0)
		y = 0;
	while (y < all->ray.p_pos.y + RADIUS && all->pars.map[y])
	{
		x = all->ray.p_pos.x - RADIUS;
		if (x < 0)
			x = 0;
		while (x < (int)ft_strlen(all->pars.map[y])
			&& x < all->ray.p_pos.x + RADIUS && all->pars.map[y][x])
		{
			start.x = (x - all->ray.p_pos.x + RADIUS) * SIZE_MINIMAP;
			start.y = (y - all->ray.p_pos.y + RADIUS) * SIZE_MINIMAP;
			if (ft_strchr("1 ", all->pars.map[y][x]))
				draw_square(all, start, SIZE_MINIMAP, 0xba3235);
			if (ft_strchr("0NSEW", all->pars.map[y][x]))
				draw_square(all, start, SIZE_MINIMAP, 0xffffff);
			x++;
		}
		y++;
	}
}
