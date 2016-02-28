/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colle00.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/08 06:47:45 by acazuc            #+#    #+#             */
/*   Updated: 2015/08/09 15:52:07 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_putchar(char c);

int		is_corner(int width, int height, int current_width, int current_height)
{
	int is_corner;

	is_corner = 0;
	if ((current_width == 0 && current_height == 0)
			|| (current_width == 0 && current_height == height - 1)
			|| (current_width == width - 1 && current_height == 0)
			|| (current_width == width - 1 && current_height == height - 1))
	{
		is_corner = 1;
	}
	return (is_corner);
}

void	print_char(int width, int height, int width_c, int height_c)
{
	if (is_corner(width, height, width_c, height_c))
	{
		ft_putchar('o');
	}
	else if (width_c == 0 || width_c == width - 1)
	{
		ft_putchar('|');
	}
	else if (height_c == 0 || height_c == height - 1)
	{
		ft_putchar('-');
	}
	else
	{
		ft_putchar(' ');
	}
}

void	colle(int x, int y)
{
	int width_c;
	int height_c;

	height_c = 0;
	while (height_c < y)
	{
		width_c = 0;
		while (width_c < x)
		{
			print_char(x, y, width_c, height_c);
			width_c++;
		}
		ft_putchar('\n');
		height_c++;
	}
}
