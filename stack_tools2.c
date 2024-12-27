/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_tools2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habdella <habdella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 21:16:56 by habdella          #+#    #+#             */
/*   Updated: 2024/12/22 19:19:49 by habdella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	free_stack(t_stack **stack)
{
	t_stack	*prv;
	t_stack	*curr;

	if (!*stack || !stack)
		return ;
	curr = *stack;
	while (curr)
	{
		prv = curr->next;
		free(curr);
		curr = prv;
	}
	*stack = NULL;
}

void	push_tail(t_stack **stack, t_stack *new_node)
{
	t_stack	*curr;

	curr = *stack;
	if (!new_node)
		return ;
	if (!*stack)
	{
		*stack = new_node;
		return ;
	}
	while (curr->next)
		curr = curr->next;
	curr->next = new_node;
}

int	check_duplicate(t_stack *stack)
{
	t_stack	*a;
	t_stack	*b;

	if (!stack)
		return (0);
	a = stack;
	while (a->next)
	{
		b = a->next;
		while (b)
		{
			if (a->data == b->data)
				return (-1);
			b = b->next;
		}
		a = a->next;
	}
	return (1);
}

void	check_input_a(t_alias *kolchi)
{
	t_stack	*a;
	int		i;

	i = 0;
	a = kolchi->stack_a;
	while (i < kolchi->size)
	{
		kolchi->val = ft_atoi(kolchi->split[i], &kolchi->flag);
		if (kolchi->flag)
		{
			free_split(kolchi->split, kolchi->size);
			kolchi->split = NULL;
			puterror(kolchi);
		}
		a = creat(kolchi->val);
		push_tail(&kolchi->stack_a, a);
		i++;
	}
	kolchi->alen += i;
	free_split(kolchi->split, kolchi->size);
	kolchi->split = NULL;
}

int	check_input(t_alias *kolchi)
{
	int		j;

	j = 1;
	while (j < kolchi->ac)
	{	
		kolchi->split = ft_split(kolchi->av[j], ' ', &kolchi->size);
		if (!kolchi->split)
			puterror(kolchi);
		check_input_a(kolchi);
		j++;
	}
	if (check_duplicate(kolchi->stack_a) == -1)
		return (-1);
	return (1);
}
