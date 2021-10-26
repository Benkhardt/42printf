/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenkhar <dbenkhar@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 16:41:33 by dbenkhar          #+#    #+#             */
/*   Updated: 2021/10/26 22:28:18 by dbenkhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_printf_str(char *s)
{
	int	rtn;
	int	index;

	rtn = 0;
	index = -1;
	if (s == NULL)
	{
		s = ft_printf_strdup("(null)");
		while (s[++index] != '\0')
			rtn += write(1, &s[index], 1);
		free((void *)s);
		return (rtn);
	}
	while (s[++index] != '\0')
		rtn += write(1, &s[index], 1);
	return (rtn);
}
