/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_pointers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 12:21:36 by yiwong            #+#    #+#             */
/*   Updated: 2023/05/08 12:58:37 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_me42.h"
#include <stdio.h>

void	free_pointer(char *str)
{
	if (str)
	{
		free(str);
		str = NULL;
	}
	return ;
}

void	free_ppointer(char **str)
{
	int	i;

	i = 0;
	if (str)
	{
		while (str[i])
			free_pointer(str[i++]);
		free(str);
		str = NULL;
	}
	return ;
}
