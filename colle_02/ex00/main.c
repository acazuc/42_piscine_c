/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/22 11:28:59 by acazuc            #+#    #+#             */
/*   Updated: 2015/08/23 15:14:29 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "ft_puts.h"
#include "ft_dimensions.h"
#include "ft_check_colle0x.h"
#include "ft_list.h"
#include "ft_read.h"

int			g_written = 0;

int		ft_is_rectangle(char *result)
{
	int		length;
	int		max_length;
	int		count;

	count = 0;
	max_length = -1;
	while (result[count])
	{
		if (result[count] == '\n')
		{
			if (max_length == -1)
				max_length = length;
			else if (length != max_length)
				return (0);
			length = 0;
		}
		else
			length++;
		count++;
	}
	return (1);
}

void	ft_check_colles(char *result, int width, int height)
{
	char	*chars[5];

	chars[0] = "0o-o| |o-o";
	chars[1] = "1/*\\* *\\*/";
	chars[2] = "2ABAB BCBC";
	chars[3] = "3ABCB BABC";
	chars[4] = "4ABCB BCBA";
	if (!height || !width)
	{
		ft_check_colle0x(result, width, height, chars[0]);
		ft_check_colle0x(result, width, height, chars[1]);
		ft_check_colle0x(result, width, height, chars[2]);
		ft_check_colle0x(result, width, height, chars[3]);
		ft_check_colle0x(result, width, height, chars[4]);
	}
	else if (result[0] == 'o')
		ft_check_colle0x(result, width, height, chars[0]);
	else if (result[0] == '/')
		ft_check_colle0x(result, width, height, chars[1]);
	else if (result[0] == 'A')
	{
		ft_check_colle0x(result, width, height, chars[2]);
		ft_check_colle0x(result, width, height, chars[3]);
		ft_check_colle0x(result, width, height, chars[4]);
	}
}

void	ft_check_shapes(int width, int height)
{
	if (width == height)
	{
		if (g_written)
			ft_putstr(" || ");
		g_written = 1;
		ft_putstr("[carre] [");
		ft_putnbr(width);
		ft_putstr("] [");
		ft_putnbr(height);
		ft_putstr("]");
	}
	if (g_written)
		ft_putstr(" || ");
	g_written = 1;
	ft_putstr("[rectangle] [");
	ft_putnbr(width);
	ft_putstr("] [");
	ft_putnbr(height);
	ft_putstr("]");
}

int		main(void)
{
	char	*result;
	int		width;
	int		height;

	result = ft_read();
	width = ft_get_width(result);
	height = ft_get_height(result);
	write(1, "", 0);
	if (!width)
		height = 0;
	if (!height)
		width = 0;
	if (ft_is_rectangle(result))
	{
		ft_check_colles(result, width, height);
		if (!g_written)
			ft_putstr("aucune");
		g_written = 1;
		ft_check_shapes(width, height);
	}
	free(result);
	return (0);
}
