/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habdella <habdella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 21:18:12 by habdella          #+#    #+#             */
/*   Updated: 2024/12/22 14:49:57 by habdella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

static	int	count_words(const char *s, char c)
{
	int	i;
	int	flag;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		flag = 1;
		while (s[i] && s[i] == c)
			i++;
		while (s[i] && s[i] != c)
		{
			if (flag)
				count++;
			flag = 0;
			i++;
		}
	}
	return (count);
}

static	int	ft_len(const char *s, int i)
{
	int	count;

	count = 0;
	if (!s)
		return (0);
	while (s[i] && s[i] != ' ')
	{
		count++;
		i++;
	}
	return (count);
}

char	*ft_strduplen(char *s, int len)
{
	int		i;
	char	*p;

	i = 0;
	p = (char *)malloc(len + 1);
	if (!p)
		return (NULL);
	while (i < len)
	{
		p[i] = s[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

void	free_split(char **p, int count)
{
	int	i;

	i = 0;
	if (!p || !*p)
		return ;
	while (i < count)
	{
		free(p[i]);
		p[i] = NULL;
		i++;
	}
	free(p);
	p = NULL;
}

char	**ft_split(char *s, char c, int *size)
{
	char	**p;
	int		k;
	int		i;

	*size = count_words(s, c);
	if (*size == 0 || !s)
		return (NULL);
	p = malloc(sizeof(char *) * (*size + 1));
	if (!p)
		return (NULL);
	k = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
		{
			p[k++] = ft_strduplen(&s[i], ft_len(s, i));
			i += ft_len(s, i);
		}
	}
	p[k] = NULL;
	return (p);
}
