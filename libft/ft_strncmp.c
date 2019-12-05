/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjohns <yjohns@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 04:14:12 by yjohns            #+#    #+#             */
/*   Updated: 2019/11/06 04:14:12 by yjohns           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_strncmp(const char *str1, const char *str2, size_t num)
{
	int	i;

	i = -1;
	if (!num)
		return (0);
	num--;
	while (str1[++i] && str1[i] == str2[i] && num)
		num--;
	return ((unsigned char)str1[i] - (unsigned char)str2[i]);
}
