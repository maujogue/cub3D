/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maujogue <maujogue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 12:06:42 by maujogue          #+#    #+#             */
/*   Updated: 2023/06/23 16:14:37 by maujogue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub.h"

void	move_up_down(t_all *all, double move_speed)
{
	int	x;
	int	y;

	x = (int)floor(all->ray.p_pos.x);
	if (all->keys[0] == 0)
	{
		y = (int)floor(all->ray.p_pos.y - move_speed);
		if (all->pars.map[y][x] != '1')
			all->ray.p_pos.y -= move_speed;
	}
	if (all->keys[1] == 0)
	{
		y = (int)floor(all->ray.p_pos.y + move_speed);
		if (all->pars.map[y][x] != '1')
			all->ray.p_pos.y += move_speed;
	}
}

void	move_left_right(t_all *all, double move_speed)
{
	int	x;
	int	y;

	y = (int)floor(all->ray.p_pos.y);
	if (all->keys[2] == 0)
	{
		x = (int)floor(all->ray.p_pos.x - move_speed);
		if (all->pars.map[y][x] != '1')
			all->ray.p_pos.x -= move_speed;
	}
	if (all->keys[3] == 0)
	{
		x = (int)floor(all->ray.p_pos.x + move_speed);
		if (all->pars.map[y][x] != '1')
			all->ray.p_pos.x += move_speed;
	}
}

int	move_player(t_all *all)
{
	double	move_speed;

	move_speed = 0.05;
	if ((all->keys[0] == 0 && all->keys[2] == 0)
		|| (all->keys[0] == 0 && all->keys[3] == 0)
		|| (all->keys[1] == 0 && all->keys[2] == 0)
		|| (all->keys[1] == 0 && all->keys[3] == 0))
		move_speed /= sqrt(2);
	move_up_down(all, move_speed);
	move_left_right(all, move_speed);
	return (0);
}
