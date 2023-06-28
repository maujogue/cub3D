/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typedef.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maujogue <maujogue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 14:12:47 by maujogue          #+#    #+#             */
/*   Updated: 2023/06/28 15:38:48 by maujogue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPEDEF_H
# define TYPEDEF_H

# define SIZE_MINIMAP 25
# define RADIUS 5
# define HEIGHT 1080
# define WIDTH 1920
# define PI 3.141592653589793

# ifdef __APPLE__
#  define W_KEY 13
#  define A_KEY 0
#  define S_KEY 1
#  define D_KEY 2
#  define L_ARROW 123
#  define R_ARROW 124
#  define ESC_KEY 53
#  define SPACE_KEY 49
# else
#  define W_KEY 119
#  define A_KEY 97
#  define S_KEY 115
#  define D_KEY 100
#  define L_ARROW 65361
#  define R_ARROW 65363
#  define ESC_KEY 65307
#  define SPACE_KEY 32
# endif

typedef struct s_vector
{
	double	x;
	double	y;
}				t_vector;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		*addr2;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		pix_height;
}				t_data;

typedef struct pars
{
	char		*north_wall;
	char		*south_wall;
	char		*east_wall;
	char		*west_wall;
	uint32_t	floor_color;
	uint32_t	ceiling_color;
	char		**map;
}	t_pars;

typedef struct s_ray
{
	t_vector	p_pos;
	t_vector	delta_pos;
	double		angle;
	t_vector	pos;
	t_vector	dir;
	t_vector	plane;
	double		time;
	double		oldtime;
	double		cameraX;
	t_vector	raydir;
	t_vector	sidedist;
	t_vector	deltadist;
	int			mapX;
	int			mapY;
	double		perpWallDist;
	int			stepX;
	int			stepY;
	int			inWall;
	int			sideWall;
	int			drawStart;
	int			drawEnd;
	int			lineHeight;
	double		rotSpeed;
	double		moveSpeed;
	int			texNum;
	double		wallX;
	int			texX;
	double		texStep;
	double		texPos;
	int			texY;
	t_data		texture[4];
	int			drawStartTmp;
}				t_ray;

typedef struct all
{
	t_data		data;
	t_ray		ray;		
	t_pars		pars;
	void		*mlx;
	void		*mlx_win;
	int			mouse_pos;
	int			keys[6];
}	t_all;

#endif