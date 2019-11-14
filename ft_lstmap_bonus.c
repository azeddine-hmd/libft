/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 12:09:47 by ahamdaou          #+#    #+#             */
/*   Updated: 2019/10/29 15:26:15 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*ft_lstmap(t_list *l, void *(*f)(void *), void (*d)(void *))
{
	t_list	*node;
	t_list	*head;

	if (!l || !f || !d)
		return (NULL);
	node = ft_lstnew(f(l->content));
	if (!node)
	{
		ft_lstclear(&node, d);
		return (NULL);
	}
	head = node;
	l = l->next;
	while (l)
	{
		node = ft_lstnew(f(l->content));
		if (!node)
		{
			ft_lstclear(&head, d);
			return (NULL);
		}
		node = node->next;
		l = l->next;
	}
	return (head);
}
