/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharunthornmusik <tharunthornmusik@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 13:54:16 by tharunthorn       #+#    #+#             */
/*   Updated: 2023/07/01 13:55:48 by tharunthorn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	insert_sort_algorithm(t_stack **stack_a)
{
	if (!*stack_a || !(*stack_a)->next)
		return ;
	if (*(*stack_a)->value > *(*stack_a)->next->value)
	{
		swap_a(stack_a);
		insert_sort_algorithm(&(*stack_a)->next);
	}
	else
	{
		if (!(*stack_a)->next->next)
			return ;
	}
	if (!sorted_check(stack_a))
		insert_sort_algorithm(&(*stack_a)->next); ;
	return ;
}

void	insert_sort(t_stack **stack_a)
{
	while(!sorted_check(stack_a))
		insert_sort_algorithm(stack_a);
	return ;
}

