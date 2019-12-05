/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjohns <yjohns@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 04:14:08 by yjohns            #+#    #+#             */
/*   Updated: 2019/11/06 04:14:08 by yjohns           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	size_t len;

	len = ft_strlen(src);
	if (len > n)
		len = n;
	*(dest + ft_strlen(dest) + len) = '\0';
	ft_memcpy(dest + ft_strlen(dest), src, len);
	return (dest);
}
