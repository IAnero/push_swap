/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: herrakot <herrakot@student.42antanana>     #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-09-09 12:49:51 by herrakot          #+#    #+#             */
/*   Updated: 2024-09-09 12:49:51 by herrakot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_format_specifier(char format_type, va_list ap)
{
	int	count_to_return;

	count_to_return = 0;
	if (format_type == 'c')
		count_to_return += ft_putchar(va_arg(ap, int));
	else if (format_type == 'p')
		count_to_return += ft_adress(va_arg(ap, unsigned long));
	else if (format_type == 's')
		count_to_return += ft_putstr(va_arg(ap, char *));
	else if (format_type == 'i' || format_type == 'd')
		count_to_return += ft_putnbr(va_arg(ap, int));
	else if (format_type == '%')
		count_to_return += ft_putchar('%');
	else if (format_type == 'u')
		count_to_return += ft_putnbr_unsigned(va_arg(ap, unsigned int));
	else if (format_type == 'x' || format_type == 'X')
		count_to_return += ft_hexa(format_type, va_arg(ap, unsigned int));
	return (count_to_return);
}

int	ft_printf(const char *format, ...)
{
	int	count_to_return;

	va_list(ap);
	va_start(ap, format);
	count_to_return = 0;
	while (*format)
	{
		if (*format == '%')
			count_to_return += ft_format_specifier(*(++format), ap);
		else
			count_to_return += ft_putchar(*format);
		++format;
	}
	va_end(ap);
	return (count_to_return);
}
