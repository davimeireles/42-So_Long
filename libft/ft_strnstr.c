/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:46:34 by dmeirele          #+#    #+#             */
/*   Updated: 2023/10/09 16:09:50 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	big_size;
	size_t	little_size;
	size_t	i;

	i = 0;
	big_size = ft_strlen(big);
	little_size = ft_strlen(little);
	if (little[0] == '\0')
		return ((char *)&big[i]);
	if (little_size > big_size || len == 0)
		return (NULL);
	while (big[i] && i < len)
	{
		if (ft_strncmp(&big[i], little, little_size) == 0 && i
			+ little_size <= len)
			return ((char *)&big[i]);
		i++;
	}
	return (NULL);
}
