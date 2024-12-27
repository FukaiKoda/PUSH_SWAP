/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habdella <habdella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 13:36:46 by habdella          #+#    #+#             */
/*   Updated: 2024/12/24 11:15:20 by habdella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "get_next_line.h"
#include "ft_printf.h"

int	ft_strncmp(char *s1, char *s2, int n)
{
	int		i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	if (n == i)
		return (0);
	return (s1[i] - s2[i]);
}

void	check_instruct(t_alias *kolchi, char *instruct)
{
	if (!ft_strncmp(instruct, "sa\n", 3))
		return (swap(&kolchi->stack_a));
	else if (!ft_strncmp(instruct, "sb\n", 3))
		return (swap(&kolchi->stack_b));
	else if (!ft_strncmp(instruct, "ss\n", 3))
		return (swap(&kolchi->stack_a), swap(&kolchi->stack_b));
	else if (!ft_strncmp(instruct, "pa\n", 3))
		return (push(&kolchi->stack_a, &kolchi->stack_b));
	else if (!ft_strncmp(instruct, "pb\n", 3))
		return (push(&kolchi->stack_b, &kolchi->stack_a));
	else if (!ft_strncmp(instruct, "ra\n", 3))
		return (rotate(&kolchi->stack_a));
	else if (!ft_strncmp(instruct, "rb\n", 3))
		return (rotate(&kolchi->stack_b));
	else if (!ft_strncmp(instruct, "rr\n", 3))
		return (rotate(&kolchi->stack_a), rotate(&kolchi->stack_b));
	else if (!ft_strncmp(instruct, "rra\n", 4))
		return (rev_rotate(&kolchi->stack_a));
	else if (!ft_strncmp(instruct, "rrb\n", 4))
		return (rev_rotate(&kolchi->stack_b));
	else if (!ft_strncmp(instruct, "rrr\n", 4))
		return (rev_rotate(&kolchi->stack_a), rev_rotate(&kolchi->stack_b));
	else
		kolchi->flag = -1;
}

void	apply_instruction(t_alias *kolchi)
{
	char	*instruct;

	instruct = get_next_line(0, kolchi->flag);
	while (instruct != NULL)
	{
		check_instruct(kolchi, instruct);
		if (kolchi->flag == -1)
		{
			get_next_line(0, kolchi->flag);
			break ;
		}
		free(instruct);
		instruct = get_next_line(0, kolchi->flag);
	}
	free(instruct);
	instruct = NULL;
}

int	main(int ac, char **av)
{
	t_alias	*kolchi;

	kolchi = malloc(sizeof(t_alias));
	if (!kolchi || ac <= 1)
	{
		free(kolchi);
		return (1);
	}
	initialize(kolchi, ac, av);
	if (check_input(kolchi) == -1)
		puterror(kolchi);
	apply_instruction(kolchi);
	if (kolchi->flag == -1)
		puterror(kolchi);
	if (!is_sorted(kolchi->stack_a) || kolchi->blen > 0)
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
	free_stack(&kolchi->stack_a);
	free_stack(&kolchi->stack_b);
	free(kolchi);
	return (0);
}
