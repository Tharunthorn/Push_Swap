/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharunthornmusik <tharunthornmusik@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 08:09:36 by thmusik           #+#    #+#             */
/*   Updated: 2023/07/23 12:02:28 by tharunthorn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_resultcheck(long result)
{
	if (result > 2147483649)
		return (0);
	if (result < -2147483649)
		return (-1);
	return (result);
}

long	ft_atoi(const char *str)
{
	long	i;
	long	sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while ((*(str + i) >= 9 && *(str + i) <= 13) || (*(str + i) == 32))
		i++;
	if (*(str + i) == 45 || *(str + i) == 43)
	{
		if (*(str + i) == 45)
			sign *= -1;
		i++;
	}
	while (*(str + i) >= 48 && *(str + i) <= 57)
	{
		result += *(str + i) - 48;
		result *= 10;
		i++;
	}
	result /= 10;
	return (ft_resultcheck(result * sign));
}

long	ft_long_atoi(const char *str)
{
	long	i;
	long	sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while ((*(str + i) >= 9 && *(str + i) <= 13) || (*(str + i) == 32))
		i++;
	if (*(str + i) == 45 || *(str + i) == 43)
	{
		if (*(str + i) == 45)
			sign *= -1;
		i++;
	}
	while (*(str + i) >= 48 && *(str + i) <= 57)
	{
		result += *(str + i) - 48;
		result *= 10;
		i++;
	}
	result /= 10;
	return (result * sign);
}

/*
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    (void)argc;
    printf("original atoi: %d\n", atoi(argv[1]));
    printf("copy atoi: %d\n", ft_atoi(argv[1]));
    return (0);
}
*/
