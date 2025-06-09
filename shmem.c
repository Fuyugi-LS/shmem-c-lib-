/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shmem.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsongsit < nsongsit@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 20:42:04 by nsongsit          #+#    #+#             */
/*   Updated: 2025/06/09 22:10:57 by nsongsit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shmem.h"

static t_list	*get_list(void)
{
	static t_list	list;
	static int		init;
	int				is_init;

	is_init = init;
	if (!is_init)
	{
		list.head = NULL;
		list.tail = NULL;
		init = 1;
	}
	return (&list);
}

static t_shnode	*create_shnode(void *ptr)
{
	t_shnode	*node;

	node = malloc(sizeof(t_shnode));
	if (!node)
		return (NULL);
	node->ptr = ptr;
	node->next = NULL;
	return (node);
}

void	*shloc(size_t size)
{
	t_list		*list;
	void		*mem;
	t_shnode	*node;

	list = get_list();
	mem = malloc(size);
	if (!mem)
		return (NULL);
	node = create_shnode(mem);
	if (!node)
		return (free(mem), NULL);
	if (list->head == NULL)
	{
		list->head = node;
		list->tail = node;
		return (mem);
	}
	list->tail->next = node;
	list->tail = node;
	return (mem);
}

void	shfree(void)
{
	t_list		*list;
	t_shnode	*curr;
	t_shnode	*next;

	list = get_list();
	curr = list->head;
	while (curr)
	{
		next = curr->next;
		free(curr->ptr);
		free(curr);
		curr = next;
	}
	list->head = NULL;
	list->tail = NULL;
}
