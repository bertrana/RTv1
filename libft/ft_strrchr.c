/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjohns <yjohns@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 04:14:33 by yjohns            #+#    #+#             */
/*   Updated: 2019/11/06 04:14:33 by yjohns           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strrchr(const char *str, int s)
{
	int i;

	if (s == '\0')
		return ((char *)(str + ft_strlen(str)));
	i = ft_strlen(str);
	while (i && str[i] != s)
		i--;
	if (str[i] == s)
		return ((char *)(str + i));
	return (NULL);
}
