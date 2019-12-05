/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjohns <yjohns@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 04:12:30 by yjohns            #+#    #+#             */
/*   Updated: 2019/11/06 04:12:30 by yjohns           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	unsigned int i;

	if (n < 0)
	{
		ft_putchar('-');
		i = (unsigned int)-n;
	}
	else
		i = (unsigned int)n;
	if (i > 9)
		ft_putnbr(i / 10);
	ft_putchar(i % 10 + '0');
}
