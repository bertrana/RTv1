/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjohns <yjohns@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 04:11:29 by yjohns            #+#    #+#             */
/*   Updated: 2019/11/06 04:11:29 by yjohns           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *buffer, int ch, size_t n)
{
	size_t			i;
	unsigned char	*save;

	i = 0;
	save = (unsigned char *)buffer;
	while (i < n)
	{
		if (save[i] == (unsigned char)ch)
			return (save + i);
		i++;
	}
	return (NULL);
}
