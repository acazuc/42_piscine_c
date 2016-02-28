/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/23 11:26:03 by acazuc            #+#    #+#             */
/*   Updated: 2015/08/23 13:23:50 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "ft_list.h"
#define BUFF_SIZE 1024

t_list	*ft_create_elem(void *data)
{
	t_list	*elem;

	elem = malloc(sizeof(elem));
	if (elem)
	{
		elem->next = NULL;
		elem->data = data;
	}
	return (elem);
}

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*next;
	t_list	*new;

	new = ft_create_elem(data);
	if (*begin_list == NULL)
	{
		*begin_list = new;
		return ;
	}
	next = *begin_list;
	while (next->next != NULL)
		next = next->next;
	next->next = new;
}

char	*ft_build(t_list *list, int size)
{
	t_list	*temp;
	char	*result;
	int		offset;
	int		count;

	result = malloc(sizeof(*result) * size);
	if (result)
	{
		offset = -1;
		while (list)
		{
			count = -1;
			while (list->data[++count])
				result[++offset] = list->data[count];
			temp = list;
			list = list->next;
			free(temp->data);
			free(temp);
		}
		result[++offset] = 0;
	}
	return (result);
}

char	*ft_read(void)
{
	int		size;
	int		readed;
	char	*buffer;
	t_list	*list;

	size = 1;
	list = 0;
	buffer = malloc(sizeof(*buffer) * BUFF_SIZE);
	if (!buffer)
		return (0);
	while ((readed = read(0, buffer, BUFF_SIZE - 1)) > 0)
	{
		size += readed;
		buffer[readed] = 0;
		ft_list_push_back(&list, buffer);
		buffer = malloc(sizeof(*buffer) * BUFF_SIZE);
		if (!buffer)
			return (0);
	}
	return (ft_build(list, size));
}
