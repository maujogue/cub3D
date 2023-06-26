/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maujogue <maujogue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 13:54:50 by maujogue          #+#    #+#             */
/*   Updated: 2023/06/26 14:50:05 by maujogue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub.h"

int utils(void)
{
	return (0);
}

int	ft_strlen_array(char **str)
{
	int	i;

	i = 0;
	if (str)
	{
		while (str[i])
			i++;
	}
	return (i);
}

void	set_player_position(t_all *all)
{
	int	x;
	int	y;

	y = 0;
	while (all->pars.map[y])
	{
		x = 0;
		while (all->pars.map[y][x])
		{
			if (ft_strchr("NSEW", all->pars.map[y][x]))
			{
				all->ray.p_pos.x = x;
				all->ray.p_pos.y = y;
				all->ray.pos.y = (double)x;
				all->ray.pos.x = (double)y;
				return ;
			}
			x++;
		}
		y++;
	}
}
