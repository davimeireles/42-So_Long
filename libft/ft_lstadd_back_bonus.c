/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 14:41:08 by dmeirele          #+#    #+#             */
/*   Updated: 2023/10/15 12:05:20 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*node_helper;

	node_helper = *lst;
	if (node_helper == NULL)
	{
		*lst = new;
		return ;
	}
	while (node_helper->next)
		node_helper = node_helper->next;
	node_helper->next = new;
}
