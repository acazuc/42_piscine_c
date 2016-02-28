/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dimensions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/22 14:49:58 by acazuc            #+#    #+#             */
/*   Updated: 2015/08/22 15:06:19 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_get_height(char *arg)
{
	int		count;
	int		result;

	count = -1;
	result = 0;
	while (arg[++count])
		if (arg[count] == '\n')
			result++;
	return (result);
}

int		ft_get_width(char *arg)
{
	int		length;
	int		count;

	count = -1;
	length = 0;
	while (arg[++count] && arg[count] != '\n')
		length++;
	return (length);
}
