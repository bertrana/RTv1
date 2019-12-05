/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjohns <yjohns@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 04:11:22 by yjohns            #+#    #+#             */
/*   Updated: 2019/11/06 04:11:22 by yjohns           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char *mem;

	mem = (char*)malloc(size);
	if (!mem)
		return (NULL);
	ft_bzero(mem, size);
	return ((void *)mem);
}
