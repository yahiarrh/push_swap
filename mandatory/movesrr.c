/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movesrr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrrhaibi <yrrhaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 13:45:28 by yrrhaibi          #+#    #+#             */
/*   Updated: 2023/05/03 17:38:54 by yrrhaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack **a)
{
	t_stack	*t;
	t_stack	*tmp;

	tmp = ft_lstlast(*a);
	t = *a;
	if (*a)
	{
		while (t->next->next != NULL)
		{
			t = t->next;
		}
		tmp->next = *a;
		*a = tmp;
		t->next = NULL;
		ft_printf("rra\n");
	}
}

void	rrb(t_stack **b)
{
	t_stack	*t;
	t_stack	*tmp;

	tmp = ft_lstlast(*b);
	t = *b;
	if (*b)
	{
		while (t->next->next != NULL)
		{
			t = t->next;
		}
		tmp->next = *b;
		*b = tmp;
		t->next = NULL;
		ft_printf("rrb\n");
	}
}

void	rrr(t_stack **a, t_stack **b)
{
	rra(a);
	rrb(b);
	ft_printf("rrr\n");
}
