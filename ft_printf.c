/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenkhar <dbenkhar@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 15:31:30 by dbenkhar          #+#    #+#             */
/*   Updated: 2021/10/26 20:32:08 by dbenkhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_lines(const char format, void *arg)
{
	int	rtn;

	rtn = 0;
	if (format == 'u')
		rtn += ft_printf_uint(*(unsigned int *)&arg);
	else if (format == 'x')
		rtn += ft_printf_lohex(*(unsigned int *)&arg);
	else if (format == 'X')
		rtn += ft_printf_uphex(*(unsigned int *)&arg);
	else if (format == 'c')
		rtn += ft_printf_char(*(char *)&arg);
	else if (format == 'd' || format == 'i')
		rtn += ft_printf_int(*(int *)&arg);
	else if (format == 's')
		rtn += ft_printf_str((char *)arg);
	else if (format == 'p')
		rtn += ft_printf_ptr((unsigned long)arg);
	return (rtn);
}

int	ft_printf(const char *format, ...)
{
	t_mys	*z;
	int		length;

	z = (t_mys *)malloc(sizeof(t_mys));
	if (!z)
		return (0);
	z = ft_init(z);
	va_start(z->args, format);
	while (format[++z->i])
	{
		if (format[z->i] != '%')
			z->t_length += write(1, &format[z->i], 1);
		else if (format[++z->i] != '%')
			z->t_length += ft_lines(format[z->i], va_arg(z->args, void *));
		else
			z->t_length += write(1, "%", 1);
	}
	va_end(z->args);
	length = z->t_length;
	free((void *)z);
	return (length);
}
