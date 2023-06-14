/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maujogue <maujogue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:15:47 by maujogue          #+#    #+#             */
/*   Updated: 2023/06/14 13:59:15 by maujogue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*pointer;

	if (size > 0 && count > (SIZE_MAX / size))
		return (NULL);
	pointer = malloc(count * size);
	if (! (pointer))
		return (NULL);
	ft_bzero(pointer, count * size);
	return (pointer);
}
