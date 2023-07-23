/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharunthornmusik <tharunthornmusik@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 00:43:10 by tharunthorn       #+#    #+#             */
/*   Updated: 2023/07/20 15:38:43 by tharunthorn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	swap(t_stack **stack)
{
	t_stack	*temp;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	temp = *stack;
	*stack = (*stack)->next;
	temp->next = (*stack)->next;
	(*stack)->next = temp;
	return ;
}

void	swap_a(t_stack **stack_a)
{
	swap(stack_a);
	ft_printf("sa\n");
	return ;
}

void	swap_b(t_stack **stack_b)
{
	swap(stack_b);
	ft_printf("sb\n");
	return ;
}

void	swap_ab(t_stack **stack_a, t_stack **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	ft_printf("ss\n");
	return ;
}
