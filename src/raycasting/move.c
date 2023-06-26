/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maujogue <maujogue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 12:06:42 by maujogue          #+#    #+#             */
/*   Updated: 2023/06/26 15:32:47 by maujogue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub.h"

void	move_up_down(t_all *all, double move_speed)
{
	int	x;
	int	y;

	x = floor(all->ray.p_pos.x + cos(all->ray.angle) / move_speed);
	y = floor(all->ray.p_pos.y + sin(all->ray.angle) / move_speed);
	if (all->keys[0] == 0 && all->pars.map[y][x] != '1')
	{
		all->ray.p_pos.x += cos(all->ray.angle) / move_speed;
		all->ray.p_pos.y += sin(all->ray.angle) / move_speed;
		all->ray.pos.y = all->ray.p_pos.x;
		all->ray.pos.x = all->ray.p_pos.y;
	}
	x = floor(all->ray.p_pos.x - cos(all->ray.angle) / move_speed);
	y = floor(all->ray.p_pos.y - sin(all->ray.angle) / move_speed);
	if (all->keys[1] == 0 && all->pars.map[y][x] != '1')
	{
		all->ray.p_pos.x -= cos(all->ray.angle) / move_speed;
		all->ray.p_pos.y -= sin(all->ray.angle) / move_speed;
		all->ray.pos.y = all->ray.p_pos.x;
		all->ray.pos.x = all->ray.p_pos.y;
	}
}

void	move_left_right(t_all *all, double move_speed)
{
	int	x;
	int	y;

	x = floor(all->ray.p_pos.x + cos(all->ray.angle - PI / 2) / move_speed);
	y = floor(all->ray.p_pos.y + sin(all->ray.angle - PI / 2) / move_speed);
	if (all->keys[2] == 0 && all->pars.map[y][x] != '1')
	{
		all->ray.p_pos.y += sin(all->ray.angle - PI / 2) / move_speed;
		all->ray.p_pos.x += cos(all->ray.angle - PI / 2) / move_speed;
		all->ray.pos.y = all->ray.p_pos.x;
		all->ray.pos.x = all->ray.p_pos.y;
	}
	x = floor(all->ray.p_pos.x + cos(all->ray.angle + PI / 2) / move_speed);
	y = floor(all->ray.p_pos.y + sin(all->ray.angle + PI / 2) / move_speed);
	if (all->keys[3] == 0 && all->pars.map[y][x] != '1')
	{
		all->ray.p_pos.y += sin(all->ray.angle + PI / 2) / move_speed;
		all->ray.p_pos.x += cos(all->ray.angle + PI / 2) / move_speed;
		all->ray.pos.y = all->ray.p_pos.x;
		all->ray.pos.x = all->ray.p_pos.y;
	}
}

void	rotate_left_right(t_all *all)
{
	if (all->keys[4] == 0)
	{
		all->ray.angle -= 0.05;
		if (all->ray.angle < 0)
			all->ray.angle = 2 * PI;
		double oldDirX = all->ray.dir.x;
		all->ray.dir.x = all->ray.dir.x * cos(all->ray.rotSpeed) - all->ray.dir.y * sin(all->ray.rotSpeed);
		all->ray.dir.y = oldDirX * sin(all->ray.rotSpeed) + all->ray.dir.y * cos(all->ray.rotSpeed);
		double oldPlaneX = all->ray.plane.x;
		all->ray.plane.x = all->ray.plane.x * cos(all->ray.rotSpeed) - all->ray.plane.y * sin(all->ray.rotSpeed);
		all->ray.plane.y = oldPlaneX * sin(all->ray.rotSpeed) + all->ray.plane.y * cos(all->ray.rotSpeed);
	}
	if (all->keys[5] == 0)
	{
		all->ray.angle += 0.05;
		if (all->ray.angle > 2 * PI)
			all->ray.angle = 0;
		double oldDirX = all->ray.dir.x;
		all->ray.dir.x = all->ray.dir.x * cos(-all->ray.rotSpeed) - all->ray.dir.y * sin(-all->ray.rotSpeed);
		all->ray.dir.y = oldDirX * sin(-all->ray.rotSpeed) + all->ray.dir.y * cos(-all->ray.rotSpeed);
		double oldPlaneX = all->ray.plane.x;
		all->ray.plane.x = all->ray.plane.x * cos(-all->ray.rotSpeed) - all->ray.plane.y * sin(-all->ray.rotSpeed);
		all->ray.plane.y = oldPlaneX * sin(-all->ray.rotSpeed) + all->ray.plane.y * cos(-all->ray.rotSpeed);
	}
	all->ray.delta_pos.x = cos(all->ray.angle);
	all->ray.delta_pos.y = sin(all->ray.angle);
}


int	move_player(t_all *all)
{
	double	move_speed;

	move_speed = 20;
	if ((all->keys[0] == 0 && all->keys[2] == 0)
		|| (all->keys[0] == 0 && all->keys[3] == 0)
		|| (all->keys[1] == 0 && all->keys[2] == 0)
		|| (all->keys[1] == 0 && all->keys[3] == 0))
		move_speed *= sqrt(2);
	move_up_down(all, move_speed);
	move_left_right(all, move_speed);
	rotate_left_right(all);
	return (0);
}
