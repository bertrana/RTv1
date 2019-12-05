/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjohns <yjohns@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 04:14:01 by yjohns            #+#    #+#             */
/*   Updated: 2019/11/06 04:14:01 by yjohns           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	unsigned int	i;
	char			*ans;

	if (!s || !f)
		return (NULL);
	ans = ft_strnew(ft_strlen(s));
	if (!ans)
		return (NULL);
	i = 0;
	while (s[i])
	{
		ans[i] = f(s[i]);
		i++;
	}
	return (ans);
}
