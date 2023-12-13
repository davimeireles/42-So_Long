/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 11:31:49 by dmeirele          #+#    #+#             */
/*   Updated: 2023/10/16 12:36:37 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*first_node(t_list *lst, void *(*f)(void *),
		void (*del)(void *))
{
	t_list	*ptrlst;
	void	*cont;

	cont = f(lst->content);
	ptrlst = ft_lstnew(cont);
	if (!ptrlst)
	{
		del(cont);
		return (NULL);
	}
	return (ptrlst);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*ptrlst;
	void	*cont;

	if (!lst)
		return (NULL);
	ptrlst = first_node(lst, f, del);
	if (ptrlst == NULL)
		return (NULL);
	head = ptrlst;
	while (lst->next)
	{
		lst = lst->next;
		cont = f(lst->content);
		ptrlst->next = ft_lstnew(cont);
		if (!ptrlst->next)
		{
			del(cont);
			ft_lstclear(&head, del);
			return (NULL);
		}
		ptrlst = ptrlst->next;
	}
	return (head);
}
