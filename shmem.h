/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shmem.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsongsit <nsongsit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 20:43:47 by nsongsit          #+#    #+#             */
/*   Updated: 2025/06/09 21:53:25 by nsongsit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHMEM_H
# define SHMEM_H

# include <stdlib.h>
# include <stddef.h>

typedef struct s_shnode
{
	void			*ptr;
	struct s_shnode	*next;
}	t_shnode;

typedef struct s_list
{
	t_shnode	*head;
	t_shnode	*tail;
}	t_list;

void	*shloc(size_t size);
void	shfree(void);

#endif