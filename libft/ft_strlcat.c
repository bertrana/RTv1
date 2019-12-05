/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjohns <yjohns@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 04:13:49 by yjohns            #+#    #+#             */
/*   Updated: 2019/11/06 04:13:49 by yjohns           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	len;

	len = ft_strlen(dest);
	if (ft_strlen(dest) > size)
		return (size + ft_strlen(src));
	ft_strncat(dest, src, size - ft_strlen(dest) - 1);
	return (len + ft_strlen(src));
}
