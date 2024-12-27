/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_moves.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habdella <habdella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 21:16:41 by habdella          #+#    #+#             */
/*   Updated: 2024/12/22 16:15:19 by habdella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	calculation(t_alias *kolchi, int target_index)
{
	t_stack	*b;
	int		node_index;
	int		median_a;
	int		median_b;
	int		result;

	b = kolchi->stack_b;
	node_index = find_index(kolchi->stack_a, kolchi->a_value);
	median_a = kolchi->alen / 2;
	median_b = kolchi->blen / 2;
	result = 0;
	if (node_index <= median_a)
		result = node_index;
	else
		result = kolchi->alen - node_index;
	if (target_index <= median_b)
		result += target_index;
	else
		result += kolchi->blen - target_index;
	return (result);
}

void	additional_rotation(t_alias *kolchi, int node_value, char key)
{
	int	node_pos;
	int	med_a;
	int	med_b;

	med_a = kolchi->alen / 2;
	med_b = kolchi->blen / 2;
	if (key == 'a')
	{
		kolchi->flag = 0;
		node_pos = find_index(kolchi->stack_a, node_value);
		while (node_pos <= med_a && kolchi->stack_a->data != node_value)
			r(kolchi);
		while (node_pos > med_a && kolchi->stack_a->data != node_value)
			rr(kolchi);
	}
	else
	{
		kolchi->flag = 1;
		node_pos = find_index(kolchi->stack_b, node_value);
		while (node_pos <= med_b && kolchi->stack_b->data != node_value)
			r(kolchi);
		while (node_pos > med_b && kolchi->stack_b->data != node_value)
			rr(kolchi);
	}
}

void	move(t_alias *kolchi, int best_node, int target_val)
{
	int	best_node_pos;
	int	best_target_pos;
	int	med_a;
	int	med_b;

	(1) && (med_a = kolchi->alen / 2, med_b = kolchi->blen / 2);
	best_node_pos = find_index(kolchi->stack_a, best_node);
	best_target_pos = find_index(kolchi->stack_b, target_val);
	if (best_node_pos <= med_a && best_target_pos <= med_b)
	{
		while (kolchi->stack_a->data != best_node
			&& kolchi->stack_b->data != target_val)
			(void)((1) && (kolchi->flag = 2, r(kolchi), 1));
	}
	else if (best_node_pos > med_a && best_target_pos > med_b)
	{
		while (kolchi->stack_a->data != best_node
			&& kolchi->stack_b->data != target_val)
			(void)((1) && (kolchi->flag = 2, rr(kolchi), 1));
	}
	additional_rotation(kolchi, best_node, 'a');
	additional_rotation(kolchi, target_val, 'b');
}

void	move_a(t_alias *kolchi)
{
	int	med_a;
	int	node_index;

	med_a = kolchi->alen / 2;
	node_index = find_index(kolchi->stack_a, kolchi->a_value);
	kolchi->flag = 0;
	while (node_index <= med_a && kolchi->stack_a->data != kolchi->a_value)
		r(kolchi);
	while (node_index > med_a && kolchi->stack_a->data != kolchi->a_value)
		rr(kolchi);
}
