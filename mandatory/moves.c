/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felhafid <felhafid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 10:35:56 by felhafid          #+#    #+#             */
/*   Updated: 2024/05/06 21:02:17 by felhafid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **lst, char *nameopr)
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
	if (nameopr[1] == 'a')
		write(1, "sa\n", 3);
	else if (nameopr[1] == 'b')
		write(1, "sb\n", 3);
}

void	rotate(t_list **lst, char *nameopr)
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
	if (nameopr[1] == 'a')
		write(1, "ra\n", 3);
	else if (nameopr[1] == 'b')
		write(1, "rb\n", 3);
}

void	reverse_rotate(t_list **lst, char *nameopr)
{
	t_list	*p;
	t_list	*head;

	if (ft_lstsize((*lst)) == 1 || ft_lstsize((*lst)) <= 0)
		return ;
	p = *lst;
	while (p->next->next != NULL)
		p = p->next;
	head = p;
	p = p->next;
	head->next = NULL;
	p->next = (*lst);
	(*lst) = p;
	if (nameopr[2] == 'a')
		write(1, "rra\n", 4);
	else if (nameopr[2] == 'b')
		write(1, "rrb\n", 4);
}

void	push(t_list **lst, t_list **dst, char *nameopr)
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
	if (nameopr[1] == 'a')
		write(1, "pa\n", 3);
	else if (nameopr[1] == 'b')
		write(1, "pb\n", 3);
}
