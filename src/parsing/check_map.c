/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maujogue <maujogue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 13:18:09 by maujogue          #+#    #+#             */
/*   Updated: 2023/06/15 14:47:12 by maujogue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub.h"

static int	check_map_wall(char **map)
{
	int	i;
	int	j;

	i = -1;
	while (map[0][++i])
	{
		printf("%c",map[0][i] );
		if (map[0][i] != '1')
			return (1);
	}
	j = -1;
	while (map[++j])
	{
		i = 0;
		while (map[j][i + 1])
			i++;
		if (map[j][0] != '1' || map[j][i] != '1')
			return (1);
	}
	i = 0;
	j--;
	while (map[j][i])
	{
		if (map[j][i] != '1')
			return (1);
		i++;
	}
	return (EXIT_SUCCESS);
}

int	ft_strlen_array(char **str)
{
	int	i;

	i = 0;
	if (str)
	{
		while (str[i] != NULL)
			i++;
	}
	return (i);
}

int	check_map_caracters(char **map)
{
	int	i;
	int	j;
	int	len_i;
	int	len_j;

	i = 0;
	j = 0;
	len_j = ft_strlen_array(map) - 1;
	while (map[j])
	{
		len_i = ft_strlen(map[j]) - 1;
		printf("%d %d\n", len_j, len_i);
		while (map[j][i])
		{
			if (ft_strchr(" 01NSEW", map[j][i]) == NULL)
				return (1);
			// if (map[i][j] == '0' && ((ft_strchr(" 01NSEW", map[i + 1][j]))|| (ft_strchr(" 01NSEW", map[i - 1][j]))
			// 		|| (ft_strchr(" 01NSEW", map[i][j + 1])) || (ft_strchr(" 01NSEW", map[i][j - 1]))))
			// 		return (1);
			if (map[j][i] == ' ' && !((j < len_j && map[j + 1][i] == '1') && (j > 0 && map[j - 1][i] == '1')
					&& (i < len_i && map[j][i + 1] == '1') && (i > 0 && map[j][i - 1] == '1')))
					return (1);
			i++;	
		}
		i = 0;
		j++;
	}
	return (0);
}

void	check_map(t_all *all)
{
	if (check_map_caracters(all->pars->map) == EXIT_FAILURE)
		free_exit(all, 1, "Error - Invalid caracter\n");
	if (check_map_wall(all->pars->map) == EXIT_FAILURE)
		free_exit(all, 1, "Error - Map is not surrounded by walls\n");
}
