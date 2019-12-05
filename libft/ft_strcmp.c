/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjohns <yjohns@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 04:13:06 by yjohns            #+#    #+#             */
/*   Updated: 2019/11/06 04:13:06 by yjohns           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(const char *str1, const char *str2)
{
	int i;

	i = -1;
	while (str1[++i] && str1[i] == str2[i])
		;
	return ((unsigned char)str1[i] - (unsigned char)str2[i]);
}
