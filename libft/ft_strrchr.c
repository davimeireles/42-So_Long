/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 12:06:20 by dmeirele          #+#    #+#             */
/*   Updated: 2023/10/09 19:27:13 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int	final;

	final = ft_strlen(s);
	i = final;
	while (i >= 0)
	{
		if (s[i] == (const char)c)
			return ((char *)&s[i]);
		i--;
	}
	if ((char)c == 0)
		return ((char *)&s[final]);
	return (NULL);
}
