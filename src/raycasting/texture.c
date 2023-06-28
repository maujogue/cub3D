/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaganay <avaganay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 17:22:40 by avaganay          #+#    #+#             */
/*   Updated: 2023/06/28 13:25:10 by avaganay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub.h"

// void	resize(int** array, int newSize)
// {
// 	if (newSize <= 0) 
// 	{
// 		free(*array);
// 		*array = NULL;
// 		return ;
// 	}
// 	int* newArray = (int*)malloc(newSize * sizeof(int));
// 	if (*array != NULL)
// 	{
// 		memcpy(newArray, *array, newSize * sizeof(int));
// 		free(*array);
// 	}
// 	*array = newArray;
// }

void	texture(t_all *all, int x)
{
	int	y;

	// (void)x;
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
	// printf("Side %d\n", all->ray.sideWall);
	// printf("raydir x %f\n", all->ray.raydir.x);
	// else if (all->pars.map[all->ray.mapX][all->ray.mapY] == '0')
	// 	all->ray.texNum = 0;
	// all->ray.texNum = all->pars.map[all->ray.mapX][all->ray.mapY] - 1;
	// printf("mapx:%d\n", all->ray.mapX);
	// printf("NUM:%d\n", all->pars.map[all->ray.mapX][all->ray.mapY]);
	if (all->ray.sideWall == 0)
		all->ray.wallX = all->ray.pos.y + all->ray.perpWallDist * all->ray.raydir.y;
	else
		all->ray.wallX = all->ray.pos.x + all->ray.perpWallDist * all->ray.raydir.x;
	all->ray.wallX -= floor((all->ray.wallX));
	all->ray.texX = (int)(all->ray.wallX * (double)64);
	if (all->ray.sideWall == 0 && all->ray.raydir.x > 0)
		all->ray.texX = 64 - all->ray.texX - 1;
	if (all->ray.sideWall == 1 && all->ray.raydir.y < 0)
		all->ray.texX = 64 - all->ray.texX - 1;
	all->ray.texStep = 1.0 * 64 / all->ray.lineHeight;
	all->ray.texPos = (all->ray.drawStartTmp - 1080 / 2 + all->ray.lineHeight / 2) * all->ray.texStep;
	// printf("STARTTMP: %d\n", all->ray.drawStartTmp);
	// printf("START: %d\n", all->ray.drawStart);
	y = all->ray.drawStartTmp;
	while (y < all->ray.drawEnd)
	{
		// printf("ICI");
		// mlx_put_image_to_window(all->mlx, all->mlx_win, all->ray.texture[0].img, 500 , 500);
		if (y < 1080 && x < 1920)
		{
			all->ray.texY = (int)all->ray.texPos & (64 - 1);
			all->ray.texPos += all->ray.texStep;
			// printf("NUM:%d\n", all->ray.texNum);
			// if (all->ray.texNum > 3)
			// 	all->ray.texNum = rand()%3;
			all->data.addr2[y * all->data.line_length / 4 + x] = all->ray.texture[all->ray.texNum].addr2[all->ray.texY * 6 / 4 * all->ray.texX];
		}
		y++;
	}


}
