/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:29:55 by dmeirele          #+#    #+#             */
/*   Updated: 2023/10/16 18:51:42 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	digit_count(int n)
{
	int				len;
	unsigned int	nb;

	len = 0;
	nb = n;
	if (n < 0)
	{
		len++;
		nb = -n;
	}
	if (nb == 0)
	{
		len = 1;
		return (len);
	}
	while (nb > 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

static char	*negative_number(unsigned int n, int d_count)
{
	char	*negnbr;

	negnbr = ft_calloc(d_count + 1, sizeof(char));
	if (!negnbr)
		return (NULL);
	negnbr[d_count] = '\0';
	while (d_count > 0)
	{
		d_count--;
		negnbr[d_count] = n % 10 + '0';
		n = n / 10;
	}
	negnbr[0] = '-';
	return (negnbr);
}

char	*ft_itoa(int n)
{
	char			*nbr;
	char			*negnbr;
	int				d_count;
	unsigned int	nb;

	nb = n;
	if (n < 0)
	{
		nb = -n;
		d_count = digit_count(n);
		negnbr = negative_number(nb, d_count);
		return (negnbr);
	}
	d_count = digit_count(n);
	nbr = ft_calloc(d_count + 1, sizeof(char));
	if (!nbr)
		return (NULL);
	nbr[d_count] = '\0';
	while (d_count > 0)
	{
		nbr[d_count-- - 1] = n % 10 + '0';
		n = n / 10;
	}
	return (nbr);
}
