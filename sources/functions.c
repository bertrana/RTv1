/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjohns <yjohns@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 04:20:08 by yjohns            #+#    #+#             */
/*   Updated: 2019/11/06 04:20:08 by yjohns           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv.h"

int			err_exit(char *str)
{
	ft_putendl(str);
	exit(0);
}

t_vector	vector_parse(char *str)
{
	char		**nums;
	t_vector	ans;

	ans = vector_new(0, 0, 0);
	nums = ft_strsplit(str, ',');
	if (!nums[0] || !nums[1] || !nums[2])
		err_exit("no 3 parts of vector");
	ans = vector_new(ft_atoi(nums[0]),
			ft_atoi(nums[1]), ft_atoi(nums[2]));
	free_arr(nums);
	return (ans);
}

void		free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

int			parse_color_from_hex(char *str)
{
	int ans;
	int i;

	i = 0;
	ans = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			ans = ans * 16 + (str[i] - '0');
		else
		{
			if (str[i] >= 'a' && str[i] <= 'f')
				ans = ans * 16 + (str[i] - 'a' + 10);
			else
				return (ans);
		}
		i++;
	}
	return (ans);
}

/*
** type 1 - PLANE: CONE: CYLINDER: SPHERE:
** else 2 - POINT: AMBIENT:
*/

int			check_by_type(char *line, int i)
{
	if (i == 1)
	{
		return (ft_strnstr(line, "PLANE:", 6) != NULL ||
				ft_strnstr(line, "CONE:", 5) != NULL ||
				ft_strnstr(line, "CYLINDER:", 9) != NULL ||
				ft_strnstr(line, "SPHERE:", 7) != NULL);
	}
	return (ft_strnstr(line, "POINT:", 6) != NULL ||
			ft_strnstr(line, "AMBIENT:", 8) != NULL);
}
