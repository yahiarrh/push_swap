/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrrhaibi <yrrhaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 09:56:45 by yrrhaibi          #+#    #+#             */
/*   Updated: 2023/05/12 11:44:09 by yrrhaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	threemov(t_stack **a)
{
	if ((*a)->num > (*a)->next->num && (*a)->next->num < (*a)->next->next->num
		&& (*a)->num < (*a)->next->next->num)
		sa(a);
	else if ((*a)->num > (*a)->next->num
		&& (*a)->next->num > (*a)->next->next->num
		&& (*a)->num > (*a)->next->next->num)
	{
		sa(a);
		rra(a);
	}
	else if ((*a)->num > (*a)->next->num
		&& (*a)->next->num < (*a)->next->next->num
		&& (*a)->num > (*a)->next->next->num)
		ra(a, 1);
	else if ((*a)->num < (*a)->next->num
		&& (*a)->next->num > (*a)->next->next->num
		&& (*a)->num < (*a)->next->next->num)
	{
		sa(a);
		ra(a, 1);
	}
	else if ((*a)->num < (*a)->next->num
		&& (*a)->next->num > (*a)->next->next->num
		&& (*a)->num > (*a)->next->next->num)
		rra(a);
}

void	more_mov(t_stack **a, t_stack **b)
{
	int		pv1;
	int		pv2;

	pv2 = ft_lstsize(*a) / 12;
	pv1 = ft_lstsize(*a) / 6;
	send_b(a, b, pv1, pv2);
	threemov(a);
	send_a(a, b);
}
