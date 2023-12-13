/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 09:59:32 by dmeirele          #+#    #+#             */
/*   Updated: 2023/10/09 19:26:56 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	src_size;
	size_t	dst_size;
	size_t	i;
	size_t	dst_return;

	src_size = ft_strlen(src);
	dst_size = ft_strlen(dst);
	dst_return = ft_strlen(dst);
	i = 0;
	if (size == 0)
		return (src_size);
	if (size >= dst_size)
	{
		while (src[i] && dst_size < size - 1)
		{
			dst[dst_size] = src[i];
			dst_size++;
			i++;
		}
		dst[dst_size] = '\0';
		return (dst_return + src_size);
	}
	return (src_size + size);
}
