/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movesr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrrhaibi <yrrhaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 13:45:24 by yrrhaibi          #+#    #+#             */
/*   Updated: 2023/05/08 11:51:53 by yrrhaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ra(t_stack **a)
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
	}
}

void	rb(t_stack **b)
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
	}
}

void	rr(t_stack **a, t_stack **b)
{
	ra(a);
	rb(b);
}
