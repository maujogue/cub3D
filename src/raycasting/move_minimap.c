/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaganay <avaganay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 13:10:45 by avaganay          #+#    #+#             */
/*   Updated: 2023/06/19 10:50:39 by avaganay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub.h"

void    coor_to_index_minimap(t_all *all)
{
    all->ray->mapX = round(all->ray->pos.x);
    all->ray->mapY = round(all->ray->pos.y);
    printf("mapX : %dmapY : %d\n", all->ray->mapX, all->ray->mapY);
}

void    move_nwes(t_all *all, char c)
{
    coor_to_index_minimap(all);
    if (c == 'W')
    {
        printf("X%dY%d\n", (int)round(all->ray->pos.x), (int)round(all->ray->pos.y - 1));
        if (all->pars->map[all->ray->mapX][ all->ray->mapY - 1] != '1')
            all->ray->pos.y -= 0.1;
    }
    if (c == 'E')
    {
        printf("X%dY%d\n", (int)round(all->ray->pos.x), (int)round(all->ray->pos.y - 1));
        if (all->pars->map[all->ray->mapX][ all->ray->mapY + 1] != '1')
            all->ray->pos.y += 0.1;
    }
    if (c == 'S')
    {
        printf("X%dY%d\n", (int)round(all->ray->pos.x), (int)round(all->ray->pos.y - 1));
        if (all->pars->map[all->ray->mapX + 1][ all->ray->mapY] != '1')
            all->ray->pos.x += 0.1;
    }
    if (c == 'N')
    {
        printf("X%dY%d\n", (int)round(all->ray->pos.x), (int)round(all->ray->pos.y - 1));
        if (all->pars->map[all->ray->mapX - 1][ all->ray->mapY] != '1')
            all->ray->pos.x -= 0.1;
    }
    printf("x: %f\n", all->ray->pos.x);
    printf("y: %f\n", all->ray->pos.y);
    // all->pars->map[(int)all->ray->pos.x][(int)all->ray->pos.y] = 'N';
    // draw_map(all);
    my_mlx_pixel_put(all->data, all->ray->pos.x , all->ray->pos.y, 0x00FF0000);
}