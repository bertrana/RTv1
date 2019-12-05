/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjohns <yjohns@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 04:10:27 by yjohns            #+#    #+#             */
/*   Updated: 2019/11/06 04:10:27 by yjohns           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_itoa(int n)
{
	int				s;
	int				len;
	char			*ans;
	unsigned int	num;

	len = n < 0 ? 2 : 1;
	s = n;
	while ((s = s / 10))
		len++;
	if (!(ans = ft_strnew(len)))
		return (NULL);
	num = n > 0 ? n : -n;
	while (len)
	{
		ans[len - 1] = num % 10 + '0';
		num = num / 10;
		len--;
	}
	if (n < 0)
		ans[0] = '-';
	return (ans);
}
