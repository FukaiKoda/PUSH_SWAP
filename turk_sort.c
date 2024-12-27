/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habdella <habdella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 21:07:17 by habdella          #+#    #+#             */
/*   Updated: 2024/12/21 21:43:14 by habdella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	sort_stack(t_alias *kolchi)
{
	if (kolchi->alen == 2)
	{
		kolchi->flag = 0;
		s(kolchi);
		return ;
	}
	if (kolchi->alen == 3)
	{
		three_element(kolchi);
		return ;
	}
	else
		turk_sort(kolchi);
}

void	three_element_cond(t_alias *kolchi, t_stack *a, t_stack *b, t_stack *c)
{
	if (a->data > b->data && a->data > c->data)
	{
		if (b->data < c->data)
			r(kolchi);
		else
			(s(kolchi), rr(kolchi));
	}
	else if (a->data < b->data && a->data < c->data)
		(s(kolchi), r(kolchi));
	else if (b->data < a->data && b->data < c->data)
	{
		if (a->data < c->data)
			s(kolchi);
		else
			rr(kolchi);
	}
	else if (c->data < a->data && c->data < b->data)
	{
		if (a->data > b->data)
			(s(kolchi), rr(kolchi));
		else
			rr(kolchi);
	}
}

void	three_element(t_alias *kolchi)
{
	t_stack	*a;
	t_stack	*b;
	t_stack	*c;

	if (is_sorted(kolchi->stack_a))
		return ;
	a = kolchi->stack_a;
	b = a->next;
	c = b->next;
	kolchi->flag = 0;
	three_element_cond(kolchi, a, b, c);
}

void	turk_sort(t_alias *kolchi)
{
	if (!is_sorted(kolchi->stack_a) && kolchi->alen >= 4)
	{
		kolchi->flag = 1;
		p(kolchi);
		if (!is_sorted(kolchi->stack_a) && kolchi->alen > 4)
		{
			p(kolchi);
			kolchi->alen--;
			kolchi->blen++;
		}
		kolchi->alen--;
		kolchi->blen++;
	}
	first_part_a(kolchi);
	if (!is_sorted(kolchi->stack_a))
		sort_stack(kolchi);
	last_part_b(kolchi);
	ft_rotate_till_min(kolchi);
}
