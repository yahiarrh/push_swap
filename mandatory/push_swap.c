/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrrhaibi <yrrhaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 13:45:00 by yrrhaibi          #+#    #+#             */
/*   Updated: 2023/05/10 18:00:19 by yrrhaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_move(t_stack **a, int i)
{
	t_stack	*b;

	b = NULL;
	if (i == 3)
		threemov(a);
	else if (i == 5)
		fivemov(a, &b);
	else if (i > 5)
		more_mov(a, &b);
}

void	ft_indexing(t_stack **a)
{
	t_stack	*t;
	t_stack	*tm;
	int		min;
	int		i;

	i = 1;
	tm = *a;
	while (tm)
	{
		t = *a;
		min = find_min(a);
		while (t)
		{
			if (t->num == min)
			{
				t->index = i;
				i++;
			}
			t = t->next;
		}
		tm = tm->next;
	}
}

void	check_dup(t_stack *a)
{
	t_stack	*tmp;

	tmp = NULL;
	while (a != NULL)
	{
		tmp = a->next;
		while (tmp != NULL)
		{
			if (a->num == tmp->num)
				ft_error();
			tmp = tmp->next;
		}
		a = a->next;
	}
	return ;
}

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	int		i;

	i = 1;
	a = NULL;
	if (ac == 1)
	{
		exit(1);
	}
	else
	{
		fill_nod(&a, av, ac);
		check_dup(a);
		if (!if_sort(&a))
			return (0);
		ft_indexing(&a);
		i = ft_lstsize(a);
		ft_move(&a, i);
	}
}
