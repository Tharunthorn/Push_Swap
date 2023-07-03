/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharunthornmusik <tharunthornmusik@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 11:09:42 by tharunthorn       #+#    #+#             */
/*   Updated: 2023/07/03 14:00:38 by tharunthorn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_stack	*empty_stack(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->value = NULL;
	stack->next = NULL;
	return (stack);
}

t_stack	*new_stack(int **value, int size)
{
	t_stack	*stack;
	t_stack	*tmp;
	int		i;

	i = size - 1;
	stack = empty_stack();
	if (!stack)
		return (NULL);
	stack->value = value[i];
	i--;
	while (i >= 0)
	{
		tmp = empty_stack();
		if (!tmp)
			return (NULL);
		tmp->value = value[i];
		tmp->next = stack;
		stack = tmp;
		i--;
	}
	return (stack);
}

void	print_stack(t_stack *stack)
{
	while (stack)
	{
		if (stack->value)
			ft_printf("%d ", *stack->value);
		stack = stack->next;
	}
	ft_printf("\n");
}

void	print_stack_ab(t_stack *stack_a, t_stack *stack_b)
{
	ft_printf("Stack A: ");
	print_stack(stack_a);
	ft_printf("Stack B: ");
	print_stack(stack_b);
}

int	stack_size(t_stack *stack)
{
	int		size;
	t_stack	*tmp;

	size = 0;
	tmp = stack;
	while (tmp)
	{
		size++;
		tmp = tmp->next;
	}
	return (size);
}
