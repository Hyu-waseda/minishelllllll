/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okumurahyu <okumurahyu@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 15:23:06 by okumurahyu        #+#    #+#             */
/*   Updated: 2022/02/20 17:47:37 by okumurahyu       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(char*))
{
	t_list	*tmp;

	if (lst == 0 || *lst == 0 || del == 0)
		return ;
	while (*lst != 0)
	{
		tmp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = tmp;
	}
}

/* 
void	del(void *content);

int main()
{
	t_list *new;
	t_list **lst;
	
	lst = (t_list **)ft_xmalloc(sizeof(t_list*) * 5);
	lst[0] = ft_lstnew("0ban");
	lst[1] = ft_lstnew("1ban");
	lst[2] = ft_lstnew("2ban");
	lst[3] = ft_lstnew("3ban");
	lst[4] = ft_lstnew("4ban");
	lst[0]->next = lst[1];
	lst[1]->next = lst[2];
	lst[2]->next = lst[3];
	lst[3]->next = lst[4];
	lst[4]->next = 0;
	ft_lstclear(&lst[0], del);

	t_list *now;
	now = lst[0];
	while(now != 0)
	{
		printf("new->content = %s\n", (char *)now->content);
		now = now->next;
	}
}

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = (t_list *)ft_xmalloc(sizeof(t_list) * 1);
	if (new == 0)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

void	del(void *content)
{
	printf("del\n");
}

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (del == 0 || lst == 0)
		return ;
	(*del)(lst->content);
	free(lst);
}
 */