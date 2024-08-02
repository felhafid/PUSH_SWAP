/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felhafid <felhafid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 10:35:56 by felhafid          #+#    #+#             */
/*   Updated: 2024/05/06 21:02:23 by felhafid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strlen(char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

t_list	*ft_new(int content)
{
	t_list	*head;

	head = malloc(sizeof(t_list));
	if (!head)
		return (NULL);
	head->content = content;
	head->next = NULL;
	head->indix = 0;
	return (head);
}

void	ft_add_back(t_list **head, t_list *lst)
{
	t_list	*p;

	p = *head;
	while (p->next != NULL)
		p = p->next;
	p->next = lst;
	p = *head;
}

int	ft_lstsize(t_list *lst)
{
	int	i;

	if (lst == NULL)
		return (0);
	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

long	ft_atoi(char *s)
{
	int		i;
	int		sign;
	long	nb;

	i = 0;
	sign = 1;
	nb = 0;
	while (s[i] && (s[i] == '+' || s[i] == '-'))
	{
		if (s[i++] == '-')
		{
			sign = -sign;
			nb = -nb;
		}
	}
	while (s[i])
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			nb = nb * 10;
			nb = nb + (s[i] - 48);
		}
		i++;
	}
	return (nb * sign);
}
