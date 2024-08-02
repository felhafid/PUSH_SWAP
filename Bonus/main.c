/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felhafid <felhafid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 12:16:18 by felhafid          #+#    #+#             */
/*   Updated: 2024/05/09 18:29:15 by felhafid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
	{
		ft_add_back(&stack_a, ft_new(ft_atoi(str[i++])));
	}
	return (frees(str), free(s), stack_a);
}

int	ft_cases(t_list **a, t_list **b, char *move)
{
	if (ft_strcmp("sa\n", move) == 0)
		return (swap(a), 1);
	else if (ft_strcmp("sb\n", move) == 0)
		return (swap(b), 1);
	else if (ft_strcmp("ss\n", move) == 0)
		return (swap_both(a, b), 1);
	else if (ft_strcmp("ra\n", move) == 0)
		return (rotate(a), 1);
	else if (ft_strcmp("rb\n", move) == 0)
		return (rotate(b), 1);
	else if (ft_strcmp("rr\n", move) == 0)
		return (rotate_both(a, b), 1);
	else if (ft_strcmp("rra\n", move) == 0)
		return (reverse_rotate(a), 1);
	else if (ft_strcmp("rrb\n", move) == 0)
		return (reverse_rotate(b), 1);
	else if (ft_strcmp("rrr\n", move) == 0)
		return (reverse_rotate_both(a, b), 1);
	else if (ft_strcmp("pa\n", move) == 0)
		return (push(b, a), 1);
	else if (ft_strcmp("pb\n", move) == 0)
		return (push(a, b), 1);
	return (0);
}

int	ok_or_ko(t_list **a, t_list **b)
{
	char	*s;

	s = get_next_line(0);
	while (s)
	{
		if (ft_cases(a, b, s) == 0)
		{
			write(2, "Error\n", 6);
			free(s);
			return (0);
		}
		free(s);
		s = get_next_line(0);
	}
	if (check_sort(a) == 0 && ft_lstsize(*b) == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free(s);
	return (0);
}

int	main(int c, char **v)
{
	t_list	*stack_a;
	t_list	*stack_b;

	if (c <= 1)
		return (0);
	stack_b = NULL;
	stack_a = ft_stack_a(v);
	ok_or_ko(&stack_a, &stack_b);
	ft_lstclear(&stack_a);
	ft_lstclear(&stack_b);
	exit(0);
}
