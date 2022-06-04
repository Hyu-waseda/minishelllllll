/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstdel_mid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaneko <kkaneko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 18:52:36 by kkaneko           #+#    #+#             */
/*   Updated: 2022/03/13 02:34:43 by kkaneko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	lstdel_mid(t_list *lst)
{
	lst->prev->next = lst->next;
	lst->next->prev = lst->prev;
	ft_lstdelone(lst, free_content);
}
