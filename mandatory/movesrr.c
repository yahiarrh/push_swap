/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movesrr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrrhaibi <yrrhaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 13:45:28 by yrrhaibi          #+#    #+#             */
/*   Updated: 2023/05/16 11:21:24 by yrrhaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack **a, int flag)
{
	t_stack	*t;
	t_stack	*tmp;

	tmp = ft_lstlast(*a);
	t = *a;
	if (ft_lstsize(*a) >= 2)
	{
		while (t->next->next != NULL)
		{
			t = t->next;
		}
		tmp->next = *a;
		*a = tmp;
		t->next = NULL;
		if (flag == 1)
			ft_printf("rra\n");
	}
}

void	rrb(t_stack **b, int flag)
{
	t_stack	*t;
	t_stack	*tmp;

	tmp = ft_lstlast(*b);
	t = *b;
	if (ft_lstsize(*b) >= 2)
	{
		while (t->next->next != NULL)
		{
			t = t->next;
		}
		tmp->next = *b;
		*b = tmp;
		t->next = NULL;
		if (flag == 1)
			ft_printf("rrb\n");
	}
}

void	rrr(t_stack **a, t_stack **b)
{
	rra(a, 0);
	rrb(b, 0);
	ft_printf("rrr\n");
}
