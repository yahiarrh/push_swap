/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrrhaibi <yrrhaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 17:21:23 by yrrhaibi          #+#    #+#             */
/*   Updated: 2023/05/06 20:40:15 by yrrhaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min(t_stack **a)
{
	t_stack	*t;
	int		min;
	int		pos;

	t = *a;
	min = 2147483647;
	pos = 0;
	while (t)
	{
		if (min > t->num && t->index == 0)
			min = t->num;
		t = t->next;
	}
	return (min);
}

int	position(t_stack **a, int min)
{
	t_stack	*t;
	int		i;

	i = 0;
	t = *a;
	while (t && t->index != min)
	{
		i++;
		t = t->next;
	}
	return (i);
}

int	if_sort(t_stack **a)
{
	t_stack	*t;

	t = *a;
	while (t != NULL)
	{
		if (t->next == NULL)
			break ;
		if (t->num > t->next->num)
			return (1);
		t = t->next;
	}
	return (0);
}

int	min_index(t_stack **a)
{
	t_stack	*t;
	int		min;

	t = *a;
	min = 2147483647;
	while (t)
	{
		if (min > t->index)
			min = t->index;
		t = t->next;
	}
	return (min);
}

void	fill_nod(t_stack **a, char **av, int ac)
{
	t_stack	*h;
	char	*s;
	char	*ts;
	char	**t;
	int		i;

	i = 1;
	s = NULL;
	while (i < ac)
	{
		ts = s;
		s = ft_strjoin(s, av[i++]);
		free(ts);
	}
	ts = s;
	t = ft_split(s, ' ');
	free(ts);
	i = 0;
	while (t[i])
	{
		h = ft_lstnew(ft_atoi(t[i++]));
		ft_lstadd_back(a, h);
		h->index = 0;
	}
	dealc (t, i);
}
