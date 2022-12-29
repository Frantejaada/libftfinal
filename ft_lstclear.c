
#include "libft.h"

void ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *tmp;
	t_list *aux;

	tmp = *lst;
	while (tmp)
	{
		aux = tmp -> next;
		(*del)(tmp -> content);
		free(tmp);
		tmp = aux;
	}
	*lst = NULL;
}