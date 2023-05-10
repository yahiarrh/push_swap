/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movesr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrrhaibi <yrrhaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 13:45:24 by yrrhaibi          #+#    #+#             */
/*   Updated: 2023/05/10 16:29:28 by yrrhaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack **a, int bo)
{
	t_stack	*tmp;
	t_stack	*tmp1;

	tmp1 = *a;
	if (*a != NULL)
	{
		tmp = ft_lstlast(*a);
		*a = tmp1->next;
		tmp1->next = NULL;
		tmp->next = tmp1;
		if (bo)
			ft_printf("ra\n");
	}
}

void	rb(t_stack **b, int bo)
{
	t_stack	*tmp;
	t_stack	*tmp1;

	tmp1 = *b;
	if (*b != NULL)
	{
		tmp = ft_lstlast(*b);
		*b = tmp1->next;
		tmp1->next = NULL;
		tmp->next = tmp1;
		if (bo)
			ft_printf("rb\n");
	}
}

void	rr(t_stack **a, t_stack **b)
{
	ra(a, 0);
	rb(b, 0);
	ft_printf("rr\n");
}
