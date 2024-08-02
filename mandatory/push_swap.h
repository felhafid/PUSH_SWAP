/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felhafid <felhafid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 10:36:43 by felhafid          #+#    #+#             */
/*   Updated: 2024/05/05 10:01:19 by felhafid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	int				content;
	int				indix;
	struct s_list	*next;
}					t_list;

int		ft_errors(char **v);
int		ft_strlen(char *s);
char	*ft_strdup(char *s);
char	*ft_join2string(char *s, char *s1);
char	**ft_split(char *s);
long	ft_atoi(char *s);
int		ft_duplicates(char **v);
int		ft_limite(char **v);
void	frees(char **v);
t_list	*ft_new(int content);
int		ft_lstsize(t_list *lst);
void	ft_add_back(t_list **head, t_list *lst);
void	swap(t_list **lst, char *nameopr);
void	rotate(t_list **lst, char *nameopr); 
void	reverse_rotate(t_list **lst, char *nameopr);
void	push(t_list **lst, t_list **dst, char *nameopr);
void	pushmin(t_list **a, t_list **b);
int		check_sort(t_list **a);
void	sorting(t_list **a, t_list **b);
void	sort_all(t_list **a, t_list **b);

#endif
