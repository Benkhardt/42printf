/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenkhar <dbenkhar@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 08:14:02 by dbenkhar          #+#    #+#             */
/*   Updated: 2021/10/26 22:27:31 by dbenkhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	ft_uintcount(unsigned int u)
{
	int	size;

	size = 0;
	if (u == 0)
		return (1);
	while (u)
	{
		u = u / 10;
		size++;
	}
	return (size);
}

static char	*ft_itoa_int(unsigned int u)
{
	int		size;
	char	*rtn;
	char	*nbrs;

	size = ft_uintcount(u);
	rtn = (char *)malloc(sizeof(char) * size + 1);
	if (!rtn)
		return (0);
	nbrs = ft_printf_strdup("0123456789");
	rtn[size] = '\0';
	while (size >= 0)
	{
		rtn[size - 1] = nbrs[u % 10];
		u = u / 10;
		size--;
	}
	free((void *)nbrs);
	return (rtn);
}

int	ft_printf_int(int d)
{
	char	*str;
	int		rtn;
	int		save_d;

	save_d = d;
	rtn = 0;
	if (save_d < 0)
	{
		rtn += ft_printf_char('-');
		save_d = save_d * -1;
	}
	str = ft_itoa_int((unsigned int)save_d);
	rtn += ft_printf_str(str);
	free((void *)str);
	return (rtn);
}
