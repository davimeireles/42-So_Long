/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 18:28:56 by dmeirele          #+#    #+#             */
/*   Updated: 2023/10/25 19:08:13 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_pointer_put_nbr(unsigned long long ptr_nbr, int *print)
{
	char			*str;
	unsigned long	module;

	str = "0123456789abcdef";
	if (ptr_nbr >= 16)
		ft_pointer_put_nbr(ptr_nbr / 16, print);
	module = ptr_nbr % 16;
	write(1, &str[module], 1);
	*print += 1;
}

static void	ft_hex_put_nbr(unsigned int hex_nbr, int *print, char format)
{
	char			*str;
	unsigned int	module;

	if (format == 'x')
		str = "0123456789abcdef";
	else
		str = "0123456789ABCDEF";
	if (hex_nbr >= 16)
		ft_hex_put_nbr(hex_nbr / 16, print, format);
	module = hex_nbr % 16;
	write(1, &str[module], 1);
	*print += 1;
}

void	ft_print_hex(va_list args, int *print, char format)
{
	unsigned int		hex_nbr;
	unsigned long		ptr_nbr;

	if (format == 'p')
	{
		ptr_nbr = va_arg(args, unsigned long);
		if (ptr_nbr == 0)
		{
			write(1, "(nil)", 5);
			*print += 5;
			return ;
		}
		write(1, "0x", 2);
		*print += 2;
		ft_pointer_put_nbr(ptr_nbr, print);
	}
	else
	{
		hex_nbr = va_arg(args, unsigned int);
		ft_hex_put_nbr(hex_nbr, print, format);
	}
}
