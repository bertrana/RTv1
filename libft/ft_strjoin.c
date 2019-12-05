/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjohns <yjohns@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 04:13:45 by yjohns            #+#    #+#             */
/*   Updated: 2019/11/06 04:13:45 by yjohns           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *ans;

	if (!s1 || !s2)
		return (NULL);
	ans = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	if (!ans)
		return (NULL);
	ft_strcat(ans, s1);
	ft_strcat(ans, s2);
	return (ans);
}
