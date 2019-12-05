/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjohns <yjohns@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 04:14:29 by yjohns            #+#    #+#             */
/*   Updated: 2019/11/06 04:14:29 by yjohns           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strnstr(const char *str1, const char *str2, size_t len)
{
	int	i;
	int	j;

	i = 0;
	if (!*str2)
		return ((char *)str1);
	while (str1[i] && len)
	{
		if (str1[i] == str2[0])
		{
			j = 1;
			while (str2[j] && str1[i + j] == str2[j] && (len - j))
				j++;
			if (!str2[j])
				return ((char *)str1 + i);
		}
		i++;
		len--;
	}
	return (NULL);
}
