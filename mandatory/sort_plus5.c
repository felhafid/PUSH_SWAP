/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_plus5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felhafid <felhafid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 10:35:56 by felhafid          #+#    #+#             */
/*   Updated: 2024/05/06 21:02:31 by felhafid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	indixing(t_list **a)
{
	t_list	*p;
	t_list	*h;

	p = *a;
	while (p != NULL)
	{
		h = *a;
		while (h != NULL)
		{
			if (p->content > h->content)
				p->indix = p->indix + 1;
			h = h->next;
		}
		p = p->next;
	}
	p = *a;
}

int	range_eq(int n)
{
	int	range;

	if (n <= 50)
		range = 8;
	else if (n <= 100)
		range = 15;
	else
		range = 35;
	return (range);
}

int	ra_or_rra(t_list **b)
{
	t_list	*p;
	int		i;

	p = *b;
	i = 1;
	while (p)
	{
		if (p->indix == ft_lstsize(*b) - 1)
		{
			if (i < ft_lstsize(*b) / 2)
				return (1);
			else
				break ;
		}
		i++;
		p = p->next;
	}
	return (0);
}

void	fill_stack_a(t_list **a, t_list **b)
{
	while (*b)
	{
		if ((*b)->indix == ft_lstsize(*b) - 1)
		{
			push(b, a, "pa");
		}
		else
		{
			if (ra_or_rra(b) == 1)
			{
				rotate(b, "rb");
			}
			else
				reverse_rotate(b, "rrb");
		}
	}
}

void	sorting(t_list **a, t_list **b)
{
	int		range;
	int		nb;

	nb = 0;
	indixing(a);
	range = range_eq(ft_lstsize(*a));
	while ((*a) != NULL)
	{
		if ((*a)->indix >= nb && (*a)->indix <= range)
		{
			push(a, b, "pb");
			nb++;
			range++;
		}
		else if ((*a)->indix < nb)
		{
			push(a, b, "pb");
			rotate(b, "rb");
			nb++;
			range++;
		}
		else if ((*a)->indix > range)
			rotate(a, "ra");
	}
	fill_stack_a(a, b);
}
