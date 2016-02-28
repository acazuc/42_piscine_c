/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   match.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/10 17:02:24 by acazuc            #+#    #+#             */
/*   Updated: 2015/08/10 19:22:13 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	check_char(int count1, int count2, char *s1, char *s2);

int	ft_strlen(char *str)
{
	int length;

	length = 0;
	while (str[length])
	{
		length++;
	}
	return (length);
}

int	next_count1(int count1, int count2, char *s1, char *s2)
{
	int next_count1;

	next_count1 = -1;
	while (count1 < ft_strlen(s1))
	{
		if (s1[count1] == s2[count2] && check_char(count1, count2, s1, s2) == 1)
			next_count1 = count1;
		count1++;
	}
	return (next_count1);
}

int	check_char(int count1, int count2, char *s1, char *s2)
{
	int new_count1;

	while (count1 < ft_strlen(s1))
	{
		if (s2[count2] == '*')
		{
			if (count2 == ft_strlen(s2) - 1)
				return (1);
			new_count1 = next_count1(count1, ++count2, s1, s2);
			if (new_count1 == -1)
				return (0);
			else
				count1 = new_count1;
		}
		else if (s1[count1] != s2[count2])
			return (0);
		count1++;
		count2++;
	}
	if (count1 == ft_strlen(s1) && count2 == ft_strlen(s2))
		return (1);
	return (0);
}

int	match(char *s1, char *s2)
{
	if (s2[0] == '*')
		return (1);
	return (check_char(0, 0, s1, s2));
}
