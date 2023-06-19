/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos_playeur.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaganay <avaganay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 14:03:20 by avaganay          #+#    #+#             */
/*   Updated: 2023/06/17 14:46:26 by avaganay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub.h"

void	find_pos_playeur(t_all *all)
{
	int	x;
	int	y;

	x = 0;
	while (all->pars->map[x])
	{
		y = 0;
		while (all->pars->map[x][y])
		{
			if (ft_strchr("NWES", all->pars->map[x][y]))
			{
				all->ray->pos.x = (double)x;
				all->ray->pos.y = (double)y;
				return ;
			}
			y++;
		}
		x++;
	}
}