/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 18:52:36 by yiwong            #+#    #+#             */
/*   Updated: 2023/06/13 17:25:31 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../dep/so_long.h"

int get_map_height(int *fd, char *name);

int	open_map_file(char *name)
{
	int		fd;
	char	*temp;

	temp = ft_strjoin(name, ".ber");
	name = ft_strjoin("maps/", temp);
	free_pointer(temp);
	fd = open(name, O_RDONLY, 0666);
	free_pointer(name);
	if (fd < 0)
		return (0);
	return (fd);
}

char	**read_map(int fd, char *name)
{
	char	*line;
	char	**map;
	int		i;
	int		len;

	line = get_next_line(fd);
	if (!line)
		return (NULL);
	len = ft_strlen(line);
	i = 0;
	map = (char **)malloc(sizeof(char *)
			* (get_map_height(&fd, name) + 1));
	while (line)
	{
		map[i] = (char *)malloc(sizeof(char) * len - 1);
		ft_strlcpy(map[i], line, len);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	map[i] = NULL;
	return (map);
}

int get_map_height(int *fd, char *name)
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
	return (i + 1);
}

////Obsolete////
//char	*remove_whitespace(char *line)
//{
//	char	*return_line;
//	int		i;
//	int		j;
//	int		count;
//
//	i = 0;
//	count = 0;
//	while (line[i])
//	{
//		if (line[i] != ' ' && line[i] != '\n')
//			count++;
//		i++;
//	}
//	return_line = (char *)malloc(sizeof(char) * (count + 1));
//	i = 0;
//	j = 0;
//	while (j < count && line[i])
//	{
//		if (line[i] != ' ' && line[i] != '\n')
//			return_line[j++] = line[i];
//		i++;
//	}
//	return_line[j] = '\0';
//	return (return_line);
//}
//