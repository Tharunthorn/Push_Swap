/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharunthornmusik <tharunthornmusik@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 11:09:42 by tharunthorn       #+#    #+#             */
/*   Updated: 2023/07/24 00:33:57 by tharunthorn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_stack	*new_single_stack(long value)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new || value < INT_MIN || value > INT_MAX)
		print_error();
	new->value = value;
	new->index = 0;
	new->next = NULL;
	return (new);
}

void	assign_index(t_stack *stack_a, int stack_size)
{
	t_stack		*ptr;
	t_stack		*highest;
	long		value;

	while (--stack_size > 0)
	{
		ptr = stack_a;
		value = INT_MIN;
		highest = NULL;
		while (ptr)
		{
			if (ptr->value < INT_MIN && ptr->value > INT_MAX)
				print_error();
			if (ptr->value > value && ptr->index == 0)
			{
				value = ptr->value;
				highest = ptr;
				ptr = stack_a;
			}
			else
				ptr = ptr->next;
		}
		if (highest != NULL)
			highest->index = stack_size;
	}
}

t_stack	*new_stack(int argc, char **argv)
{
	t_stack	*new;
	t_stack	*head;
	t_stack	*tmp;
	int		i;

	i = 1;
	head = new_single_stack(ft_long_atoi(argv[i]));
	while (i < argc - 1)
	{
		tmp = head;
		while (tmp->next != NULL)
			tmp = tmp->next;
		new = new_single_stack(ft_long_atoi(argv[++i]));
		tmp->next = new;
	}
	assign_index(head, argc - 1);
	return (head);
}
