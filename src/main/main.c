/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharunthornmusik <tharunthornmusik@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 17:52:08 by tharunthorn       #+#    #+#             */
/*   Updated: 2023/07/23 12:53:41 by tharunthorn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../include/utility.h"

char	**add_front(char **argv, char *str)
{
	char	**temp;
	int		i;

	i = 0;
	temp = (char **)malloc(sizeof(char *) * (ft_strlen(str) + 1));
	temp[0] = ft_strdup(str);
	while (argv[i])
	{
		temp[i + 1] = ft_strdup(argv[i]);
		i++;
	}
	temp[i + 1] = NULL;
	return (temp);
}

int	char_array_len(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
		i++;
	return (i);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**temp;

	if (argc == 1 || argv[1][0] == '\0')
		exit(1);
	if (argc == 2 && is_split(argv))
	{
		ft_printf("argv[1] = %s\n", argv[1]);
		temp = ft_split(argv[1], ' ');
		argv = add_front(temp, argv[0]);
		argc = char_array_len(argv);
	}
	if (!is_correct_input(argv))
		print_error();
	stack_a = new_stack(argc, argv);
	stack_b = NULL;
	push_swap(stack_a, stack_b);
	return (0);
}
