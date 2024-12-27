/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habdella <habdella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 21:07:11 by habdella          #+#    #+#             */
/*   Updated: 2024/12/23 08:34:28 by habdella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "ft_printf.h"

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
	if (is_sorted(kolchi->stack_a))
	{
		free_stack(&kolchi->stack_a);
		free_stack(&kolchi->stack_b);
		free(kolchi);
		return (0);
	}
	sort_stack(kolchi);
	free_stack(&kolchi->stack_a);
	free_stack(&kolchi->stack_b);
	free(kolchi);
	return (0);
}
