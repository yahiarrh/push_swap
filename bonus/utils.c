/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrrhaibi <yrrhaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 11:51:13 by yrrhaibi          #+#    #+#             */
/*   Updated: 2023/05/14 15:47:06 by yrrhaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
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
		s = ft_strjoinn(s, av[i++]);
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

void	check_dup(t_stack *a)
{
	t_stack	*tmp;

	tmp = NULL;
	while (a != NULL)
	{
		tmp = a->next;
		while (a->num != ' ' && tmp != NULL)
		{
			if (a->num == tmp->num)
			{
				empty_stack(a, 0, 1);
				ft_error();
			}
			tmp = tmp->next;
		}
		a = a->next;
	}
	return ;
}

long	ft_atoi(const char *str)
{
	int		i;
	long	r;
	int		s;

	i = 0;
	r = 0;
	s = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-')
	{
		s = -1;
		i++;
	}	
	else if (str[i] == '+')
		i++;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
		r = (r * 10) + (str[i++] - '0');
	if ((str[i] < 48 || str[i] > 57) && str[i])
		ft_error();
	else if (r > 2147483647 || r < -2147483648)
		ft_error();
	return (r * s);
}
