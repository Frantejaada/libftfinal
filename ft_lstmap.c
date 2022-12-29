
#include "libft.h"

t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *tmp;
	t_list *cabeza;

	cabeza = NULL;
	while(lst)
	{
		tmp = ft_lstnew((*f)(lst -> content));
		if (!tmp)
		{
			ft_lstclear(&cabeza, del);
			return (NULL);
		}
		else
		{
			ft_lstadd_front(&cabeza, tmp);
			lst = lst -> next;
		}
	}
	return (cabeza);
}