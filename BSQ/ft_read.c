/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/23 11:26:03 by acazuc            #+#    #+#             */
/*   Updated: 2015/08/27 15:22:07 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "ft_puts.h"
#include "ft_file_size.h"
#define BUFF_SIZE 100000000

char	*ft_concat(char *s1, char *s2, int s1_len, int s2_len)
{
	int		count;
	char	*result;

	if (!(result = malloc(sizeof(*result) * (s1_len + s2_len + 1))))
		return (0);
	if (s1)
	{
		count = -1;
		while (++count < s1_len)
			result[count] = s1[count];
		free(s1);
	}
	count = -1;
	while (++count < s2_len)
		result[count + s1_len] = s2[count];
	result[s1_len + count] = 0;
	return (result);
}

char	*ft_read_stdin(void)
{
	long	size;
	int		readed;
	char	*buffer;
	char	*result;

	size = 0;
	result = 0;
	if (!(buffer = malloc(sizeof(*buffer) * BUFF_SIZE)))
		return (0);
	while ((readed = read(0, buffer, BUFF_SIZE - 1)) > 0)
	{
		buffer[readed] = 0;
		result = ft_concat(result, buffer, size, readed);
		size += readed;
	}
	free(buffer);
	return (result);
}

char	*ft_read(char *file)
{
	long	size;
	int		readed;
	char	*buffer;
	int		fd;

	if ((size = ft_file_size(open(file, O_RDONLY))) == -1)
		return (0);
	if ((fd = open(file, O_RDONLY)) == -1)
		return (0);
	if (!(buffer = malloc(sizeof(*buffer) * size)))
		return (0);
	if ((readed = read(fd, buffer, size)) < 0)
		return (0);
	buffer[readed] = 0;
	close(fd);
	return (buffer);
}
