/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_colle0x.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/22 11:35:36 by acazuc            #+#    #+#             */
/*   Updated: 2015/08/23 11:32:12 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_puts.h"

extern int	g_written;

int		ft_check_line_top(char *str, int width, char *chars)
{
	int		count;

	count = -1;
	while (str[++count] && str[count] != '\n')
		if (count == 0)
		{
			if (str[count] != chars[1])
				return (0);
		}
		else if (count == width - 1)
		{
			if (str[count] != chars[3])
				return (0);
		}
		else if (str[count] != chars[2])
			return (0);
	if (count == width)
		return (1);
	return (0);
}

int		ft_check_line_bot(char *str, int width, char *chars)
{
	int		count;

	count = -1;
	while (str[++count] && str[count] != '\n')
		if (count == 0)
		{
			if (str[count] != chars[7])
				return (0);
		}
		else if (count == width - 1)
		{
			if (str[count] != chars[9])
				return (0);
		}
		else if (str[count] != chars[8])
			return (0);
	if (count == width)
		return (1);
	return (0);
}

int		ft_check_line_mid(char *str, int width, char *chars)
{
	int		count;

	count = -1;
	while (str[++count] && str[count] != '\n')
		if (count == 0)
		{
			if (str[count] != chars[4])
				return (0);
		}
		else if (count == width - 1)
		{
			if (str[count] != chars[6])
				return (0);
		}
		else if (str[count] != chars[5])
			return (0);
	if (count == width)
		return (1);
	return (0);
}

void	ft_put_ok(char id, int width, int height)
{
	if (g_written)
		ft_putstr(" || ");
	g_written = 1;
	ft_putstr("[colle-0");
	ft_putchar(id);
	ft_putstr("] [");
	ft_putnbr(width);
	ft_putstr("] [");
	ft_putnbr(height);
	ft_putstr("]");
}

void	ft_check_colle0x(char *str, int width, int height, char *chars)
{
	int		line_count;

	line_count = -1;
	if (!width || !height)
		line_count = height;
	while (++line_count < height)
		if (line_count == 0)
		{
			if (!ft_check_line_top(str + (width + 1) *
						line_count, width, chars))
				return ;
		}
		else if (line_count == height - 1)
		{
			if (!ft_check_line_bot(str + (width + 1) *
						line_count, width, chars))
				return ;
		}
		else if (!ft_check_line_mid(str + (width + 1) *
					line_count, width, chars))
			return ;
	ft_put_ok(chars[0], width, height);
}
