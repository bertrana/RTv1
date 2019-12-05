/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjohns <yjohns@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 04:14:36 by yjohns            #+#    #+#             */
/*   Updated: 2019/11/06 04:14:36 by yjohns           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>

static unsigned int	count_words(const char *s, char c)
{
	unsigned int ans;
	unsigned int in;
	unsigned int i;

	in = 0;
	ans = 0;
	i = 0;
	while (s[i])
	{
		if (in && s[i] == c)
			in = 0;
		if (!in && s[i] != c)
		{
			in = 1;
			ans++;
		}
		i++;
	}
	return (ans);
}

static unsigned int	len_word(char *s, char c)
{
	int	ans;

	ans = 0;
	while (*s && *s != c)
	{
		ans++;
		s++;
	}
	return (ans);
}

static char			**erase(char **arr, int i)
{
	while (i > 0)
	{
		free(arr[i]);
		i--;
	}
	free(arr);
	return (NULL);
}

char				**ft_strsplit(const char *s, char c)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	count;
	char			**ans;

	if (!s)
		return (NULL);
	count = count_words(s, c);
	if (!(ans = (char **)malloc(count * sizeof(char *) + 1)))
		return (NULL);
	i = 0;
	j = 0;
	while (i < count)
	{
		while (s[j] == c && s[j])
			j++;
		if (!(ans[i] = ft_strsub(s + j, 0, len_word((char *)(s + j), c))))
			return (erase(ans, i));
		j += len_word((char *)(s + j), c);
		i++;
	}
	ans[i] = NULL;
	return (ans);
}
