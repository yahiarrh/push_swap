/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   applic_alg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrrhaibi <yrrhaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 18:17:46 by yrrhaibi          #+#    #+#             */
/*   Updated: 2023/05/10 18:45:43 by yrrhaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	re_b(t_stack **a, t_stack **b, int pv1)
{
	if ((*a)->index <= pv1)
	{
		pb(a, b);
		return (1);
	}
	else
		ra(a, 1);
	return (0);
}

void	send_b(t_stack **a, t_stack **b, int pv1, int pv2)
{
	int		count;
	long	ppv2;

	count = 0;
	ppv2 = -1e12;
	while (ft_lstsize(*a) > 3)
	{
		if (ft_lstsize(*b) > 1 && (*b)->index <= pv2
			&& (*b)->index > ppv2 && (*a)->index > pv1)
			rr(a, b);
		else if (ft_lstsize(*b) > 1 && (*b)->index <= pv2 && (*b)->index > ppv2)
			rb(b, 1);
		count += re_b(a, b, pv1);
		if (count == pv1)
		{
			ppv2 = pv2;
			pv2 = (ft_lstsize(*a) / 6) + pv1;
			pv1 += ft_lstsize(*a) / 3;
		}
	}
}

static int	upper_pos(t_stack **a, t_stack **b, int flag)
{
	while (((*a)->index - 1) != (*b)->index)
	{
		if (flag || ft_lstlast(*a)->index < (*b)->index)
		{
			flag = 0;
			pa(a, b);
			ra(a, 1);
		}
		else
			rrb(b);
	}
	pa(a, b);
	return (flag);
}

static int	lower_pos(t_stack **a, t_stack **b, int flag)
{
	while (((*a)->index - 1) != (*b)->index)
	{
		if (flag || ft_lstlast(*a)->index < (*b)->index)
		{
			flag = 0;
			pa(a, b);
			ra(a, 1);
		}
		else
			rb(b, 1);
	}
	pa(a, b);
	return (flag);
}

void	send_a(t_stack **a, t_stack **b)
{
	int	pos;
	int	flag;

	while (*b)
	{
		pos = position(b, ((*a)->index - 1));
		if (pos == 1)
			sb(b);
		else if (pos > (ft_lstsize(*b) / 2))
		{
			flag = upper_pos(a, b, flag);
		}
		else if (pos <= (ft_lstsize(*b) / 2))
		{
			flag = lower_pos(a, b, flag);
		}
		while (ft_lstlast(*a)->index == (*a)->index - 1)
		{
			rra(a);
		}
		if (ft_lstlast(*a)->index > (*a)->index)
			flag = 1;
	}
}
