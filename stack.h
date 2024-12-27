/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habdella <habdella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 21:16:16 by habdella          #+#    #+#             */
/*   Updated: 2024/12/22 18:06:31 by habdella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

// stack instructions and data structure
typedef struct s_stack
{
	int				data;
	struct s_stack	*next;
}	t_stack;
/* ---------- stack instruction helpers ----------- */
void	push_tail(t_stack **stack, t_stack *new_node);
void	push(t_stack **stack, t_stack **head);
void	rev_rotate(t_stack **stack);
void	rotate(t_stack **stack);
void	swap(t_stack **stack);
t_stack	*creat(int data);
// kolchi struct and it's helper functions
typedef struct s_alias
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		alen;
	int		blen;
	int		ac;
	char	**av;
	char	**split;
	int		size;
	int		flag;
	int		count;
	int		val;
	int		a_value;
	int		a_index;
	int		b_value;
	int		b_index;
}				t_alias;
/* ---------- stack instructions ------------------ */
void	p(t_alias *kolchi);
void	s(t_alias *kolchi);
void	r(t_alias *kolchi);
void	rr(t_alias *kolchi);
/* --------------- free functions --------------- */
void	free_stack(t_stack	**stack);
void	free_split(char **p, int count);
void	puterror(t_alias *kolchi);
// ----------------- input check ----------------- */
int		ft_atoi(char *s, int *flag);
char	**ft_split(char *s, char c, int *size);
void	initialize(t_alias *kolchi, int ac, char **av);
int		check_duplicate(t_stack *stack);
int		check_input(t_alias *kolchi);
int		last_check(char	*s);
/* ------------- sorting function ---------------- */
void	initialize(t_alias *kolchi, int ac, char **av);
int		is_sorted(t_stack *stack);
void	sort_stack(t_alias *kolchi);
void	turk_sort(t_alias *kolchi);
void	three_element(t_alias *kolchi);
void	three_element_cond(t_alias *kolchi, t_stack *a, t_stack *b, t_stack *c);
void	first_part_a(t_alias *kolchi);
int		check_input(t_alias *kolchi);
void	check_input_a(t_alias *kolchi);
void	last_part_b(t_alias *kolchi);
int		find_min(t_stack *stack);
int		find_max(t_stack *stack);
int		find_index(t_stack *stack, int value);
int		find_value(t_stack *stack, int index);
int		calculation(t_alias *kolchi, int target_index);
int		find_pos_b(t_alias *kolchi, int target);
int		find_pos_a(t_alias *kolchi, int target);
void	move(t_alias *kolchi, int best_node, int target_val);
void	additional_rotation(t_alias *kolchi, int node_value, char key);
void	move_a(t_alias *kolchi);
void	ft_rotate_till_min(t_alias *kolchi);
/* ----------------------------------------------- */
#endif
