/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habdella <habdella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 21:17:04 by habdella          #+#    #+#             */
/*   Updated: 2024/12/22 18:09:47 by habdella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_stack	*creat(int data)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->data = data;
	new->next = NULL;
	return (new);
}

void	push(t_stack **stack, t_stack **head)
{
	t_stack	*top;

	if (!head || !*head)
		return ;
	top = *head;
	*head = top->next;
	top->next = *stack;
	*stack = top;
}

void	swap(t_stack **stack)
{
	int		tmp;
	t_stack	*head;
	t_stack	*second;

	if (!*stack || !(*stack)->next)
		return ;
	head = *stack;
	second = head->next;
	tmp = head->data;
	head->data = second->data;
	second->data = tmp;
}

void	rotate(t_stack **stack)
{
	t_stack	*head;
	t_stack	*tail;

	if (!*stack || !(*stack)->next)
		return ;
	head = *stack;
	tail = *stack;
	while (tail->next)
		tail = tail->next;
	*stack = head->next;
	tail->next = head;
	head->next = NULL;
}

void	rev_rotate(t_stack **stack)
{
	t_stack	*head;
	t_stack	*tail;

	if (!*stack || !(*stack)->next)
		return ;
	head = *stack;
	tail = *stack;
	while (tail->next->next)
		tail = tail->next;
	head = tail->next;
	tail->next = NULL;
	head->next = *stack;
	*stack = head;
}
