/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjohns <yjohns@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 04:12:02 by yjohns            #+#    #+#             */
/*   Updated: 2019/11/06 04:12:02 by yjohns           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *memptr, int val, size_t len)
{
	char *c;

	c = (char *)memptr;
	while (len)
	{
		*c = (char)val;
		c++;
		len--;
	}
	return (memptr);
}
