/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjohns <yjohns@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 04:11:14 by yjohns            #+#    #+#             */
/*   Updated: 2019/11/06 04:11:14 by yjohns           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*ans;
	void	*copy;

	if (!(ans = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	ans->next = NULL;
	if (!content)
	{
		ans->content = NULL;
		ans->content_size = 0;
		return (ans);
	}
	if (!(copy = ft_memalloc(content_size)))
	{
		free(ans);
		return (NULL);
	}
	ans->content = ft_memcpy(copy, content, content_size);
	ans->content_size = content_size;
	return (ans);
}
