/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehkul <mehkul@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 12:36:39 by mehkul            #+#    #+#             */
/*   Updated: 2025/08/01 12:36:39 by mehkul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

static int	dispatch_format(const char spec, va_list *args)
{
	if (spec == 'c')
		return (print_char(va_arg(*args, int)));
	else if (spec == 's')
		return (print_str(va_arg(*args, char *)));
	else if (spec == 'd' || spec == 'i')
		return (print_int(va_arg(*args, int)));
	else if (spec == 'p')
		return (print_ptr((unsigned long)va_arg(*args, void *)));
	else if (spec == 'u')
		return (print_unsigned(va_arg(*args, unsigned int)));
	else if (spec == 'x' || spec == 'X')
		return (print_hex(va_arg(*args, unsigned int), spec));
	else if (spec == '%')
		return (print_char('%'));
	else
		return (-1);
}

static int	handle_percent(const char **format, va_list *args)
{
	int	add;

	(*format)++;
	if (**format == '\0')
		return (-1);
	add = dispatch_format(**format, args);
	if (add == -1)
	{
		if (print_char(**format) == -1)
			return (-1);
		return (1);
	}
	return (add);
}

static int	ft_format(const char *format, va_list *args, int count)
{
	int	add;

	while (*format)
	{
		if (*format == '%')
		{
			add = handle_percent(&format, args);
			if (add == -1)
				return (-1);
			count += add;
		}
		else
		{
			if (print_char(*format) == -1)
				return (-1);
			count++;
		}
		format++;
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	if (!format)
		return (-1);
	va_start(args, format);
	count = ft_format(format, &args, 0);
	va_end(args);
	return (count);
}
