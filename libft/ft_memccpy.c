/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjohns <yjohns@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 04:11:25 by yjohns            #+#    #+#             */
/*   Updated: 2019/11/06 04:11:25 by yjohns           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	void	*p;

	p = ft_memchr(src, c, n);
	if (p)
		return ((void *)ft_memcpy(dest, src, p - src + 1) + (p - src + 1));
	ft_memcpy(dest, src, n);
	return (NULL);
}
