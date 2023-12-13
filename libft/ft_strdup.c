/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 18:23:29 by dmeirele          #+#    #+#             */
/*   Updated: 2023/10/16 14:30:50 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*ptr;
	size_t	str_size;
	size_t	i;

	i = 0;
	str_size = ft_strlen(s);
	ptr = ft_calloc(str_size + 1, 1);
	if (!ptr)
		return (NULL);
	while (i <= str_size)
	{
		ptr[i] = s[i];
		i++;
	}
	return (ptr);
}
