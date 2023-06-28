/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_invalid_character_bonus.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 16:03:17 by yiwong            #+#    #+#             */
/*   Updated: 2023/06/27 16:03:17 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../dep/so_long.h"

int	is_character_valid(char c);

int	check_invalid_characters(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (is_character_valid(map[i][j]))
				return (INVALID_CHAR);
			j++;
		}
		i++;
	}
	return (OK);
}

int	is_character_valid(char c)
{
	const char	set[] = {'P', 'C', 'E', '1', '0', 'H', 'h', 'V', 'v', '\n', 0};
	int			i;

	i = 0;
	while (set[i] && set[i] != c)
		i++;
	if (set[i] == c)
		return (OK);
	return (FAIL);
}
