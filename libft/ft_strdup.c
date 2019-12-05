/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjohns <yjohns@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 04:13:31 by yjohns            #+#    #+#             */
/*   Updated: 2019/11/06 04:13:31 by yjohns           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*copy;
	int		len;

	len = ft_strlen(src) + 1;
	copy = (char *)malloc(len);
	if (!copy)
		return (NULL);
	return (ft_memcpy(copy, src, len));
}
