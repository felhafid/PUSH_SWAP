/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felhafid <felhafid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 10:35:24 by felhafid          #+#    #+#             */
/*   Updated: 2024/05/06 18:56:49 by felhafid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

char	*ft_space(char *s, char c)
{
	int		i;
	char	*str;

	i = 0;
	while (s[i])
		i++;
	str = malloc(i + 2);
	i = 0;
	str[0] = c;
	while (s[i])
	{
		str[i + 1] = s[i];
		i++;
	}
	str[i + 1] = '\0';
	return (str);
}

int	checkword(char *s)
{
	int	i;
	int	word;

	if (!s) 
		return (0);
	i = 0;
	word = 0;
	while (s[i])
	{
		if ((s[i] == ' ' && s[i + 1] != ' ' && s[i + 1] != '\0') 
			|| (i == 0 && s[i] != ' '))
			word++;
		i++;
	}
	return (word);
}

char	**allocation(char *s, char **v, int i)
{
	int		j;
	int		k;
	int		o;

	j = 0;
	while (i < checkword(s))
	{
		while (s[j] && s[j] == ' ' )
			j++;
		k = 0;
		while (s[j + k] && s[j + k] != ' ')
			k++;
		v[i] = malloc(k + 1);
		if (!v[i])
			return (NULL);
		o = 0;
		while (s[j] && s[j] != ' ' && o < k)
			v[i][o++] = s[j++];
		v[i][o] = '\0';
		i++;
	}
	v[i] = NULL;
	return (v);
}

char	**ft_split(char *s)
{
	int		i;
	char	**v;

	i = 0;
	v = NULL;
	v = malloc((checkword(s) + 1) * sizeof(char *));
	if (!v) 
		return (NULL);
	return (allocation(s, v, i));
}

char	*ft_join2string(char *s, char *s1)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	if (s1 == NULL && s == NULL)
		return (NULL);
	if (!s)
		return (ft_strdup(s1));
	if (!s1)
		return (s);
	s1 = ft_space(s1, ' ');
	str = malloc(ft_strlen(s) + ft_strlen(s1) + 1);
	if (!str)
		return (NULL);
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	j = 0;
	while (s1[j])
		str[i++] = s1[j++];
	str[i] = '\0';
	return (free(s1), free(s), str);
}
