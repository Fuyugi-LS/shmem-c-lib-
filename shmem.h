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