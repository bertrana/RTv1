/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjohns <yjohns@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 04:14:16 by yjohns            #+#    #+#             */
/*   Updated: 2019/11/06 04:14:16 by yjohns           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	size_t len;

	len = ft_strlen(src);
	if (len > n)
		len = n;
	ft_bzero(dst, n);
	return (ft_memcpy(dst, src, len));
}
