/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaganay <avaganay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 15:42:27 by avaganay          #+#    #+#             */
/*   Updated: 2023/06/19 13:40:14 by avaganay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x > 1920 || y > 1080)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	draw_playeur(t_all *all, double i, double j)
{
	int	x;
	int	y;

	x = 0;
	while (x < SIZE_MINIMAP - 5)
	{
		y = 0;
		while (y < SIZE_MINIMAP - 5)
		{
			if (x > 15 && x < SIZE_MINIMAP - 15 && y > 15 && y < SIZE_MINIMAP - 15)
				my_mlx_pixel_put(all->data, x + (j * SIZE_MINIMAP) , y + (i * SIZE_MINIMAP), 0x00FF0000);
			y++;
		}
		x++;
	}
}

void	draw_cube(t_all *all, int i, int j, char c)
{
	int	x;
	int	y;

	x = 0;
	while (x < SIZE_MINIMAP - 5)
	{
		y = 0;
		while (y < SIZE_MINIMAP - 5)
		{
			if (c == '0')
				my_mlx_pixel_put(all->data, x + (j * SIZE_MINIMAP) , y + (i * SIZE_MINIMAP), 0x000000FF);
			else if (c == '1')
				my_mlx_pixel_put(all->data, x + (j * SIZE_MINIMAP) , y + (i * SIZE_MINIMAP), 0x0000FF00);
			else if (c != '0' && c != '1')
			{
				my_mlx_pixel_put(all->data, x + (j * SIZE_MINIMAP) , y + (i * SIZE_MINIMAP), 0x000000FF);
				// if (x > 15 && x < SIZE_MINIMAP - 15 && y > 15 && y < SIZE_MINIMAP - 15)
				// 	my_mlx_pixel_put(all->data, x + (j * SIZE_MINIMAP) , y + (i * SIZE_MINIMAP), 0x00FF0000);
			}
			y++;
		}
		x++;
	}
}

void	draw_map(t_all *all)
{
	int		i;
	int		j;

	i = 0;
	while (all->pars->map[i])
	{
		j = 0;
		while (all->pars->map[i][j])
		{
			if (all->pars->map[i][j] == '0')
				draw_cube(all, i , j, '0');
			else if (all->pars->map[i][j] == '1')
				draw_cube(all, i , j, '1');
            else if (ft_strchr("NWES", all->pars->map[i][j]))
				draw_cube(all, i , j, 'N');
			j++;
		}
		i++;
	}
	my_mlx_pixel_put(all->data, (int)all->ray->pos.x , (int)all->ray->pos.y, 0x00FF0000);
}