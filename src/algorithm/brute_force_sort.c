/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brute_force_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharunthornmusik <tharunthornmusik@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 22:45:19 by tharunthorn       #+#    #+#             */
/*   Updated: 2023/07/22 21:56:17 by tharunthorn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdio.h>

long	find_min_index(t_stack *stack)
{
	long	min;
	t_stack	*current;

	min = stack->index;
	current = stack->next;
	while (current != NULL)
	{
		if (current->index < min)
			min = current->index;
		current = current->next;
	}
	return (min);
}

long	find_max_index(t_stack *stack)
{
	long	max;
	t_stack	*current;

	max = stack->index;
	current = stack->next;
	while (current != NULL)
	{
		if (current->index > max)
			max = current->index;
		current = current->next;
	}
	return (max);
}

void	three_sort(t_stack *stack_a)
{
	int		highest;

	if (is_sorted(stack_a))
		return ;
	highest = find_max_index(stack_a);
	if (stack_a->index == highest)
		rotate_a(&stack_a);
	else if (stack_a->next->index == highest)
		reverse_rotate_a(&stack_a);
	if (stack_a->index > stack_a->next->index)
		swap_a(&stack_a);
	return ;
}

void	five_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	min;
	int	max;

	min = find_min_index(stack_a);
	max = find_max_index(stack_a);
	while (get_stack_size(stack_a) > 3)
	{
		if (stack_a->index == min || stack_a->index == max)
			push_b(&stack_a, &stack_b);
		else
			rotate_a(&stack_a);
	}
	if (stack_b->index < stack_b->next->index)
		swap_b(&stack_b);
	three_sort(stack_a);
	push_a(&stack_a, &stack_b);
	rotate_a(&stack_a);
	push_a(&stack_a, &stack_b);
	return ;
}

void	brute_force_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	stack_size;

	stack_size = get_stack_size(stack_a);
	if (stack_size == 2)
		swap_a(&stack_a);
	else if (stack_size == 3)
		three_sort(stack_a);
	else if (stack_size == 5)
		five_sort(stack_a, stack_b);
	return ;
}
