/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjohns <yjohns@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 04:14:45 by yjohns            #+#    #+#             */
/*   Updated: 2019/11/06 04:14:45 by yjohns           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*ans;
	unsigned int	i;

	if (!s)
		return (NULL);
	i = 0;
	ans = ft_strnew(len);
	if (!ans)
		return (NULL);
	while (len)
	{
		ans[i] = s[start];
		i++;
		start++;
		len--;
	}
	return (ans);
}
