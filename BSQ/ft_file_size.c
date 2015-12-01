/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/26 12:02:46 by acazuc            #+#    #+#             */
/*   Updated: 2015/08/27 15:19:44 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#define BUFF_SIZE 100000

long	ft_file_size(int fd)
{
	long	size;
	int		readed;
	char	*buffer;

	if (fd == -1)
		return (-1);
	size = 1;
	if (!(buffer = malloc(sizeof(*buffer) * BUFF_SIZE)))
		return (-1);
	while ((readed = read(fd, buffer, BUFF_SIZE)) > 0)
		size += readed;
	free(buffer);
	if (readed == -1)
		return (-1);
	return (size);
}
