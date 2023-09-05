/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maujogue <maujogue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 11:38:14 by maujogue          #+#    #+#             */
/*   Updated: 2023/09/05 17:54:52 by maujogue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	get_r(int trgb)
{
	return ((trgb >> 16) & 0xFF);
}

int	get_g(int trgb)
{
	return ((trgb >> 8) & 0xFF);
}

int	get_b(int trgb)
{
	return (trgb & 0xFF);
}

int	parse_color(t_all *all, t_list *lst, char *key)
{
	int		color;
	int		nbr;
	char	*temp_color;
	char	**temp_split;
	int		i;

	i = 0;
	temp_color = get_lst_content(lst, key);
	if (!temp_color || check_number(temp_color) == 1)
		return (free(temp_color), -2);
	temp_split = ft_split(temp_color, ',');
	if (!temp_split)
		return (free(temp_color), free_exit(all, 1, "Malloc Error\n"), 1);
	while (i < 3)
	{
		nbr = ft_atoi(temp_split[i]);
		if (nbr > 255 || nbr < 0 || ft_strlen_array(temp_split) != 3)
			return (free_array(temp_split), free(temp_color), -2);
		i++;
	}
	color = create_trgb(0, ft_atoi(temp_split[0]),
			ft_atoi(temp_split[1]), ft_atoi(temp_split[2]));
	return (free_array(temp_split), free(temp_color), color);
}
