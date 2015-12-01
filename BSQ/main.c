/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/24 09:03:06 by acazuc            #+#    #+#             */
/*   Updated: 2015/08/24 11:01:07 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_solve.h"

int		main(int argc, char **argv)
{
	int	count;

	if (argc < 2)
		ft_solve(0);
	else
	{
		count = 0;
		while (++count < argc)
			ft_solve(argv[count]);
	}
}
