/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/24 10:22:34 by acazuc            #+#    #+#             */
/*   Updated: 2015/08/27 14:59:16 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "ft_read.h"
#include "ft_map.h"
#include "ft_square.h"
#include "ft_puts.h"
#include "ft_parse.h"
#include "ft_find.h"
#include "ft_write.h"

void	ft_solve(char *file)
{
	t_square	*square;
	t_map		*map;
	char		*data;

	if (!(map = malloc(sizeof(*map))))
	{
		write(2, "map error\n", 10);
		return ;
	}
	square = 0;
	if (!file)
		data = ft_read_stdin();
	else
		data = ft_read(file);
	if (!data || !ft_parse(data, map) || map->height == 0 || map->width == 0)
	{
		free(map);
		write(2, "map error\n", 10);
		return ;
	}
	square = ft_find(map);
	ft_write(map, square);
	free(square);
	free(map->data);
	free(map);
}
