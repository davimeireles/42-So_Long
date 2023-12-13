/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:37:43 by dmeirele          #+#    #+#             */
/*   Updated: 2023/10/30 19:07:33 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*ptr;
	size_t			i;
	size_t			total_size;

	total_size = nmemb * size;
	ptr = malloc(total_size);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < total_size)
	{
		ptr[i] = 0;
		i++;
	}
	return (ptr);
}

char	*ft_strcpy_nl(char *src, char *dest, int nl_stop)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		if (nl_stop && src[i] == '\n')
		{
			i++;
			break ;
		}
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	ft_check_character(char *str, int c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

char	*ft_strjoin_gnl(char *str1, char *str2)
{
	size_t	len;
	int		i;
	int		k;
	char	*joined;

	i = 0;
	len = ft_strlen(str1) + ft_strlen(str2);
	joined = ft_calloc((len + 1), sizeof(char));
	if (!joined)
		return (NULL);
	while (str1 && str1[i])
	{
		joined[i] = str1[i];
		i++;
	}
	k = 0;
	while (str2 && str2[k])
		joined[i++] = str2[k++];
	free(str1);
	return (joined);
}
