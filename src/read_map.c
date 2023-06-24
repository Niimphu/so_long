/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 18:52:36 by yiwong            #+#    #+#             */
/*   Updated: 2023/06/21 18:10:08 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../dep/so_long.h"

char	*find_map(char *name);
int	get_map_height(int *fd, char *name);

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

char	**read_map(int fd, char *name)
{
	char	*line;
	char	**map;
	int		i;

	map = (char **)malloc(sizeof(char *) * (get_map_height(&fd, name) + 1));
	line = get_next_line(fd);
	if (!line)
		return (NULL);
	i = 0;
	while (line)
	{
		map[i] = ft_strtrim(line, "\n");
		free(line);
		line = get_next_line(fd);
		i++;
	}
	map[i] = NULL;
	return (map);
}

int	get_map_height(int *fd, char *name)
{
	int		i;
	char	*line;

	i = 0;
	line = get_next_line(*fd);
	while (line)
	{
		free(line);
		line = get_next_line(*fd);
		i++;
	}
	close(*fd);
	*fd = open_map_file(name);
	return (i);
}
