/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharunthornmusik <tharunthornmusik@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 23:22:11 by tharunthorn       #+#    #+#             */
/*   Updated: 2023/07/21 23:53:08 by tharunthorn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	radix_sort(t_stack *stack_a, t_stack *stack_b)
{
	long	mask;
	int		stack_size;

	mask = 1L;
	while (!is_sorted(stack_a))
	{
		stack_size = get_stack_size(stack_a);
		while (stack_size-- > 0)
		{
			if (stack_a->index & mask)
				rotate_a(&stack_a);
			else
				push_b(&stack_a, &stack_b);
		}
		while (stack_b)
			push_a(&stack_a, &stack_b);
		mask <<= 1;
	}
	return ;
}
