/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharunthornmusik <tharunthornmusik@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 01:00:08 by tharunthorn       #+#    #+#             */
/*   Updated: 2023/07/21 23:57:13 by tharunthorn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	push(t_stack **stack_1, t_stack **stack_2)
{
	t_stack	*new_node;
	t_stack	*temp;

	if (*stack_2 == NULL)
		return ;
	new_node = (t_stack *)malloc(sizeof(t_stack));
	new_node->value = (*stack_2)->value;
	new_node->index = (*stack_2)->index;
	new_node->next = *stack_1;
	*stack_1 = new_node;
	temp = *stack_2;
	*stack_2 = (*stack_2)->next;
	free(temp);
	return ;
}

void	push_a(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_a, stack_b);
	ft_printf("pa\n");
	return ;
}

void	push_b(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_b, stack_a);
	ft_printf("pb\n");
	return ;
}
