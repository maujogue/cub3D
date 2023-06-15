/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typedef.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maujogue <maujogue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 14:12:47 by maujogue          #+#    #+#             */
/*   Updated: 2023/06/15 12:19:05 by maujogue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPEDEF_H
# define TYPEDEF_H

typedef struct pars
{
	char	*north_wall;
	char	*south_wall;
	char	*east_wall;
	char	*west_wall;
	uint32_t floor_color;
	uint32_t ceiling_color;
	char	**map;
}	t_pars;

typedef struct all
{
	void		*mlx;
	void		*mlx_win;
	t_pars		*pars;

}	t_all;

#endif