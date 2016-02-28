/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/15 10:29:31 by acazuc            #+#    #+#             */
/*   Updated: 2015/08/15 19:06:29 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	ft_print_tab(int *tab)
{
	int		count;
	char	c;

	count = 0;
	while (++count <= 81)
	{
		c = '0' + tab[count - 1];
		write(1, &c, 1);
		if (count % 9 == 0)
			write(1, "\n", 1);
		else
			write(1, " ", 1);
	}
}

int		ft_is_ok(int cell, int *tab)
{
	int		count;

	count = -1;
	while (++count < 9)
		if (((cell / 9) * 9 + count) != cell
				&& tab[(cell / 9) * 9 + count] == tab[cell])
			return (0);
	count = -1;
	while (++count < 9)
		if (((cell % 9 + count * 9) != cell)
				&& tab[cell % 9 + count * 9] == tab[cell])
			return (0);
	count = -1;
	while (++count < 9)
		if ((((cell % 9) / 3) * 3 + count / 3) +
				(((cell / 9) / 3) * 3 + count % 3) * 9 != cell)
			if (tab[(((cell % 9) / 3) * 3 + count / 3) +
					(((cell / 9) / 3) * 3 + count % 3) * 9] == tab[cell])
				return (0);
	return (1);
}

long	ft_check_case(int cell, int *tab, int show)
{
	int		count;
	long	add;

	if (cell == 81 && show)
		ft_print_tab(tab);
	if (cell == 81)
		return (1);
	count = 0;
	add = 0;
	if (tab[cell] == 0)
	{
		while (++count < 10)
		{
			tab[cell] = count;
			if (ft_is_ok(cell, tab))
				add += ft_check_case(cell + 1, tab, show);
			tab[cell] = 0;
		}
	}
	else if (ft_is_ok(cell, tab))
		return (ft_check_case(cell + 1, tab, show));
	return (add);
}

int		ft_init(char **argv, int *tab)
{
	int		count;
	int		count2;
	int		count3;

	count = 0;
	count2 = 1;
	while (++count < 10)
	{
		count3 = 0;
		count2--;
		while (argv[count3])
		{
			if (argv[count][count3] == '.')
				tab[count2] = 0;
			else if (argv[count][count3] >= '0' && argv[count][count3] <= '9')
				tab[count2] = argv[count][count3] - '0';
			count3++;
			count2++;
		}
	}
	return (1);
}

int		main(int argc, char **argv)
{
	int		*tab;
	int		count;
	long	result;

	result = -1;
	tab = malloc(sizeof(*tab) * 81);
	count = -1;
	while (++count < 81)
		tab[count] = 0;
	if (argc == 10)
	{
		if (!ft_init(argv, tab))
		{
			write(1, "Erreur\n", 7);
			return (0);
		}
		result = ft_check_case(0, tab, 0);
	}
	if (result == 1)
		ft_check_case(0, tab, 1);
	else
		write(1, "Erreur\n", 7);
	free(tab);
	return (0);
}
