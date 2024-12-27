/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habdella <habdella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 21:17:26 by habdella          #+#    #+#             */
/*   Updated: 2024/12/22 18:06:19 by habdella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "ft_printf.h"

void	p(t_alias *kolchi)
{
	if (!kolchi->flag)
	{
		push(&kolchi->stack_a, &kolchi->stack_b);
		ft_printf("pa\n");
	}
	else
	{
		push(&kolchi->stack_b, &kolchi->stack_a);
		ft_printf("pb\n");
	}
}

void	s(t_alias *kolchi)
{
	if (!kolchi->flag)
	{
		swap(&kolchi->stack_a);
		ft_printf("sa\n");
	}
	else if (kolchi->flag == 1)
	{
		swap(&kolchi->stack_b);
		ft_printf("sb\n");
	}
	else
	{
		swap(&kolchi->stack_a);
		swap(&kolchi->stack_b);
		ft_printf("ss\n");
	}
}

void	r(t_alias *kolchi)
{
	if (!kolchi->flag)
	{
		rotate(&kolchi->stack_a);
		ft_printf("ra\n");
	}
	else if (kolchi->flag == 1)
	{
		rotate(&kolchi->stack_b);
		ft_printf("rb\n");
	}
	else
	{
		rotate(&kolchi->stack_a);
		rotate(&kolchi->stack_b);
		ft_printf("rr\n");
	}
}

void	rr(t_alias *kolchi)
{
	if (!kolchi->flag)
	{
		rev_rotate(&kolchi->stack_a);
		ft_printf("rra\n");
	}
	else if (kolchi->flag == 1)
	{
		rev_rotate(&kolchi->stack_b);
		ft_printf("rrb\n");
	}
	else
	{
		rev_rotate(&kolchi->stack_a);
		rev_rotate(&kolchi->stack_b);
		ft_printf("rrr\n");
	}
}
