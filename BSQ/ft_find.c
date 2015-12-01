/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/24 20:52:47 by acazuc            #+#    #+#             */
/*   Updated: 2015/08/26 10:26:32 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_square.h"
#include "ft_map.h"
#include "ft_puts.h"

int			ft_check_two(t_map *map, int x, int y, int size)
{
	int			count;

	count = -1;
	while (++count < size)
		if (map->data[y + count][x + size - 1] == map->block)
			return (0);
	count = -1;
	while (++count < size)
		if (map->data[y + size - 1][x + count] == map->block)
			return (0);
	return (1);
}

int			ft_check(t_map *map, int x, int y, int size)
{
	int			count_x;
	int			count_y;

	count_x = size;
	while (--count_x >= 0)
	{
		count_y = -1;
		while (++count_y < size)
			if (map->data[y + count_y][x + count_x] == map->block)
				return (count_x);
	}
	return (-2);
}

int			ft_check_at(t_map *map, t_square *square, int x, int y)
{
	int			count_size;
	int			result;

	count_size = square->size;
	if ((result = ft_check(map, x, y, count_size + 1)) == -2)
		while (x + ++count_size <= map->width
				&& y + count_size <= map->height
				&& ft_check_two(map, x, y, count_size))
		{
			square->size = count_size;
			square->x = x;
			square->y = y;
		}
	else
		return (result);
	return (0);
}

t_square	*ft_find(t_map *map)
{
	t_square	*square;
	int			count_x;
	int			count_y;

	square = malloc(sizeof(*square));
	if (!square)
		return (0);
	square->x = 0;
	square->y = 0;
	square->size = 0;
	count_y = -1;
	while (++count_y < map->height - square->size)
	{
		count_x = -1;
		while (++count_x < map->width - square->size)
			count_x += ft_check_at(map, square, count_x, count_y);
	}
	return (square);
}
