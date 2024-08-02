/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felhafid <felhafid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 10:35:56 by felhafid          #+#    #+#             */
/*   Updated: 2024/05/09 11:16:25 by felhafid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	frees(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
		free(str[i++]);
	free(str);
}

t_list	*ft_stack_a(char **v)
{
	t_list	*stack_a;
	int		i;
	char	*s;
	char	**str;

	if (ft_errors(v) == 0)
		exit(1); 
	i = 1;
	s = NULL;
	while (v[i])
		s = ft_join2string(s, v[i++]);
	i = 0;
	str = ft_split(s);
	if (ft_duplicates(ft_split(s)) == 0 || ft_limite(ft_split(s)) == 0)
	{
		frees(str);
		free(s);
		exit(1);
	}
	stack_a = ft_new(ft_atoi(str[i++]));
	while (str[i])
		ft_add_back(&stack_a, ft_new(ft_atoi(str[i++])));
	return (frees(str), free(s), stack_a);
}

void	ft_lstclear(t_list **a)
{
	t_list	*p;

	while (*a)
	{
		p = *a;
		*a = (*a)->next;
		free(p);
	}
	*a = NULL;
}

int	main(int c, char **v)
{
	t_list	*stack_a;
	t_list	*stack_b;

	if (c <= 1)
		return (0);
	stack_b = NULL;
	stack_a = ft_stack_a(v);
	if (check_sort(&stack_a) == 0)
	{
		ft_lstclear(&stack_a);
		exit(0);
	}
	sort_all(&stack_a, &stack_b);
	ft_lstclear(&stack_a);
	ft_lstclear(&stack_b);
	exit(0);
}
