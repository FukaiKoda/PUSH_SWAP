/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_essential.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habdella <habdella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 21:16:31 by habdella          #+#    #+#             */
/*   Updated: 2024/12/24 13:29:36 by habdella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	find_min(t_stack *stack)
{
	t_stack	*a;
	int		min;

	if (!stack)
		return (-1);
	min = stack->data;
	a = stack;
	while (a)
	{
		if (min > a->data)
			min = a->data;
		a = a->next;
	}
	return (min);
}

int	find_max(t_stack *stack)
{
	t_stack	*a;
	int		max;

	if (!stack)
		return (-1);
	max = stack->data;
	a = stack;
	while (a)
	{
		if (max < a->data)
			max = a->data;
		a = a->next;
	}
	return (max);
}

int	find_index(t_stack *stack, int value)
{
	t_stack	*curr;
	int		i;

	i = 0;
	curr = stack;
	if (!stack)
		return (-1);
	while (curr)
	{
		if (value == curr->data)
			break ;
		i++;
		curr = curr->next;
	}
	return (i);
}

int	find_value(t_stack *stack, int index)
{
	t_stack	*curr;
	int		i;

	i = 0;
	curr = stack;
	if (!stack)
		return (-1);
	while (curr)
	{
		if (i == index)
			break ;
		i++;
		curr = curr->next;
	}
	return (curr->data);
}

void	ft_rotate_till_min(t_alias *kolchi)
{
	int		min;
	int		min_index;

	min = find_min(kolchi->stack_a);
	min_index = find_index(kolchi->stack_a, min);
	kolchi->flag = 0;
	if (min_index < kolchi->alen / 2)
	{
		while (kolchi->stack_a->data != min)
			r(kolchi);
	}
	else
	{
		while (kolchi->stack_a->data != min)
			rr(kolchi);
	}
}
