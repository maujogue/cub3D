/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaganay <avaganay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 13:54:53 by maujogue          #+#    #+#             */
/*   Updated: 2023/06/15 11:43:06 by avaganay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <math.h>
# include "../minilibx_linux/mlx.h"

# include "typedef.h"

void    init_cub(t_all *all);

void	check_keypress(t_all *all);

void    free_exit(t_all *all);

void	ft_mlx(t_all *all);

void	draw_map(t_all *all);

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

#endif
