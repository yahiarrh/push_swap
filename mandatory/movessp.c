/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movessp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrrhaibi <yrrhaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 13:45:40 by yrrhaibi          #+#    #+#             */
/*   Updated: 2023/05/12 11:45:14 by yrrhaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **a)
{
	t_stack	*tmp;
	t_stack	*tmp1;

	tmp = NULL;
	tmp1 = *a;
	if (*a != NULL && ft_lstsize(*a) > 1)
	{
		tmp = ft_lstnew(tmp1->next->num);
		tmp->index = tmp1->next->index;
		tmp1->next->num = tmp1->num;
		tmp1->next->index = tmp1->index;
		tmp1->num = tmp->num;
		tmp1->index = tmp->index;
		ft_printf("sa\n");
		free(tmp);
		tmp = NULL;
	}
}

void	sb(t_stack **b)
{
	t_stack	*tmp;
	t_stack	*tmp1;

	tmp = NULL;
	tmp1 = *b;
	if (*b != NULL && ft_lstsize(*b) > 1)
	{
		tmp = ft_lstnew(tmp1->next->num);
		tmp->index = tmp1->next->index;
		tmp1->next->num = tmp1->num;
		tmp1->next->index = tmp1->index;
		tmp1->num = tmp->num;
		tmp1->index = tmp->index;
		ft_printf("sb\n");
		free(tmp);
		tmp = NULL;
	}
}

void	ss(t_stack **a, t_stack **b)
{
	sa(a);
	sb(b);
	ft_printf("ss\n");
}

void	pa(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	int		index;

	if (ft_lstsize(*b) >= 1)
	{
		tmp = *b;
		*b = (*b)->next;
		tmp->next = NULL;
		index = tmp->index;
		ft_lstadd_front(a, tmp);
		(*a)->index = index;
		ft_printf("pa\n");
	}
}

void	pb(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	int		index;

	tmp = *a;
	*a = (*a)->next;
	tmp->next = NULL;
	index = tmp->index;
	if (*a != NULL)
	{
		if (!*b || !b)
			*b = tmp;
		else
			ft_lstadd_front(b, tmp);
		(*b)->index = index;
		ft_printf("pb\n");
	}
}
