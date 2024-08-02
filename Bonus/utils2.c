/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felhafid <felhafid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 10:36:20 by felhafid          #+#    #+#             */
/*   Updated: 2024/05/09 18:27:20 by felhafid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

int	check_sort(t_list **a)
{
	t_list	*p;

	p = *a;
if (p == NULL)
	return (1);
	while (p->next != NULL)
	{
		if (p->content > p->next->content)
			return (1);
		p = p->next;
	}
	return (0);
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

int	ft_strcmp(char *s, char *s1)
{
	int	i;

	i = 0;
	while (s[i] || s1[i])
	{
		if (s[i] != s1[i])
			return (1);
		i++;
	}
	return (0);
}
