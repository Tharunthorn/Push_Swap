/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharunthornmusik <tharunthornmusik@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 09:03:23 by thmusik           #+#    #+#             */
/*   Updated: 2023/07/24 23:14:29 by tharunthorn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	int		i;

	if (!s)
		return (0);
	str = ft_strdup(s);
	i = 0;
	if (!str)
		return (0);
	while (*(str + i) != '\0')
	{
		*(str + i) = (*f)(i, *(str + i));
		i++;
	}
	return (str);
}
