/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felhafid <felhafid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 10:35:56 by felhafid          #+#    #+#             */
/*   Updated: 2024/05/09 11:41:57 by felhafid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_duplicates(char **v)
{
	int	i;
	int	j;

	i = 0;
	while (v[i])
	{
		j = i + 1;
		while (v[j])
		{
			if (ft_atoi(v[i]) == ft_atoi(v[j]))
			{
				write(2, "Error\n", 6);
				frees(v);
				return (0);
			}
			j++;
		}
		i++;
	}
	frees(v);
	return (1);
}

int	ft_checkspaces(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] != ' ')
			return (1);
		i++;
	}
	return (0);
}

int	ft_checkdigit(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if ((s[i] == '-' || s[i] == '+') && !(s[i + 1] >= '0'
				&& s[i + 1] <= '9' && (s[i - 1] == ' ' || i - 1 == -1)))
			return (0);
		else if ((!(s[i] >= '0' && s[i] <= '9'))
			&& s[i] != ' ' && s[i] != '+' && s[i] != '-')
			return (0);
		i++;
	}
	return (1);
}

int	ft_limite(char **v)
{
	int	i;

	i = 0;
	while (v[i])
	{
		if (ft_atoi(v[i]) > 2147483647 || ft_atoi(v[i]) < -2147483648)
		{
			write(2, "Error\n", 6);
			frees(v);
			return (0);
		}
		i++;
	}
	frees(v);
	return (1);
}

int	ft_errors(char **v)
{
	int	i;

	i = 1;
	while (v[i])
	{
		if (ft_checkspaces(v[i]) == 0 || ft_checkdigit(v[i]) == 0)
		{
			write(2, "Error\n", 6);
			return (0);
		}
		i++;
	}
	return (1);
}
