/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 18:35:46 by yiwong            #+#    #+#             */
/*   Updated: 2023/07/03 15:43:05 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../dep/so_long_bonus.h"

char	*find_map(char *name);

int	open_map_file(char *name)
{
	int		fd;
	char	*path_to_map;

	path_to_map = find_map(name);
	if (!path_to_map)
		fd = open(name, O_RDONLY, 0666);
	else
	{
		fd = open(path_to_map, O_RDONLY, 0666);
		free_pointer(path_to_map);
	}
	if (fd < 0)
		return (0);
	return (fd);
}

char	*find_map(char *name)
{
	char	*temp;

	if (ft_strnstr(name, ".ber", ft_strlen(name)) || ft_strrchr(name, '/'))
		return (NULL);
	else
	{
		temp = ft_strjoin(name, ".ber");
		name = ft_strjoin("maps/", temp);
		free_pointer(temp);
	}
	return (name);
}
