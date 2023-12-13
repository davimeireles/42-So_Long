/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:51:32 by dmeirele          #+#    #+#             */
/*   Updated: 2023/10/25 18:59:45 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_put_char(char c, int *print)
{
	write(1, &c, 1);
	*print += 1;
}

static void	ft_check_flags(const char *format, va_list args, int *print)
{
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
				ft_print_char(args, print);
			if (*format == 's')
				ft_print_str(args, print);
			if (*format == 'd' || *format == 'i' || *format == 'u')
				ft_print_nbr(args, print, *format);
			if (*format == 'x' || *format == 'X' || *format == 'p')
				ft_print_hex(args, print, *format);
			if (*format == '%')
			{
				write(1, "%", 1);
				*print += 1;
			}
		}
		else
			ft_put_char(*format, print);
		format++;
	}
}

int	ft_printf(const char *format, ...)
{
	int		print;
	va_list	args;

	print = 0;
	va_start(args, format);
	ft_check_flags(format, args, &print);
	va_end(args);
	return (print);
}
