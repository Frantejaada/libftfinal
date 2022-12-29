
#include "libft.h"

void ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list *tmp;

	if (*lst == NULL)
	{
		*lst = new;
		return (NULL);
	}
	tmp = *lst;
	while (tmp -> next)
	{
		tmp = tmp -> new;
	}
	tmp -> next = new;
}