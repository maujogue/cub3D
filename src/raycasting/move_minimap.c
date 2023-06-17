/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaganay <avaganay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 13:10:45 by avaganay          #+#    #+#             */
/*   Updated: 2023/06/17 11:54:20 by avaganay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub.h"

void    move_nwes(t_all *all, char c)
{
    if (c == 'W')
        all->ray->pos.y -= 0.1;
    if (c == 'E')
        all->ray->pos.y += 0.1;
    if (c == 'S')
        all->ray->pos.x += 0.1;
    if (c == 'N')
        all->ray->pos.x -= 0.1;
    printf("x: %f\n", all->ray->pos.x);
    printf("y: %f\n", all->ray->pos.y);
    // all->pars->map[(int)all->ray->pos.x][(int)all->ray->pos.y] = 'N';
    // draw_map(all);
    my_mlx_pixel_put(all->data, all->ray->pos.x , all->ray->pos.y, 0x00FF0000);
}