/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharunthornmusik <tharunthornmusik@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 17:52:08 by tharunthorn       #+#    #+#             */
/*   Updated: 2023/07/24 23:06:41 by tharunthorn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../include/utility.h"
#include <string.h>

char	**add_front(char **argv, char *str)
{
	char	**temp;
	int		i;
	int		j;

	i = 0;
	while (argv[i])
		i++;
	temp = (char **)malloc(sizeof(char *) * (i + 2));
	if (!temp)
		return (NULL);
	temp[0] = ft_strdup(str);
	j = 0;
	while (j < i)
	{
		temp[j + 1] = ft_strdup(argv[j]);
		free(argv[j]);
		j++;
	}
	free(argv);
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

int	is_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	if (ft_long_atoi(str) > INT_MAX || ft_long_atoi(str) < INT_MIN)
		print_error();
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**temp;

	if (argc == 1 || argv[1][0] == '\0' || (argc == 2 && is_number(argv[1])))
		return (0);
	if (argc == 2 && is_split(argv))
	{
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
