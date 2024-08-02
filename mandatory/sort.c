/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felhafid <felhafid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 10:35:56 by felhafid          #+#    #+#             */
/*   Updated: 2024/05/09 10:21:14 by felhafid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sort(t_list **a)
{
	t_list	*p;

	p = *a;
	while (p->next != NULL)
	{
		if (p->content > p->next->content)
			return (1);
		p = p->next;
	}
	return (0);
}

void	sort_2(t_list **a)
{
	swap(a, "sa");
}

void	sort_3(t_list **a)
{
	if (((*a)->content) > ((*a)->next->content))
	{
		if (((*a)->next->content) < ((*a)->next->next->content))
		{
			if (((*a)->next->next->content) > ((*a)->content))
				swap(a, "sa");
			else
				rotate(a, "ra");
		}
		else
		{
			swap(a, "sa");
			reverse_rotate(a, "rra");
		}
	}
	else
	{
		if (((*a)->next->next->content) > ((*a)->content))
		{
			swap(a, "sa");
			rotate(a, "ra");
		}
		else
			reverse_rotate(a, "rra");
	}
}

void	sort_5(t_list **a, t_list **b)
{
	if (ft_lstsize(*a) == 5)
		pushmin(a, b);
	if (check_sort(a) == 1)
		pushmin(a, b);
	if (check_sort(a) == 1)
		sort_3(a);
	while (*b)
		push(b, a, "pa");
}

void	sort_all(t_list **a, t_list **b)
{
	if (ft_lstsize(*a) == 2)
		sort_2(a);
	else if (ft_lstsize(*a) == 3 && check_sort(a) == 1)
		sort_3(a);
	else if ((ft_lstsize(*a) == 5 || ft_lstsize(*a) == 4) && check_sort(a) == 1)
		sort_5(a, b);
	else
		sorting(a, b);
}
