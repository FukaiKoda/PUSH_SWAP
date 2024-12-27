/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position_finder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habdella <habdella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 20:48:07 by habdella          #+#    #+#             */
/*   Updated: 2024/12/22 16:05:29 by habdella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	check_part_a(t_alias *kolchi, int *best_node, int *target_val)
{
	int		best_move;
	int		curr_move;
	t_stack	*a;

	best_move = -1;
	a = kolchi->stack_a;
	while (a)
	{
		kolchi->a_value = a->data;
		kolchi->a_index = find_index(kolchi->stack_a, kolchi->a_value);
		kolchi->b_index = find_pos_b(kolchi, kolchi->a_value);
		kolchi->b_value = find_value(kolchi->stack_b, kolchi->b_index);
		curr_move = calculation(kolchi, kolchi->b_index);
		if (best_move == -1 || curr_move < best_move)
		{
			best_move = curr_move;
			*best_node = kolchi->a_value;
			*target_val = kolchi->b_value;
		}
		a = a->next;
	}
}

void	first_part_a(t_alias *kolchi)
{
	int		target_val;
	int		best_node;

	while (kolchi->alen > 3 && !is_sorted(kolchi->stack_a))
	{
		check_part_a(kolchi, &best_node, &target_val);
		move(kolchi, best_node, target_val);
		kolchi->flag = 1;
		p(kolchi);
		kolchi->alen--;
		kolchi->blen++;
	}
}

void	last_part_b(t_alias *kolchi)
{
	while (kolchi->stack_b)
	{
		kolchi->b_value = kolchi->stack_b->data;
		kolchi->b_index = find_index(kolchi->stack_b, kolchi->b_value);
		kolchi->a_index = find_pos_a(kolchi, kolchi->b_value);
		kolchi->a_value = find_value(kolchi->stack_a, kolchi->a_index);
		move_a(kolchi);
		kolchi->flag = 0;
		p(kolchi);
		kolchi->alen++;
		kolchi->blen--;
	}
}

int	find_pos_b(t_alias *kolchi, int target)
{
	t_stack	*b;
	long	tmp;
	int		i;
	int		max;
	int		indice;

	i = 0;
	b = kolchi->stack_b;
	tmp = LONG_MIN;
	indice = -1;
	max = find_max(kolchi->stack_b);
	while (b)
	{
		if (target > b->data && tmp < b->data)
		{
			tmp = b->data;
			indice = i;
		}
		b = b->next;
		i++;
	}
	if (tmp == LONG_MIN)
		return (find_index(kolchi->stack_b, max));
	return (indice);
}

int	find_pos_a(t_alias *kolchi, int target)
{
	t_stack	*a;
	long	tmp;
	int		i;
	int		min;
	int		indice;

	i = 0;
	a = kolchi->stack_a;
	tmp = LONG_MAX;
	indice = -1;
	min = find_min(kolchi->stack_a);
	while (a)
	{
		if (target < a->data && tmp > a->data)
		{
			tmp = a->data;
			indice = i;
		}
		a = a->next;
		i++;
	}
	if (tmp == LONG_MAX)
		return (find_index(kolchi->stack_a, min));
	return (indice);
}
