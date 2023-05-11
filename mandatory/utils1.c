/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrrhaibi <yrrhaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 13:45:57 by yrrhaibi          #+#    #+#             */
/*   Updated: 2023/05/10 19:06:51 by yrrhaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_check(char *f)
{
	size_t	ct;

	ct = 0;
	if (ft_strlen(f) == 0)
		ft_error();
	while (f[ct] && f[ct] == ' ')
		ct++;
	if (ft_strlen(f) == ct)
		ft_error();
	else
		return ;
}

size_t	ft_strlen(const char *c)
{
	size_t	i;

	i = 0;
	if (!c)
		return (0);
	while (c[i])
		i++;
	return (i);
}

static char	*ft_strdup(const char *s)
{
	char	*d;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(s);
	d = (char *)malloc((len + 1) * sizeof(char));
	if (!d)
		return (NULL);
	while (s[i])
	{
		d[i] = s[i];
			i++;
	}
	d[i] = '\0';
	return (d);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ret;
	int		j;

	j = 0;
	if (!s1 && !s2)
		return (NULL);
	ft_check(s2);
	if (!s1)
	{
		ret = ft_strdup(s2);
		return (ret);
	}
	ret = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 2) * sizeof(char));
	if (!ret)
		return (NULL);
	while (*s1)
		ret[j++] = *s1++;
	if (!s2)
		return (ret);
	ret[j++] = ' ';
	while (*s2)
		ret[j++] = *s2++;
	ret[j] = '\0';
	return (ret);
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
	r *= s;
	if ((str[i] < 48 || str[i] > 57) && str[i])
		ft_error();
	else if (r > 2147483647 || r < -2147483648)
		ft_error();
	return (r);
}
