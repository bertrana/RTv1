/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordcounter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjohns <yjohns@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 04:15:04 by yjohns            #+#    #+#             */
/*   Updated: 2019/11/06 04:15:04 by yjohns           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_wordcounter(char *str, char split)
{
	int words;
	int isword;

	words = 0;
	isword = 0;
	while (*str)
	{
		if (*str != split)
			isword = 1;
		else
		{
			if (isword)
				words++;
			isword = 0;
		}
		str++;
	}
	return (isword ? words + 1 : words);
}
