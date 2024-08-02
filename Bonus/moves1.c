/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felhafid <felhafid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 12:16:18 by felhafid          #+#    #+#             */
/*   Updated: 2024/05/05 14:09:37 by felhafid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	reverse_rotate(t_list **lst)
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
}

void	reverse_rotate_both(t_list **lst, t_list **dst)
{
	reverse_rotate(lst);
	reverse_rotate(dst);
}
