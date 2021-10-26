/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenkhar <dbenkhar@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 20:26:31 by dbenkhar          #+#    #+#             */
/*   Updated: 2021/10/26 20:31:17 by dbenkhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	ft_lohexcount(unsigned long x)
{
	int	size;

	size = 0;
	if (x == 0)
		return (1);
	while (x)
	{
		x = x / 16;
		size++;
	}
	return (size);
}

static char	*ft_itoa_lohex(unsigned long x)
{
	int		size;
	char	*rtn;
	char	*nbrs;

	nbrs = ft_printf_strdup("0123456789abcdef");
	size = ft_lohexcount(x);
	rtn = (char *)malloc(sizeof(char) * size + 1);
	if (!rtn)
		return (NULL);
	rtn[size] = '\0';
	while (--size >= 0)
	{
		rtn[size] = nbrs[x % 16];
		x = x / 16;
	}
	free((void *)nbrs);
	return (rtn);
}

int	ft_printf_ptr(unsigned long ptr)
{
	char	*str;
	int		rtn;

	rtn = 0;
	str = ft_itoa_lohex(ptr);
	rtn += ft_printf_str("0x");
	rtn += ft_printf_str(str);
	free((void *)str);
	return (rtn);
}
