/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharunthornmusik <tharunthornmusik@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 17:52:08 by tharunthorn       #+#    #+#             */
/*   Updated: 2023/06/29 16:19:49 by tharunthorn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/stack/stack.h"
#include "../../lib/libft/libft.h"
#include "../include/push_swap.h"

void convertArguments(char **argv, int argc, int ***value, int *size)
{
	//TODO: Check if arguments are valid
	//TODO: Check if arguments are integers
	//TODO: Check if arguments are duplicates
	//TODO; Change to while loop
	*value = (int **)malloc((*size) * sizeof(int *));

	for (int i = 1; i < argc; i++) {
		(*value)[i - 1] = (int *)malloc(sizeof(int));
		*(*value)[i - 1] = ft_atoi(argv[i]);
	}
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		**value;
	int		size;

	size = argc - 1;
	convertArguments(argv, argc, &value, &argc);
	stack_a = new_stack(value, size);
	stack_b = empty_stack();
	push_swap(stack_a, stack_b);
	return (0);
}
