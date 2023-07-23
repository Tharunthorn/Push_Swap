/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharunthornmusik <tharunthornmusik@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 23:57:24 by tharunthorn       #+#    #+#             */
/*   Updated: 2023/07/23 12:06:59 by tharunthorn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"

# define INT_MIN -2147483648
# define INT_MAX 2147483647

typedef struct s_stack
{
	long			value;
	long			index;
	struct s_stack	*next;
}					t_stack;

t_stack	*new_stack(int argc, char **argv);

void	print_error(void);

int		get_stack_size(t_stack *stack);

void	free_stack(t_stack *stack);

int		is_sorted(t_stack *stack);

void	assign_index(t_stack *stack_a, int stack_size);

void	swap_a(t_stack **stack_a);

void	swap_b(t_stack **stack_b);

void	swap_ab(t_stack **stack_a, t_stack **stack_b);

void	push_a(t_stack **stack_a, t_stack **stack_b);

void	push_b(t_stack **stack_a, t_stack **stack_b);

void	rotate_a(t_stack **stack_a);

void	rotate_b(t_stack **stack_b);

void	rotate_ab(t_stack **stack_a, t_stack **stack_b);

void	reverse_rotate_a(t_stack **stack_a);

void	reverse_rotate_b(t_stack **stack_b);

void	reverse_rotate_ab(t_stack **stack_a, t_stack **stack_b);

#endif
