/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 18:52:36 by yiwong            #+#    #+#             */
/*   Updated: 2023/06/10 18:49:16 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../dep/so_long.h"

char	*remove_whitespace(char *line);

char	**read_map(int fd)
{
	char	*line;
	char	**map;
	int		i;

	line = get_next_line(fd);
	if (!line)
		return (NULL);
	i = 0;
	map = (char **)malloc(sizeof(char *) * 10);
	while (line)
	{
		map[i] = remove_whitespace(line);
		free_pointer(line);
		line = get_next_line(fd);
		i++;
	}
	map[i] = NULL;
	return (map);
}

char	*remove_whitespace(char *line)
{
	char	*return_line;
	int		i;
	int		j;
	int		count;

	i = 0;
	count = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\n')
			count++;
		i++;
	}
	return_line = (char *)malloc(sizeof(char) * (count + 1));
	i = 0;
	j = 0;
	while (j < count && line[i])
	{
		if (line[i] != ' ' && line[i] != '\n')
			return_line[j++] = line[i];
		i++;
	}
	return_line[j] = '\0';
	return (return_line);
}
