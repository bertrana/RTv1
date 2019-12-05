/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjohns <yjohns@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 04:14:49 by yjohns            #+#    #+#             */
/*   Updated: 2019/11/06 04:14:49 by yjohns           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char			*ans;
	unsigned int	i;
	size_t			j;

	if (!s)
		return (NULL);
	i = 0;
	j = ft_strlen(s) - 1;
	while (ft_isspace(s[i]))
		i++;
	while (j > i && (ft_isspace(s[j])))
		j--;
	ans = ft_strsub(s, i, j - i + 1);
	return (ans);
}
