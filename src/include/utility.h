/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharunthornmusik <tharunthornmusik@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 23:30:13 by tharunthorn       #+#    #+#             */
/*   Updated: 2023/07/22 20:40:26 by tharunthorn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILITY_H
# define UTILITY_H

# include "../include/push_swap.h"

int	is_digit(char c);

int	is_sign(char c);

int	is_correct_input(char **av);

int	is_split(char **av);

int	nbstr_cmp(const char *s1, const char *s2);

#endif
