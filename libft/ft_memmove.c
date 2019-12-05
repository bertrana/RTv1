/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjohns <yjohns@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 04:11:48 by yjohns            #+#    #+#             */
/*   Updated: 2019/11/06 04:11:48 by yjohns           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*s;
	unsigned char	*d;

	s = (unsigned char *)src;
	d = (unsigned char *)dst;
	if (dst == src)
		return (dst);
	if (dst > src)
	{
		i = n;
		while (i-- > 0)
			d[i] = s[i];
	}
	else
	{
		i = -1;
		while (++i < n)
			d[i] = s[i];
	}
	return (dst);
}
