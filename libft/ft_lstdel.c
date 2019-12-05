/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjohns <yjohns@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 04:10:34 by yjohns            #+#    #+#             */
/*   Updated: 2019/11/06 04:10:34 by yjohns           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*current;
	t_list	*next;

	if (!alst || !del || !*alst)
		return ;
	current = *alst;
	while (current)
	{
		next = current->next;
		ft_lstdelone(&current, del);
		current = next;
	}
	*alst = NULL;
}
