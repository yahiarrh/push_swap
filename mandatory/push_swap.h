/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrrhaibi <yrrhaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 13:45:51 by yrrhaibi          #+#    #+#             */
/*   Updated: 2023/05/11 15:24:12 by yrrhaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct s_stack {
	struct s_stack	*next;
	int				index;
	long			num;
}	t_stack;

t_stack		*ft_lstlast(t_stack *lst);
t_stack		*ft_lstnew(long content);
void		fill_nod(t_stack **a, char **av, int ac);
void		ft_lstadd_back(t_stack **lst, t_stack *new);
void		ft_lstadd_front(t_stack **lst, t_stack *new);
int			ft_lstsize(t_stack *lst);
char		*ft_strjoin(char *s1, char *s2);
char		**dealc(char **s, int i);
size_t		ft_strlen(const char *c);
int			ft_printf(const char *arg, ...);
char		**ft_split(char const *s, char c);
void		ft_error(void);
long		ft_atoi(const char *str);
void		sa(t_stack **a);
void		sb(t_stack **b);
void		ss(t_stack **a, t_stack **b);
void		pa(t_stack **a, t_stack **b);
void		pb(t_stack **a, t_stack **b);
void		ra(t_stack **a, int bo);
void		rb(t_stack **b, int bo);
void		rr(t_stack **a, t_stack **b);
void		rra(t_stack **a);
void		rrb(t_stack **b);
void		rrr(t_stack **a, t_stack **b);
void		threemov(t_stack **a);
void		fivemov(t_stack **a, t_stack **b);
void		more_mov(t_stack **a, t_stack **b);
int			find_min(t_stack **a);
int			min_index(t_stack **a);
int			position(t_stack **a, int min);
int			if_sort(t_stack **a);
void		ft_indexing(t_stack **a);
void		check_dup(t_stack *a);
void		send_b(t_stack **a, t_stack **b, int pv1, int pv2);
void		send_a(t_stack **a, t_stack **b);

#endif