/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/24 11:22:06 by acazuc            #+#    #+#             */
/*   Updated: 2015/08/27 14:58:25 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_map.h"

int		ft_parse_header(char *data, t_map *map)
{
	int		count;
	int		size;

	count = -1;
	while (data[++count] && data[count] != '\n')
	{
	}
	size = count;
	if (size < 4)
		return (-1);
	map->empty = data[size - 3];
	map->block = data[size - 2];
	map->square = data[size - 1];
	if (map->empty == map->block || map->empty == map->square
			|| map->block == map->square)
		return (-1);
	count = -1;
	map->height = 0;
	while (++count < size - 3)
		if (data[count] >= '0' && data[count] <= '9')
			map->height = map->height * 10 + data[count] - '0';
		else
			return (-1);
	return (size);
}

int		ft_parse_body_loop(char *data, t_map *map, int offset, int max_width)
{
	int		height;
	int		width;
	int		count;

	count = offset;
	height = -1;
	width = -2;
	while (data[count])
	{
		if ((++height > map->height) || (width != -2 && width != max_width - 1))
			return (0);
		width = -1;
		while (data[++count] && data[count] != '\n')
		{
			if ((++width > max_width)
					|| (data[count] != map->empty && data[count] != map->block))
				return (0);
			map->data[height][width] = data[count];
		}
	}
	if (height != map->height)
		return (0);
	return (1);
}

int		ft_parse_body(char *data, t_map *map, int offset)
{
	int		count;
	int		max_width;

	if (offset == -1)
		return (0);
	count = offset;
	while (data[++count] && data[count] != '\n')
	{
	}
	max_width = count - offset - 1;
	map->width = max_width;
	map->data = malloc(sizeof(*map->data) * map->height);
	map->data[0] = malloc(sizeof(**map->data) * map->height * max_width);
	count = 0;
	while (++count < map->height)
		map->data[count] = &(map->data[0][count * map->width]);
	if (!ft_parse_body_loop(data, map, offset, max_width))
		return (0);
	return (1);
}

int		ft_parse(char *data, t_map *map)
{
	int		result;

	if (!data)
		return (0);
	result = ft_parse_body(data, map, ft_parse_header(data, map));
	free(data);
	return (result);
}
