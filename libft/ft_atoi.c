/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjohns <yjohns@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 04:09:45 by yjohns            #+#    #+#             */
/*   Updated: 2019/11/06 04:09:45 by yjohns           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *s)
{
	unsigned char	*str;
	unsigned long	num;
	int				neg;

	str = (unsigned char *)s;
	num = 0;
	neg = 0;
	while (*str == ' ' || *str == '\t' || *str == '\n'
			|| *str == '\r' || *str == '\v' || *str == '\f')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			neg = 1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		if (num > 922337203685477580 || (num == 922337203685477580
			&& (*str - '0') > (neg ? 8 : 7)))
			return (neg ? 0 : -1);
		num = num * 10 + *str - '0';
		str++;
	}
	return (neg ? (int)-num : (int)num);
}
