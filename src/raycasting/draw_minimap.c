/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maujogue <maujogue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 15:42:27 by avaganay          #+#    #+#             */
/*   Updated: 2023/06/26 12:59:58 by maujogue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x > 1920 || y > 1080)
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
	int			x;
	int			y;
	int			len;
	t_vector	start;

	len = SIZE_MINIMAP;
	y = 0;
	while (all->pars.map[y])
	{
		x = 0;
		while (all->pars.map[y][x])
		{
			start.x = x * len;
			start.y = y * len;
			if (all->pars.map[y][x] == '1')
				draw_square(all, start, len - 1, 0x00FF0000);
			else if (ft_strchr("0NSEW", all->pars.map[y][x]))
				draw_square(all, start, len - 1, 0x0000FF00);
			x++;
		}
		y++;
	}
	start.x = all->ray.p_pos.x * len;
	start.y = all->ray.p_pos.y * len;
	draw_square(all, start, 10, 0x000000FF);
}

// void draw_minimap(t_all *all)
// {
// 	double x;
// 	double y;
// 	double len;
// 	double radius = 5;
//  	t_vector start;

// 	len = SIZE_MINIMAP;
// 	y = all->ray.p_pos.y - radius;
// 	if (y < 0)
// 		y = 0;
// 	while (y < all->ray.p_pos.y + radius && all->pars.map[(int)y])
// 	{
// 		x = all->ray.p_pos.x - radius;
// 		if (x < 0)
// 			x = 0;
// 		while (x < all->ray.p_pos.x + radius && all->pars.map[(int)y][(int)x])
// 		{
// 			start.x = (x - all->ray.p_pos.x + radius) * len;
// 			start.y = (y - all->ray.p_pos.y + radius) * len;
// 			if (all->pars.map[(int)y][(int)x] == '1')
// 				draw_square(all, start, len - 1, 0x00FF0000);
// 			else if (ft_strchr("0NSEW", all->pars.map[(int)y][(int)x]))
// 				draw_square(all, start, len - 1, 0x0000FF00);
// 			x++;
// 		}
// 		y++;
// 	}
// 	start.x = radius * len;
// 	start.y = radius * len;
// 	draw_square(all, start, 10, 0x000000FF);
// }
