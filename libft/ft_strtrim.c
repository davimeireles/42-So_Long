/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 18:10:49 by dmeirele          #+#    #+#             */
/*   Updated: 2023/10/16 18:52:20 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_charcmp(char s1, char const *s2)
{
	int	i;

	i = 0;
	while (s2[i])
	{
		if (s1 == s2[i])
			return (0);
		i++;
	}
	return (1);
}

static int	start_loop(char const *s1, char const *s2, int size_s1)
{
	int	i;

	i = 0;
	while (i < size_s1)
	{
		if (ft_charcmp(s1[i], s2))
			return (i);
		i++;
	}
	return (i);
}

static int	final_loop(char const *s1, char const *s2, int size_s1)
{
	int	i;

	i = size_s1 - 1;
	while (i >= 0)
	{
		if (ft_charcmp(s1[i], s2))
			return (i);
		i--;
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		incpos;
	int		finpos;
	int		memmall;
	char	*ptr;

	incpos = start_loop(s1, set, ft_strlen(s1));
	finpos = final_loop(s1, set, ft_strlen(s1));
	i = 0;
	memmall = finpos - incpos + 1;
	if (memmall < 0)
		memmall = 0;
	ptr = ft_calloc(memmall + 1, sizeof(char));
	if (!ptr)
		return (NULL);
	while (incpos <= finpos)
	{
		ptr[i] = s1[incpos];
		i++;
		incpos++;
	}
	ptr[i] = '\0';
	return (ptr);
}
