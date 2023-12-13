/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 18:29:47 by dmeirele          #+#    #+#             */
/*   Updated: 2023/10/25 19:01:43 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_unsigned_put_nbr(unsigned int u_nbr, int *print)
{
	if (u_nbr >= 10)
		ft_unsigned_put_nbr((u_nbr / 10), print);
	ft_put_char((u_nbr % 10 + '0'), print);
}

static void	ft_put_nbr(int nbr, int *print)
{
	if (nbr == -2147483648)
	{
		write(1, "-2147483648", 11);
		*print += 11;
		return ;
	}
	else
	{
		if (nbr < 0)
		{
			nbr = nbr * -1;
			write(1, "-", 1);
			*print += 1;
		}
		if (nbr >= 10)
			ft_put_nbr((nbr / 10), print);
		ft_put_char((nbr % 10 + '0'), print);
	}
}

void	ft_print_nbr(va_list args, int *print, char format)
{
	if (format == 'u')
		ft_unsigned_put_nbr(va_arg(args, unsigned int), print);
	else
		ft_put_nbr(va_arg(args, int), print);
}
