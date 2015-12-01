/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/25 09:50:50 by acazuc            #+#    #+#             */
/*   Updated: 2015/08/26 11:18:13 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_map.h"
#include "ft_square.h"

void	ft_write(t_map *map, t_square *square)
{
	int	count;
	int	count2;

	count = -1;
	while (++count < map->height)
	{
		if (count < square->y || count >= square->y + square->size)
			write(1, map->data[count], map->width);
		else
		{
			write(1, map->data[count], square->x);
			count2 = -1;
			while (++count2 < square->size)
				write(1, &(map->square), 1);
			write(1, map->data[count] + square->x + square->size,
					map->width - square->x - square->size);
		}
		write(1, "\n", 1);
	}
}
