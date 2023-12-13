/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:20:42 by dmeirele          #+#    #+#             */
/*   Updated: 2023/10/09 19:26:24 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	if (*s)
	{
		while (*s)
		{
			if (*s == (const char)c)
			{
				return ((char *)s);
			}
			s++;
		}
	}
	if ((char)c == 0)
		return ((char *)s);
	return (NULL);
}
