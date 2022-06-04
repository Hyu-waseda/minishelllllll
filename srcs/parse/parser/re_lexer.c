/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   re_lexer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaneko <kkaneko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 19:02:34 by kkaneko           #+#    #+#             */
/*   Updated: 2022/03/18 17:58:43 by kkaneko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	re_lexer(t_list **src)
{
	t_list	*new_tokens;
	t_list	*now;

	new_tokens = NULL;
	now = *src;
	while (now != NULL)
	{
		ft_lstjoin(&new_tokens, lexer(now->content));
		now = now->next;
	}
	ft_lstclear(src, free_content);
	*src = new_tokens;
}
