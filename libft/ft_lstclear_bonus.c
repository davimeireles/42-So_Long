/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 12:04:37 by dmeirele          #+#    #+#             */
/*   Updated: 2023/10/15 12:04:39 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*node_helper;
	t_list	*node_free;

	node_helper = *lst;
	while (node_helper)
	{
		del(node_helper->content);
		node_free = node_helper;
		node_helper = node_helper->next;
		free(node_free);
	}
	*lst = NULL;
}
