/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjohns <yjohns@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 04:11:33 by yjohns            #+#    #+#             */
/*   Updated: 2019/11/06 04:11:33 by yjohns           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_memcmp(const void *mem1, const void *mem2, size_t n)
{
	unsigned char	*m1;
	unsigned char	*m2;
	size_t			i;

	if (!n)
		return (0);
	n--;
	m1 = (unsigned char *)mem1;
	m2 = (unsigned char *)mem2;
	i = 0;
	while (i < n && m1[i] == m2[i])
		i++;
	return (m1[i] - m2[i]);
}
