/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 08:59:19 by dmeirele          #+#    #+#             */
/*   Updated: 2023/10/16 18:51:25 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_pointers(char **sup, int count)
{
	int	i;

	i = 0;
	while (i < count)
		free(sup[i++]);
	free(sup);
}

static int	count_words(char const *s, char c)
{
	int	i;
	int	flag;

	flag = 1;
	i = 0;
	while (*s)
	{
		if (*s == c && flag == 0)
		{
			flag = 1;
		}
		else if (*s != c && flag == 1)
		{
			i++;
			flag = 0;
		}
		s++;
	}
	return (i);
}

static void	ft_allocate(char **sup, char const *s, char c)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		k = i;
		if (s[k] == '\0')
			break ;
		while (s[i] != c && s[i] != '\0')
			i++;
		sup[j] = ft_substr(s, k, i - k);
		j++;
	}
	sup[j] = NULL;
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		i;

	i = 0;
	split = ft_calloc(count_words(s, c) + 1, sizeof(char *));
	if (!split)
		return (NULL);
	ft_allocate(split, s, c);
	while (i < count_words(s, c))
	{
		if (split[i] == NULL)
		{
			free_pointers(split, count_words(s, c));
			return (NULL);
		}
		i++;
	}
	return (split);
}
