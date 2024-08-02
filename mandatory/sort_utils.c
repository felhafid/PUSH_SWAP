/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felhafid <felhafid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 10:35:56 by felhafid          #+#    #+#             */
/*   Updated: 2024/05/28 15:23:50 by felhafid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	min(t_list **a)
{
	t_list	*p;
	int		min;

	p = *a;
	min = p->content;
	p = p->next;
	while (p != NULL)
	{
		if (min > p->content)
			min = p->content;
		p = p->next;
	}
	return (min);
}

void	pushmin(t_list **a, t_list **b)
{
	int		min1;

	min1 = min(a);
	if (min1 == (*a)->next->content)
		swap(a, "sa");
	else if (min1 == (*a)->next->next->content)
	{
		rotate(a, "ra");
		rotate(a, "ra");
	}
	else if (min1 == (*a)->next->next->next->content)
	{
		if (ft_lstsize(*a) == 5)
		{
			reverse_rotate(a, "rra");
			reverse_rotate(a, "rra");
		}
		else if (ft_lstsize(*a) == 4)
			reverse_rotate(a, "rra");
	}
	else if (ft_lstsize(*a) == 5
		&& min1 == (*a)->next->next->next->next->content)
		reverse_rotate(a, "rra");
	if (check_sort(a) == 1)
		push(a, b, "pb");
}

char	*ft_strdup(char *s)
{
	int		i;
	char	*str;

	i = 0;
	str = malloc(ft_strlen(s) + 1);
	if (!str)
		return (NULL);
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
