/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrrhaibi <yrrhaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 11:34:21 by yrrhaibi          #+#    #+#             */
/*   Updated: 2023/05/14 15:52:06 by yrrhaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "../gnl/get_next_line.h"

typedef struct s_stack {
	struct s_stack	*next;
	int				index;
	long			num;
}	t_stack;

t_stack		*ft_lstnew(long content);
t_stack		*ft_lstlast(t_stack *lst);
void		ft_lstadd_back(t_stack **lst, t_stack *new);
int			ft_lstsize(t_stack *lst);
void		ft_lstadd_front(t_stack **lst, t_stack *new);
int			if_sort(t_stack **a);
void		ft_error(void);
void		sa(t_stack **a);
void		sb(t_stack **b);
void		ss(t_stack **a, t_stack **b);
void		pa(t_stack **a, t_stack **b);
void		pb(t_stack **a, t_stack **b);
void		ra(t_stack **a);
void		rb(t_stack **b);
void		rr(t_stack **a, t_stack **b);
void		rra(t_stack **a);
void		rrb(t_stack **b);
void		rrr(t_stack **a, t_stack **b);
int			ft_strcmp(char *s1, char *s2);
int			r_mov(char *instruct, t_stack **a, t_stack **b);
int			ft_test(t_stack **a, t_stack **b);
void		fill_nod(t_stack **a, char **av, int ac);
void		check_dup(t_stack *a);
char		**dealc(char **s, int i);
char		**ft_split(char const *s, char c);
long		ft_atoi(const char *str);
char		*ft_strjoinn(char *s1, char *s2);
void		empty_stack(t_stack *a, t_stack *b, int flag);
#endif