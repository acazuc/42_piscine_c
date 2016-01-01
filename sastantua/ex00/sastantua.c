/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sastantua.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/08 07:40:32 by acazuc            #+#    #+#             */
/*   Updated: 2015/08/08 13:27:04 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_putchar(char c);

int		get_stage_offset(int total_stages, int stage)
{
	int stage_offset;
	int i;

	stage_offset = 0;
	i = total_stages - 1;
	while (i > 0 && i > stage)
	{
		stage_offset += i + 1 + (i - 1) / 2 + 4;
		i--;
	}
	return (stage_offset);
}

int		get_line_width(int stage, int stage_line)
{
	int stage_count;
	int stage_line_count;
	int stage_line_width;

	stage_count = 0;
	stage_line_count = 0;
	stage_line_width = 1;
	while (stage_count < stage)
	{
		stage_line_width += stage_count * 2 + (stage_count / 2) * 2 + 10;
		stage_count++;
	}
	while (stage_line_count < stage_line)
	{
		stage_line_width = stage_line_width + 2;
		stage_line_count++;
	}
	return (stage_line_width);
}

int		print_door(int stage, int line, int line_pos)
{
	int door_placed;
	int door_size;

	door_placed = 0;
	door_size = stage % 2 == 0 ? stage : stage - 1;
	door_size = door_size < 0 ? 0 : door_size;
	if (line >= stage + 2 - door_size)
	{
		if (door_size >= 3 && line == stage + 2 - door_size / 2
			&& line_pos == get_line_width(stage, line) / 2 + door_size / 2 - 1)
		{
			ft_putchar('$');
			door_placed = 1;
		}
		else if (line_pos >= get_line_width(stage, line) / 2 - door_size / 2
			&& line_pos <= ((get_line_width(stage, line) + door_size) / 2))
		{
			ft_putchar('|');
			door_placed = 1;
		}
	}
	return (door_placed);
}

void	print_stage_line(int total_stages, int stage, int stage_line)
{
	int i;

	i = 0;
	while (i < stage + 2 - stage_line)
	{
		ft_putchar(' ');
		i++;
	}
	ft_putchar('/');
	i = 0;
	while (i < get_line_width(stage, stage_line))
	{
		if (stage != total_stages - 1 || !print_door(stage, stage_line, i))
		{
			ft_putchar('*');
		}
		i++;
	}
	ft_putchar('\\');
}

void	sastantua(int size)
{
	int stage_count;
	int line_count;
	int offset_count;

	stage_count = 0;
	while (stage_count < size)
	{
		line_count = 0;
		while (line_count < (stage_count + 3))
		{
			offset_count = 0;
			while (offset_count < get_stage_offset(size, stage_count))
			{
				ft_putchar(' ');
				offset_count++;
			}
			print_stage_line(size, stage_count, line_count);
			ft_putchar('\n');
			line_count++;
		}
		stage_count++;
	}
}
