/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habdella <habdella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 21:17:19 by habdella          #+#    #+#             */
/*   Updated: 2024/12/22 17:31:03 by habdella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	puterror(t_alias *kolchi)
{
	if (kolchi->stack_a)
		free_stack(&kolchi->stack_a);
	if (kolchi->stack_b)
		free_stack(&kolchi->stack_b);
	if (kolchi->split)
	{
		free_split(kolchi->split, kolchi->val);
		kolchi->split = NULL;
	}
	if (kolchi)
		free(kolchi);
	write(2, "Error\n", 6);
	exit(1);
}

int	last_check(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (s[i] == '-' || s[i] == '+')
	{
		i++;
		if (!(s[i] >= '0' && s[i] <= '9'))
			return (1);
	}
	while (s[i] >= '0' && s[i] <= '9')
		i++;
	if (s[i] != '\0')
		return (1);
	return (0);
}

int	is_sorted(t_stack *stack)
{
	t_stack	*curr;
	int		count;

	if (!stack)
		return (0);
	count = 0;
	curr = stack;
	while (curr->next)
	{
		if (curr->data > curr->next->data)
			return (0);
		count++;
		curr = curr->next;
	}
	return (++count);
}

void	initialize(t_alias *kolchi, int ac, char **av)
{
	kolchi->ac = ac;
	kolchi->av = av;
	kolchi->alen = 0;
	kolchi->blen = 0;
	kolchi->flag = 0;
	kolchi->split = NULL;
	kolchi->stack_a = NULL;
	kolchi->stack_b = NULL;
	kolchi->size = 0;
	kolchi->a_value = 0;
	kolchi->a_index = 0;
	kolchi->b_value = 0;
	kolchi->b_index = 0;
}
