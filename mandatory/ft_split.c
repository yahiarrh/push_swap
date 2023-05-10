/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrrhaibi <yrrhaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 13:46:00 by yrrhaibi          #+#    #+#             */
/*   Updated: 2023/05/05 15:41:07 by yrrhaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**dealc(char **s, int i)
{
	while (i >= 0)
	{
		free(s[i]);
		i--;
	}
	free(s);
	s = NULL;
	return (s);
}

static	int	count_word(char const *s, char c)
{
	int	j;
	int	num;
	int	m;

	m = 0;
	j = 0;
	num = 0;
	while (s[j])
	{
		if (s[j] != c)
			m++;
		if (s[j] == c && s[j + 1] != c && s[j + 1])
			num++;
		j++;
	}
	if (num == 0 && m != 0)
		num++;
	return (num);
}

static	char	*give_word(char const *s, char c)
{
	char	*ret;
	int		f;

	f = 0;
	while (s[f] && s[f] != c)
		f++;
	ret = (char *)malloc(f + 1);
	if (!ret)
		return (NULL);
	f = 0;
	while (s[f] != c && s[f])
	{
		ret[f] = s[f];
		f++;
	}
	ret[f] = '\0';
	return (ret);
}

char	**ft_split(char const *s, char c)
{
	char	**word;
	size_t	count;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	count = count_word(s, c);
	word = malloc(sizeof(char *) * (count + 2));
	if (!word)
		return (NULL);
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			word[i++] = give_word(s, c);
			if (!*word)
				return (dealc(word, i));
			while (*s && *s != c)
				s++;
		}
	}
	return (word[i] = NULL, word);
}
