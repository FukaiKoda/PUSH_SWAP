/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habdella <habdella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 13:11:03 by habdella          #+#    #+#             */
/*   Updated: 2024/12/24 10:32:18 by habdella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*f_strchr(const char *s, char c)
{
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == c)
			return ((char *)(s + i));
		i++;
	}
	return (NULL);
}

char	*ft_strdup(const char *s)
{
	char	*p;
	int		i;
	int		len;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	p = malloc(len + 1);
	if (!p)
		return (NULL);
	i = 0;
	while (i < len)
	{
		p[i] = s[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	int		i;
	int		j;
	size_t	len;
	char	*p;

	if (!s1 && !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	p = malloc(len + 1);
	if (!p)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		p[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		p[i++] = s2[j];
		j++;
	}
	p[i] = '\0';
	return (p);
}

char	*ft_strdupnl(char *contain)
{
	char	*line;
	int		i;
	int		j;

	if (!contain)
		return (NULL);
	i = 0;
	while (contain[i] && contain[i] != '\n')
		i++;
	if (contain[i] != '\0')
		i++;
	line = malloc(i + 1);
	if (!line)
		return (NULL);
	j = 0;
	while (j < i)
	{
		line[j] = contain[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}
