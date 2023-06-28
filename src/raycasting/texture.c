/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maujogue <maujogue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 17:22:40 by avaganay          #+#    #+#             */
/*   Updated: 2023/06/28 15:28:37 by maujogue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub.h"

void	choose_texnum(t_all *all)
{
	if (all->ray.sideWall == 0 && all->ray.raydir.x >= 0)
		all->ray.texNum = 0;
	else if (all->ray.sideWall == 0 && all->ray.raydir.x < 0)
		all->ray.texNum = 1;
	else if (all->ray.sideWall == 1 && all->ray.raydir.y >= 0)
		all->ray.texNum = 2;
	else if (all->ray.sideWall == 1 && all->ray.raydir.y < 0)
		all->ray.texNum = 3;
	else
		all->ray.texNum = 0;
}

void	init_var_texture(t_all *all)
{
	if (all->ray.sideWall == 0)
		all->ray.wallX = all->ray.pos.y + all->ray.perpWallDist
			* all->ray.raydir.y;
	else
		all->ray.wallX = all->ray.pos.x + all->ray.perpWallDist
			* all->ray.raydir.x;
	all->ray.wallX -= floor((all->ray.wallX));
	all->ray.texX = (int)(all->ray.wallX * (double)64);
	if (all->ray.sideWall == 0 && all->ray.raydir.x > 0)
		all->ray.texX = 64 - all->ray.texX - 1;
	if (all->ray.sideWall == 1 && all->ray.raydir.y < 0)
		all->ray.texX = 64 - all->ray.texX - 1;
	all->ray.texStep = 1.0 * 64 / all->ray.lineHeight;
	all->ray.texPos = (all->ray.drawStartTmp - 1080 / 2
			+ all->ray.lineHeight / 2) * all->ray.texStep;
}

void	texture(t_all *all, int x)
{
	int	y;

	choose_texnum(all);
	init_var_texture(all);
	y = all->ray.drawStartTmp;
	while (y < all->ray.drawEnd)
	{
		if (y < 1080 && x < 1920)
		{
			all->ray.texY = (int)all->ray.texPos & (64 - 1);
			all->ray.texPos += all->ray.texStep;
			// printf("NUM:%d\n", all->ray.texNum);
			// printf("%d\n", all->ray.texture[all->ray.texNum].line_length);
			all->data.addr2[y * all->data.line_length / 4 + x] = \
all->ray.texture[all->ray.texNum].addr2[all->ray.texY * 8 / 4 * all->ray.texX];
			//all->ray.texture[all->ray.texNum].line_length
		}
		y++;
	}
}
