#ifndef STACK_H
# define STACK_H

# include <unistd.h>
# include "../libft/libft.h"

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}					t_stack;

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
