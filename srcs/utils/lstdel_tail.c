/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstdel_tail.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaneko <kkaneko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 18:49:19 by kkaneko           #+#    #+#             */
/*   Updated: 2022/03/16 15:11:21 by kkaneko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	lstdel_tail(t_list *lst)
{
	t_list	*del;

	del = ft_lstlast(lst);
	del->prev->next = NULL;
	ft_lstdelone(del, free_content);
}
