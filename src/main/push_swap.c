/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharunthornmusik <tharunthornmusik@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 16:11:16 by tharunthorn       #+#    #+#             */
/*   Updated: 2023/07/03 22:51:57 by tharunthorn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	sorted_check(t_stack **stack)
{
	t_stack	*tmp;

	tmp = *stack;
	while (tmp->next)
	{
		if (*tmp->value > *tmp->next->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	three_number_sort(t_stack **stack_a)
{
	if (*(*stack_a)->value > *(*stack_a)->next->value &&
		*(*stack_a)->value < *(*stack_a)->next->next->value)
		swap_a(stack_a);
	else if (*(*stack_a)->value > *(*stack_a)->next->value &&
		*(*stack_a)->value > *(*stack_a)->next->next->value &&
		*(*stack_a)->next->value > *(*stack_a)->next->next->value)
		{
			swap_a(stack_a);
			reverse_rotate_a(stack_a);
		}
	else if (*(*stack_a)->value > *(*stack_a)->next->value &&
		*(*stack_a)->value > *(*stack_a)->next->next->value)
		rotate_a(stack_a);
	else if (*(*stack_a)->value < *(*stack_a)->next->value &&
		*(*stack_a)->value < *(*stack_a)->next->next->value &&
		*(*stack_a)->next->value > *(*stack_a)->next->next->value)
		{
			swap_a(stack_a);
			rotate_a(stack_a);
		}
	else if (*(*stack_a)->value < *(*stack_a)->next->value &&
		*(*stack_a)->value > *(*stack_a)->next->next->value)
		reverse_rotate_a(stack_a);
	return ;
}

void five_number_sort(t_stack **stack_a, t_stack **stack_b)
{
	push_b(stack_a, stack_b);
	push_b(stack_a, stack_b);
	three_number_sort(stack_a);
	if (*(*stack_b)->value < *(*stack_b)->next->value)
		swap_b(stack_b);
	push_a(stack_a, stack_b);
	if (*(*stack_a)->value > *(*stack_a)->next->next->value)
		rotate_a(stack_a);
	push_b(stack_a, stack_b);
	three_number_sort(stack_a);
	if (*(*stack_b)->value < *(*stack_b)->next->value)
		swap_b(stack_b);
	push_a(stack_a, stack_b);
	push_a(stack_a, stack_b);
	return ;
}

void	push_swap(t_stack *stack_a, t_stack *stack_b)
{
	if (!stack_a || stack_b->value)
		return ;
	if (stack_size(stack_a) == 2 &&
		(*stack_a->value > *stack_a->next->value))
		swap_a(&stack_a);
	else if (stack_size(stack_a) == 3)
		three_number_sort(&stack_a);
	else if (stack_size(stack_a) == 5)
		five_number_sort(&stack_a, &stack_b);
	return ;
}
