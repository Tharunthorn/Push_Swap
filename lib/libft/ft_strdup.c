/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharunthornmusik <tharunthornmusik@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 09:06:46 by thmusik           #+#    #+#             */
/*   Updated: 2023/07/23 22:55:56 by tharunthorn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	size_t	len;
	void	*copy;

	len = ft_strlen(str) + 1;
	copy = malloc(len);
	if (copy)
		return (ft_memcpy(copy, str, len));
	return (copy);
}

/*
#include <stdio.h>
#include <string.h>

int main()
{
    char source[] = "GeeksForGeeks";

    // A copy of source is created dynamically
    // and pointer to copy is returned.
    char *target = ft_strdup(source);

    printf("%s", target);
    return 0;
}
*/
