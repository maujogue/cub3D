/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typedef.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaganay <avaganay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 14:12:47 by maujogue          #+#    #+#             */
/*   Updated: 2023/06/16 10:35:10 by avaganay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPEDEF_H
# define TYPEDEF_H

# define SIZE_MINIMAP 50
# define W_KEY 119
# define A_KEY 97
# define S_KEY 115
# define D_KEY 100
# define ESC_KEY 65307
# define SPACE_KEY 32
# define SPACE_KEY 32

typedef struct	s_vector
{
	double	x;
	double	y;
}				t_vector;

typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

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

typedef struct s_map
{
	char	**map;
}				t_map;

typedef struct s_ray
{
	t_vector pos;
	t_vector dir;
	t_vector plane;
	double	time;
	double	oldtime;
	double	cameraX;
	t_vector raydir;
	t_vector sidedist;
	t_vector deltadist;
	int		mapX;
	int		mapY;
}				t_ray;


typedef struct all
{
	t_data		*data;
	t_map 		*map;
	t_ray		*ray;		
	t_pars		*pars;			
	void	*mlx;
	void	*mlx_win;
	}	t_all;

#endif