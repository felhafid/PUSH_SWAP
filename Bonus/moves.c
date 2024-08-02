/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felhafid <felhafid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 12:16:18 by felhafid          #+#    #+#             */
/*   Updated: 2024/05/06 18:18:38 by felhafid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	swap(t_list **lst)
{
	t_list	*p;

	p = *lst;
	if (ft_lstsize(p) <= 1)
		return ;
	p = p->next;
	if (ft_lstsize((*lst)) == 2)
	{
		(*lst)->next = NULL;
		p->next = (*lst);
	}
	else
	{
		(*lst)->next = NULL;
		(*lst)->next = p->next;
		p->next = (*lst);
	}
	*lst = p;
}

void	swap_both(t_list **lst, t_list **dst)
{
	swap(lst);
	swap(dst);
}

void	rotate(t_list **lst)
{
	t_list	*p;
	t_list	*head;

	p = *lst;
	if (ft_lstsize((*lst)) == 1 || ft_lstsize((*lst)) <= 0)
		return ;
	p = p->next;
	head = p;
	while (head->next != NULL)
		head = head->next;
	(*lst)->next = NULL;
	head->next = (*lst);
	(*lst) = p;
}

void	rotate_both(t_list **lst, t_list **dst)
{
	rotate(lst);
	rotate(dst);
}

void	push(t_list **lst, t_list **dst)
{
	t_list	*p;
	t_list	*k;

	if (ft_lstsize(*lst) == 0)
		return ;
	k = *lst;
	p = *lst;
	k = k->next;
	*lst = k;
	p->next = NULL;
	p->next = *dst;
	*dst = p;
}
