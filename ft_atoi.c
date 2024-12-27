/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habdella <habdella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 21:18:52 by habdella          #+#    #+#             */
/*   Updated: 2024/12/22 16:06:40 by habdella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	ft_atoi(char *s, int *flag)
{
	long	num;
	int		sign;

	(1) && (num = 0, sign = 1);
	*flag = last_check(s);
	if (*flag)
		return (-1);
	if (*s == '-' || *s == '+')
		if (*s++ == '-')
			sign *= -1;
	while (*s >= '0' && *s <= '9' && num - 10 <= INT_MAX)
	{
		num = (*s - '0') + (num * 10);
		s++;
	}
	if ((num * sign) == INT_MAX || (num * sign) == INT_MIN)
		return ((int)(num * sign));
	else if ((num * sign) > INT_MAX || (num * sign) < INT_MIN)
	{
		*flag = 1;
		return (0);
	}
	return ((int)(num * sign));
}
