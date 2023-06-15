/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaganay <avaganay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 15:42:27 by avaganay          #+#    #+#             */
/*   Updated: 2023/06/15 10:51:11 by avaganay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}


void	draw_map(t_all *all,char **map)
{
	int		i;
	int		j;

	(void)all;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			// if (map[i][j] == '0')
			// 	my_mlx_pixel_put(all->data, i, j, 0x000000FF);
			// if (map[i][j] == '1')
			// 	my_mlx_pixel_put(all->data, i, j, 0x0000FF00);
            // if (map[i][j] == 'N')
            //     my_mlx_pixel_put(all->data, i, j, 0x00FF0000);
			j++;
		}
		i++;
	}
}