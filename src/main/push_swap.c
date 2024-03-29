/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharunthornmusik <tharunthornmusik@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 16:11:16 by tharunthorn       #+#    #+#             */
/*   Updated: 2023/07/22 22:38:46 by tharunthorn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	push_swap(t_stack *stack_a, t_stack *stack_b)
{
	int	stack_size;

	stack_size = get_stack_size(stack_a);
	if (is_sorted(stack_a))
		return ;
	if (stack_size == 2 || stack_size == 3 || stack_size == 5)
		brute_force_sort(stack_a, stack_b);
	else
		radix_sort(stack_a, stack_b);
	return ;
}
