/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felhafid <felhafid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 10:36:43 by felhafid          #+#    #+#             */
/*   Updated: 2024/05/06 12:25:29 by felhafid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 13
# endif

# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}					t_list;

char	*get_next_line(int fd);
char	*ft_afterline(char *s);
char	*ft_strjoin(char *s, char *s1);
int		ft_errors(char **v);
int		ft_strlen(char *s);
char	*ft_strdup(char *s);
char	*ft_join2string(char *s, char *s1);
char	**ft_split(char *s);
long	ft_atoi(char *s);
int		ft_duplicates(char **v);
int		ft_limite(char **v);
void	frees(char **v);
void	ft_lstclear(t_list **a);
t_list	*ft_stack_a(char **v);
t_list	*ft_new(int content);
int		ft_lstsize(t_list *lst);
void	ft_add_back(t_list **head, t_list *lst);
void	swap(t_list **lst);
void	swap_both(t_list **lst, t_list **dst);
void	rotate(t_list **lst);
void	rotate_both(t_list **lst, t_list **dst);
void	reverse_rotate(t_list **lst);
void	reverse_rotate_both(t_list **lst, t_list **dst);
void	push(t_list **lst, t_list **dst);
int		check_sort(t_list **a);
int		ok_or_ko(t_list **a, t_list **b);
int		ft_strcmp(char *s, char *s1);

#endif
