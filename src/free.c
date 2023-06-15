/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaganay <avaganay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 14:18:10 by maujogue          #+#    #+#             */
/*   Updated: 2023/06/15 13:01:40 by avaganay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub.h"

void    free_exit(t_all *all)
{
    mlx_clear_window(all->mlx, all->mlx_win);
    mlx_destroy_window(all->mlx, all->mlx_win);
    mlx_destroy_display(all->mlx);
    free(all->mlx);
    exit(1);
}