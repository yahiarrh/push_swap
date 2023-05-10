/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrrhaibi <yrrhaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 14:41:32 by yrrhaibi          #+#    #+#             */
/*   Updated: 2023/05/10 18:03:38 by yrrhaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static size_t	ft_strlenn(const char *c)
{
	size_t	i;

	i = 0;
	if (!c)
		return (0);
	while (c[i])
		i++;
	return (i);
}

static char	*ft_strdupp(const char *s)
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

char	*ft_strjoinn(char *s1, char *s2)
{
	char	*ret;
	int		j;

	j = 0;
	if (!s1 && !s2)
		return (NULL);
	ft_check(s2);
	if (!s1)
	{
		ret = ft_strdupp(s2);
		return (ret);
	}
	ret = (char *)malloc((ft_strlenn(s1) + ft_strlenn(s2) + 2) * sizeof(char));
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
