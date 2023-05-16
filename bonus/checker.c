/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrrhaibi <yrrhaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 10:48:07 by yrrhaibi          #+#    #+#             */
/*   Updated: 2023/05/16 11:14:25 by yrrhaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	empty_stack(t_stack *a, t_stack *b, int flag)
{
	if (flag == 1)
	{
		while (a)
		{
			free(a);
			a = a->next;
		}
	}
	else if (flag == 2)
	{
		while (a)
		{
			free(a);
			a = a->next;
		}
		while (b)
		{
			free(b);
			b = b->next;
		}
	}
}

void	both(t_stack **a, t_stack **b)
{
	empty_stack(*a, *b, 2);
	ft_error();
}

int	r_mov(char *instruct, t_stack **a, t_stack **b)
{
	if (!ft_strcmp(instruct, "ra\n"))
		ra(a);
	else if (!ft_strcmp(instruct, "rb\n"))
		rb(b);
	else if (!ft_strcmp(instruct, "rr\n"))
		rr(a, b);
	else if (!ft_strcmp(instruct, "rra\n"))
		rra(a);
	else if (!ft_strcmp(instruct, "rrb\n"))
		rrb(b);
	else if (!ft_strcmp(instruct, "rrr\n"))
		rrr(a, b);
	else if (!ft_strcmp(instruct, "sb\n"))
		sb(b);
	else if (!ft_strcmp(instruct, "ss\n"))
		ss(a, b);
	else
		return (0);
	return (1);
}

int	ft_test(t_stack **a, t_stack **b)
{
	char	*instruct;
	int		count;

	count = 0;
	instruct = get_next_line(0);
	while (instruct)
	{
		if (!ft_strcmp(instruct, "pa\n"))
			pa(a, b);
		else if (!ft_strcmp(instruct, "pb\n"))
			pb(a, b);
		else if (!ft_strcmp(instruct, "sa\n"))
			sa(a);
		else
			if (!r_mov(instruct, a, b))
				both(a, b);
		free(instruct);
		instruct = get_next_line(0);
		count++;
	}
	if (count != 0)
		return (0);
	else if (count == 0 && !instruct)
		return (0);
	return (1);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (ac == 1)
		exit(1);
	else
	{
		fill_nod(&a, av, ac);
		check_dup(a);
		if (!ft_test(&a, &b))
		{		
			if (!if_sort(&a) && !b)
				write(1, "OK\n", 3);
			else
				write(1, "KO\n", 3);
		}
		empty_stack(a, b, 2);
	}
}
