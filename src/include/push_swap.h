/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharunthornmusik <tharunthornmusik@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 13:55:30 by tharunthorn       #+#    #+#             */
/*   Updated: 2023/07/21 12:37:25 by tharunthorn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../../lib/stack/stack.h"
# include "../../lib/libft/libft.h"

typedef struct s_stack	t_stack;

void	push_swap(t_stack *stack_a, t_stack *stack_b);

void	brute_force_sort(t_stack *stack_a, t_stack *stack_b);

void	radix_sort(t_stack *stack_a, t_stack *stack_b);

#endif
